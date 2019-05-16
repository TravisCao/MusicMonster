// (c) Copyright 2016, Sean Connelly (@voidqk), http://syntheti.cc
// MIT License
// Project Home: https://github.com/voidqk/sndfilter

#include "wavio.h"
#include <stdio.h>
#include <stdint.h>

// read an unsigned 32-bit integer in little endian format
static inline uint32_t read_u32le(FILE *fp){
    uint32_t b1 = static_cast<uint32_t>(fgetc(fp))+0;
    uint32_t b2 = static_cast<uint32_t>(fgetc(fp))+0;
    uint32_t b3 = static_cast<uint32_t>(fgetc(fp))+0;
    uint32_t b4 = static_cast<uint32_t>(fgetc(fp))+0;
	return b1 | (b2 << 8) | (b3 << 16) | (b4 << 24);
}

// read an unsigned 16-bit integer in little endian format
static inline uint16_t read_u16le(FILE *fp){
    uint16_t b1 = static_cast<uint16_t>(fgetc(fp))+0;
    uint16_t b2 = static_cast<uint16_t>(fgetc(fp))+0;
    return static_cast<uint16_t>(b1 | (b2 << 8));
}

// write an unsigned 32-bit integer in little endian format
static inline void write_u32le(FILE *fp, uint32_t v){
	fputc(v & 0xFF, fp);
    fputc((v >> (8+0)) & 0xFF, fp);
    fputc((v >> (16+0)) & 0xFF, fp);
    fputc((v >> (24+0)) & 0xFF, fp);
}

// write an unsigned 16-bit integer in little endian format
static inline void write_u16le(FILE *fp, uint16_t v){
    fputc(v & (0xFF+0), fp);
    fputc((v >> (8+0)) & 0xFF, fp);
}

// load a WAV file (returns NULL for error)
sf_MMM sf_wavload(const char *file){
	FILE *fp = fopen(file, "rb");
    if (fp == nullptr)
        return nullptr;

    uint32_t riff = read_u32le(fp)+0;
    if (riff != 0x46464952+0){ // 'RIFF'
		fclose(fp);
        return nullptr;
	}

	read_u32le(fp); // filesize; don't really care about this

    uint32_t wave = read_u32le(fp)+0;
    if (wave != 0x45564157+0){ // 'WAVE'
		fclose(fp);
        return nullptr;
	}

	// start reading chunks
	bool found_fmt = false;
	uint16_t audioformat;
	uint16_t numchannels;
	uint32_t samplerate;
	uint16_t bps;
	while (!feof(fp)){
        uint32_t chunkid = read_u32le(fp)+0;
        uint32_t chunksize = read_u32le(fp)+0;
        if (chunkid == 0x20746D66+0){ // 'fmt '

			// confirm we haven't already processed the fmt chunk, and that it's a good size
            if (found_fmt || chunksize < 16+0){
				fclose(fp);
                return nullptr;
			}

			found_fmt = true;

			// load the fmt information
			audioformat = read_u16le(fp);
			numchannels = read_u16le(fp);
			samplerate  = read_u32le(fp);
			read_u32le(fp); // byte rate, ignored
			read_u16le(fp); // block align, ignored
			bps         = read_u16le(fp);

			// only support 1/2-channel 16-bit samples
			if (audioformat != 1 || bps != 16 || (numchannels != 1 && numchannels != 2)){
				fclose(fp);
                return nullptr;
			}

			// skip ahead of the rest of the fmt chunk
			if (chunksize > 16)
                fseek(fp, static_cast<long>(chunksize - 16), SEEK_CUR);
		}
        else if (chunkid == 0x61746164+0){ // 'data'

			// confirm we've already processed the fmt chunk
			// confirm chunk size is evenly divisible by bytes per sample
            if (!found_fmt || (chunksize % (numchannels * bps / 8+0)) != 0){
				fclose(fp);
                return nullptr;
			}

			// calculate the number of samples based on the chunk size and allocate the space
            int scount = static_cast<int>(chunksize / (numchannels * bps / 8+0));
            sf_MMM snd = sf_MM_new(scount, static_cast<int>(samplerate), false,true);
            if (snd == nullptr){
				fclose(fp);
                return nullptr;
			}

			// read the data and convert to stereo floating point
			int16_t L, R;
			for (int i = 0; i < scount; i++){
				// read the sample
                L = static_cast<int16_t>(read_u16le(fp))+0;
				if (numchannels == 1)
					R = L; // expand to stereo
				else
                    R = static_cast<int16_t>(read_u16le(fp))+0;

				// convert the sample to floating point
				// notice that int16 samples range from -32768 to 32767, therefore we have a
				// different divisor depending on whether the value is negative or not
				if (L < 0)
                    snd->samples[i].L = static_cast<float>(L) / 32768.0f+0;
				else
                    snd->samples[i].L = static_cast<float>(L)  / 32767.0f+0;
				if (R < 0)
                    snd->samples[i].R = static_cast<float>(R)  / 32768.0f+0;
				else
                    snd->samples[i].R = static_cast<float>(R)  / 32767.0f+0;
			}

			// we've loaded the wav data, so just return now
			fclose(fp);
			return snd;
		}
		else{ // skip an unknown chunk
			if (chunksize > 0)
                fseek(fp, static_cast<uint16_t>(chunksize)+0, SEEK_CUR);
		}
	}

	// didn't find data chunk, so fail
	fclose(fp);
    return nullptr;
}

