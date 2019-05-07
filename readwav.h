#ifndef READWAV_H
#define READWAV_H

#include <sstream>
#include <string>
#include <stdio.h>
//#include "error.h"
using namespace std;

/// data structure of the file.
struct WavRiff {
    char Riff[4];
    uint32_t lenAll;
    char Wave[4];
};

struct WavFormat{
    char fmtSign[4];
    uint32_t lenFormat;
    uint16_t type;
    uint16_t ChannelNum;
    uint32_t SampleRate;
    uint32_t ByteRate;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
};

struct WavFact {
    char factSign[4];
    uint32_t lenFact;
    uint32_t factSamplelen;
};

struct WavData{
    char dataSign[4];
    uint32_t lenData;
};



class WavInFile
{

private:

    FILE *fptr;

    /// Counter of how many bytes of sample data have been read from the file.
    long dataRead;

    ///position winthin the audio stream.
    long position;

    ///check whether we can edit this file.
    void init();

    ///read the header block of the file.
    int readHeader();

    ///CHECK the start of the file.
    int readRIFF();

    /// check the format of the file.
    /// if format is right, return 0; otherwise, return 1.
    int checkFormat();

    ///check the parameter of the file
    int checkParameter();


public:
    WavRiff riff;
    WavFormat format;
    WavFact fact;
    WavData data;
    uint getSampleRate() const;
    uint getBitsPerSample() const;
    uint getlenS3InBytes()const;
    uint getNumSamples() const;
    uint getBytesPerSample() const;
    uint getChannels() const;
    uint getLengthInMS() const;
    uint getElapsedMS() const;
    uint getByteRate() const;

    int read(float *buffer, int maxElam);



    /// constructor: open the given file, and initialize it.
    WavInFile(const char *filename);

    /// destructor: close the file
    ~WavInFile();

    /// Rewind to beginning of the file
    void rewind();

    /// Check end-of-file.
    int eof();


};


class WavOutFile
{
private:
    /// Pointer to the WAV file
    FILE *fptr;

    /// WAV file header data.
    WavRiff riff;
    WavFormat format;
    WavFact fact;
    WavData data;

    /// Counter of how many bytes have been written to the file so far.
    int bytesWritten;

    /// help to write the data into float format
    int saturate(float fvalue, float minval, float maxval);


    /// Fills in WAV file header information.
    void writeBaseHeader(const uint sampleRate, const uint bits, const uint channels);

    /// Finishes the WAV file header after we get the length of data.
    void finishHeader();




public:
    /// Constructor: Creates a new WAV file. Throws a 'runtime_error' exception
    /// if file creation fails.
    WavOutFile(const char *fileName,    ///< Filename
               int sampleRate,          ///< Sample rate (e.g. 44100 etc)
               int bits,                ///< Bits per sample (8 or 16 bits)
               int channels             ///< Number of channels (1=mono, 2=stereo)
               );

    WavOutFile(FILE *file, int sampleRate, int bits, int channels);

    /// Destructor: Finalizes & closes the WAV file.
    ~WavOutFile();


    /// Write data to WAV file in floating point format, saturating sample values to range
    /// [-1..+1[. Throws a 'runtime_error' exception if writing to file fails.
    void write(const float *buffer,     ///< Pointer to sample data buffer.
               int numElems             ///< How many array items are to be written to file.
               );
};



#endif // READWAV_H
