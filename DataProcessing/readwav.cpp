#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "readwav.h"
using namespace std;

static const char riffStr[] = "RIFF";
static const char waveStr[] = "WAVE";
static const char fmtStr[]  = "fmt ";
static const char factStr[] = "fact";
static const char dataStr[] = "data";

WavInFile::WavInFile(const char *fileName) {

    fptr = fopen(fileName, "rb");
    if (fptr == NULL)
    {
        checkFlag = 1;
    }
    init();
}

WavInFile::~WavInFile() {
    if (fptr) fclose(fptr);
    fptr = NULL;
}

//如果文件格式不对，就终止程序

void WavInFile::init() {
    int checkF;
    checkF = checkFormat();
    int checkP;
    checkP = checkParameter();
    if ((checkF != 0) || (checkP != 0)) {
        checkFlag = 1;
    }
}

//check the format of the wav file by checking the RIFF, fmt and data sign and checking the other signs.
//if the format is not right, return 1, if the format is right, return 0.
int WavInFile::checkFormat() {
    int test;
    test = readRIFF();
    if (test != 0) return -1;
    // read header blocks until data block is found
    do
    {
        test = readHeader();
        if (test < 0) return -1;  // error in file structure
    } while (test == 0);

    return 0;
}

int WavInFile::readRIFF() {
    if (fread(&(riff.Riff), sizeof(riff.Riff), 1, fptr) != 1) return -1;
    if (fread(&(riff.lenAll), sizeof(riff.lenAll), 1, fptr) != 1) return -1;
    if (fread(&(riff.Wave), sizeof(riff.Wave), 1, fptr) != 1) return -1;

    if (memcmp(riffStr, riff.Riff, 4) != 0) return -1;
    if (memcmp(waveStr, riff.Wave, 4) != 0) return -1;

    return 0;
}

int WavInFile::readHeader() {
    char label[5];
    if (fread(label, 1, 4, fptr) != 4) return -1;
    //cout << label;
    label[4] = 0;

    //'format' block
    if (strcmp(label, fmtStr) == 0)
    {
        int nLen, nDiffer;

        //store the format sign in the fmtSign.
        memcpy(format.fmtSign, fmtStr, 4);

        // read length of the format field
        if (fread(&nLen, sizeof(int), 1, fptr) != 1) return -1;

        // check if the length of the format field is right.
        nDiffer = nLen - (static_cast<int>(sizeof(format)) - 8);
        if ((nLen < 0) || (nDiffer < 0)) return -1;

        format.lenFormat = nLen;

        // read data
        if (fread(&(format.type), sizeof(uint16_t), 1, fptr) != 1) return -1;
        if (fread(&(format.ChannelNum), sizeof(uint16_t), 1, fptr) != 1) return -1;
        if (fread(&(format.SampleRate), sizeof(uint32_t), 1, fptr) != 1) return -1;
        if (fread(&(format.ByteRate), sizeof(uint32_t), 1, fptr) != 1) return -1;
        if (fread(&(format.BlockAlign), sizeof(uint16_t), 1, fptr) != 1) return -1;
        if (fread(&(format.BitsPerSample), sizeof(uint16_t), 1, fptr) != 1) return -1;


        // if format_len is larger than expected, skip the extra data
        if (nDiffer > 0)
        {
            fseek(fptr, nDiffer, SEEK_CUR);
        }

        return 0;
    }

    // 'fact' block
    else if (strcmp(label, factStr) == 0)
    {
        int nLen, nDiffer;

        memcpy(fact.factSign, factStr, 4);

        // read length of the fact field
        if (fread(&nLen, sizeof(uint32_t), 1, fptr) != 1) return -1;


        // check the length of fact field is right.
        nDiffer = nLen - (static_cast<int>(sizeof(fact)) - 8);
        if ((nLen < 0) || (nDiffer < 0)) return -1;

        fact.lenFact = nLen;

        // read data
        if (fread(&(fact.factSamplelen), sizeof(uint32_t), 1, fptr) != 1) return -1;


        if (nDiffer > 0)
        {
            fseek(fptr, nDiffer, SEEK_CUR);// skip the extra data
        }


        return 0;
    }

    // data block
    else if (strcmp(label, dataStr) == 0)
    {
        memcpy(data.dataSign, dataStr, 4);
        if (fread(&(data.lenData), sizeof(uint), 1, fptr) != 1) return -1;

        return 1;
    }

    // unknown block
    else
    {
        uint32_t len, i, temp;
        // read length
        if (fread(&len, sizeof(len), 1, fptr) != 1) return -1;
        // scan through the block
        for (i = 0; i < len; i ++)
        {
            if (fread(&temp, 1, 1, fptr) != 1) return -1;
            if (feof(fptr)) return -1;   // unexpected eof
        }
    }
    return 0;
}