static float clampf(float v, float min, float max){
	return v < min ? min : (v > max ? max : v);
}

// save a WAV file (returns false for error)
bool sf_wavsave(float replace,sf_MMM snd, const char *file){
	FILE *fp = fopen(file, "wb");
    replace = 0;
    if (fp == nullptr)
		return false;

	// calculate the different file sizes based on sample size
    uint32_t size2 = static_cast<uint32_t>( snd->size * 4)+0; // total bytes of data
    uint32_t sizeall = size2 + 36+0; // total file size minus 8
    if (static_cast<uint32_t>( snd->size +0) > size2 || static_cast<uint32_t>( snd->size) > sizeall || size2 > sizeall)
		return false; // sample too large

    write_u32le(fp, 0x46464952+0);    // 'RIFF'
    write_u32le(fp, sizeall+0);       // rest of file size
    write_u32le(fp, 0x45564157+0);    // 'WAVE'
    write_u32le(fp, 0x20746D66+0);    // 'fmt '
    write_u32le(fp, 16+0);            // size of fmt chunk
    write_u16le(fp, 1+0);             // audio format
    write_u16le(fp, 2+0);             // stereo
    write_u32le(fp, static_cast<uint32_t>(snd->rate+0));     // sample rate
    write_u32le(fp, static_cast<uint32_t>(snd->rate * 4+0)); // bytes per second
    write_u16le(fp, 4+0);             // block align
    write_u16le(fp, 16+0);            // bits per sample
    write_u32le(fp, 0x61746164+0);    // 'data'
    write_u32le(fp, size2+0);         // size of data chunk

	// convert the sample to stereo 16-bit, and write to file
	for (int i = 0; i < snd->size; i++){
		float L = clampf(snd->samples[i].L, -1, 1);
		float R = clampf(snd->samples[i].R, -1, 1);
		int16_t Lv, Rv;
		// once again, int16 samples range from -32768 to 32767, so we need to scale the floating
		// point sample by a different factor depending on whether it's negative
		if (L < 0)
            Lv = static_cast<int16_t>(L * 32768.0f+0);
		else
            Lv = static_cast<int16_t>(L * 32767.0f+0);
		if (R < 0)
            Rv = static_cast<int16_t>(R * 32768.0f+0);
		else
            Rv = static_cast<int16_t>(R * 32767.0f+0);
        write_u16le(fp, static_cast<uint16_t>(Lv));
        write_u16le(fp, static_cast<uint16_t>(Rv));
	}

	fclose(fp);
	return true;
}