int WavInFile::checkParameter() {
    if ((format.ChannelNum < 1)  || (format.ChannelNum > 9) ||
            (format.SampleRate < 4000)  || (format.SampleRate > 192000) ||
            (format.BlockAlign < 1) || (format.BlockAlign > 320) ||
            (format.BitsPerSample < 8) || (format.BitsPerSample > 32)) {
        return -1;
    }
    return 0;
}

// return to the start of the file.
void WavInFile::rewind() {
    fseek(fptr, 0, SEEK_SET);
}


// if reach the end of file, return 1; otherwise,return 0.
int WavInFile::eof() {
     return (dataRead == riff.lenAll || feof(fptr));
}

uint WavInFile::getSampleRate() const
{
    return format.SampleRate;
}

uint WavInFile::getBitsPerSample() const
{
    return format.BitsPerSample;
}

// get the sizes of the data in bytes.
uint WavInFile::getlenS3InBytes() const
{
    return data.lenData;
}

uint WavInFile::getNumSamples() const
{
    if (format.BlockAlign == 0) return 0;
    if (format.type > 1) return fact.factSamplelen;
    return data.lenData / static_cast<uint16_t>(format.BlockAlign);
}

uint WavInFile::getBytesPerSample() const
{
    return getChannels() * getBitsPerSample() / 8;
}

uint WavInFile::getByteRate() const
{
    return format.ByteRate;
}

uint WavInFile::getChannels() const
{
    return format.ChannelNum;
}

uint WavInFile::getLengthInMS() const
{
    double numSamples;
    double sampleRate;

    numSamples = static_cast<double>(getNumSamples());
    sampleRate = static_cast<double>(getSampleRate());

    return static_cast<uint>(1000.0 * numSamples / sampleRate + 0.5);
}

/// Returns how many milliseconds of audio have so far been read from the file
uint WavInFile::getElapsedMS() const
{
    return static_cast<uint>(1000.0 * static_cast<double>(dataRead) / static_cast<double>(format.ByteRate));
}

/*----------------------------------------------------------------------------------------------------------
 * ---------------------------------------------------------------------------------------------------------
 */

/// Read data in float format. Notice that when reading in float format
/// 8/16/24/32 bit sample formats are supported
//int WavInFile::read(float *buffer, int maxElems)
//{
//    unsigned int afterDataRead;
//    int numBytes;
//    int numElems;
//    int bytesPerSample;

//    //assert(buffer);

//    bytesPerSample = format.BitsPerSample / 8;
//    if ((bytesPerSample < 1) || (bytesPerSample > 4))
//    {
//        stringstream ss;
//        ss << "\nOnly 8/16/24/32 bit sample WAV files supported. Can't open WAV file with ";
//        ss << static_cast<int>(format.BitsPerSample);
//        ss << " bit sample format. ";
//        //error(ss.str().c_str());
//    }

//    numBytes = maxElems * bytesPerSample;
//    afterDataRead = dataRead + numBytes;
//    if (afterDataRead > data.lenData)
//    {
//        // Don't read more samples than are marked available in header
//        numBytes = (int)data.lenData - (int)dataRead;
//        assert(numBytes >= 0);
//    }

//    // read raw data into temporary buffer
//    char *temp = (char*)getConvBuffer(numBytes);
//    numBytes = static_cast<int>(fread(temp, 1, numBytes, fptr));
//    dataRead += numBytes;

//    numElems = numBytes / bytesPerSample;

//    // swap byte ordert & convert to float, depending on sample format
//    switch (bytesPerSample)
//    {
//        case 1:
//        {
//            unsigned char *temp2 = (unsigned char*)temp;
//            double conv = 1.0 / 128.0;
//            for (int i = 0; i < numElems; i ++)
//            {
//                buffer[i] = (float)(temp2[i] * conv - 1.0);
//            }
//            break;
//        }

//        case 2:
//        {
//            short *temp2 = (short*)temp;
//            double conv = 1.0 / 32768.0;
//            for (int i = 0; i < numElems; i ++)
//            {
//                short value = temp2[i];
//                buffer[i] = (float)(value * conv);
//            }
//            break;
//        }

//        case 3:
//        {
//            char *temp2 = (char *)temp;
//            double conv = 1.0 / 8388608.0;
//            for (int i = 0; i < numElems; i ++)
//            {
//                int value = *((int*)temp2);
//                value = value & 0x00ffffff;             // take 24 bits
//                value |= (value & 0x00800000) ? 0xff000000 : 0;  // extend minus sign bits
//                buffer[i] = (float)(value * conv);
//                temp2 += 3;
//            }
//            break;
//        }

//        case 4:
//        {
//            int *temp2 = (int *)temp;
//            double conv = 1.0 / 2147483648.0;
//            assert(sizeof(int) == 4);
//            for (int i = 0; i < numElems; i ++)
//            {
//                int value = temp2[i];
//                buffer[i] = (float)(value * conv);
//            }
//            break;
//        }
//    }

//    return numElems;
//}





/*
 * --------------------------------------------------------------------------------------------------
 * --------------------------------------------------------------------------------------------------
 * --------------------------------------------------------------------------------------------------
 */

WavOutFile::WavOutFile(const char *fileName, int sampleRate, int bits, int channels)
{
    bytesWritten = 0;
    fptr = fopen(fileName, "wb");
    if (fptr == NULL)
    {
        string msg = "Error : Unable to open file \"";
        msg += fileName;
        msg += "\" for writing.";
        //pmsg = msg.c_str;
        //error(msg.c_str());
    }

    writeBaseHeader(sampleRate, bits, channels);

}

WavOutFile::~WavOutFile()
{
    finishHeader();
    if (fptr) fclose(fptr);
    fptr = NULL;
}


void WavOutFile::writeBaseHeader(const uint sampleRate, const uint bits, const uint channels)
{
    memcpy(&(riff.Riff), riffStr, 4);
    // length of whole file unknown
    // copy string 'WAVE' to wave
    memcpy(&(riff.Wave), waveStr, 4);

    // fill in the 'format' part..
    memcpy(&(format.fmtSign), fmtStr, 4);
    format.lenFormat = 0x10;
    format.type = 1;
    format.ChannelNum = static_cast<uint16_t>(channels);
    format.SampleRate = static_cast<uint32_t>(sampleRate);
    format.BitsPerSample = static_cast<uint16_t>(bits);
    format.BlockAlign = static_cast<uint16_t>(bits * channels / 8); //byte per sample???
    format.ByteRate = format.BlockAlign * static_cast<uint32_t>(sampleRate);

    // fill in the 'fact' part...
    memcpy(&(fact.factSign), factStr, 4);
    fact.lenFact = 4;
    //fact sample length unknown

    // fill in the 'data' part..

    // copy string 'data' to data_field
    memcpy(&(data.dataSign), dataStr, 4);
    // data length unknown
}

void WavOutFile::finishHeader()
{
    // supplement the length of whole file, data length and fact sample length in the header.
    riff.lenAll = static_cast<uint32_t>(bytesWritten) + sizeof(WavFormat) + sizeof(WavFact) + sizeof(WavData) + 4;
    data.lenData = static_cast<uint32_t>(bytesWritten);
    fact.factSamplelen = static_cast<uint32_t>(bytesWritten) / format.BlockAlign;
}

int WavOutFile::saturate(float fvalue, float minval, float maxval)
{
    if (fvalue > maxval)
    {
        fvalue = maxval;
    }
    else if (fvalue < minval)
    {
        fvalue = minval;
    }
    return (int)fvalue;
}


//void WavOutFile::write(const float *buffer, int numElems)
//{
//    int numBytes;
//    int bytesPerSample;

//    if (numElems == 0) return;

//    bytesPerSample = format.BitsPerSample / 8;
//    numBytes = numElems * bytesPerSample;
//    void *temp = getConvBuffer(numBytes + 7);   // round bit up to avoid buffer overrun with 24bit-value assignment

//    switch (bytesPerSample)
//    {
//        case 1:
//        {
//            unsigned char *temp2 = (unsigned char *)temp;
//            for (int i = 0; i < numElems; i ++)
//            {
//                temp2[i] = (unsigned char)saturate(buffer[i] * 128.0f + 128.0f, 0.0f, 255.0f);
//            }
//            break;
//        }

//        case 2:
//        {
//            short *temp2 = (short *)temp;
//            for (int i = 0; i < numElems; i ++)
//            {
//                short value = (short)saturate(buffer[i] * 32768.0f, -32768.0f, 32767.0f);
//                temp2[i] = value;
//            }
//            break;
//        }

//        case 3:
//        {
//            char *temp2 = (char *)temp;
//            for (int i = 0; i < numElems; i ++)
//            {
//                int value = saturate(buffer[i] * 8388608.0f, -8388608.0f, 8388607.0f);
//                *((int*)temp2) = value;
//                temp2 += 3;
//            }
//            break;
//        }

//        case 4:
//        {
//            int *temp2 = (int *)temp;
//            for (int i = 0; i < numElems; i ++)
//            {
//                int value = saturate(buffer[i] * 2147483648.0f, -2147483648.0f, 2147483647.0f);
//                temp2[i] = value;
//            }
//            break;
//        }

//    }

//    int res = (int)fwrite(temp, 1, numBytes, fptr);

//    if (res != numBytes)
//    {
//        error("Error while writing to a wav file.");
//    }
//    bytesWritten += numBytes;
//}








