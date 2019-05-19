#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "readwav.h"
#include "assert.h"
using namespace std;

static const char riffStr[] = "RIFF";
static const char waveStr[] = "WAVE";
static const char fmtStr[]  = "fmt ";
static const char factStr[] = "fact";
static const char dataStr[] = "data";

WavInFile::WavInFile(const char *fileName) {

 dataRead = 0;
 position = 0;

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
    if (fread(&(buffer.riff.Riff), sizeof(buffer.riff.Riff), 1, fptr) != 1) return -1;
    if (fread(&(buffer.riff.lenAll), sizeof(buffer.riff.lenAll), 1, fptr) != 1) return -1;
    if (fread(&(buffer.riff.Wave), sizeof(buffer.riff.Wave), 1, fptr) != 1) return -1;

    if (memcmp(riffStr, buffer.riff.Riff, 4) != 0) return -1;
    if (memcmp(waveStr, buffer.riff.Wave, 4) != 0) return -1;

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
        memcpy(buffer.format.fmtSign, fmtStr, 4);

        // read length of the format field
        if (fread(&nLen, sizeof(int), 1, fptr) != 1) return -1;

        // check if the length of the format field is right.
        nDiffer = nLen - (static_cast<int>(sizeof(buffer.format)) - 8);
        if ((nLen < 0) || (nDiffer < 0)) return -1;

        buffer.format.lenFormat = nLen;

        // read data
        if (fread(&(buffer.format.type), sizeof(uint16_t), 1, fptr) != 1) return -1;
        if (fread(&(buffer.format.ChannelNum), sizeof(uint16_t), 1, fptr) != 1) return -1;
        if (fread(&(buffer.format.SampleRate), sizeof(uint32_t), 1, fptr) != 1) return -1;
        if (fread(&(buffer.format.ByteRate), sizeof(uint32_t), 1, fptr) != 1) return -1;
        if (fread(&(buffer.format.BlockAlign), sizeof(uint16_t), 1, fptr) != 1) return -1;
        if (fread(&(buffer.format.BitsPerSample), sizeof(uint16_t), 1, fptr) != 1) return -1;


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

        memcpy(buffer.fact.factSign, factStr, 4);

        // read length of the fact field
        if (fread(&nLen, sizeof(uint32_t), 1, fptr) != 1) return -1;


        // check the length of fact field is right.
        nDiffer = nLen - (static_cast<int>(sizeof(buffer.fact)) - 8);
        if ((nLen < 0) || (nDiffer < 0)) return -1;

        buffer.fact.lenFact = nLen;

        // read data
        if (fread(&(buffer.fact.factSamplelen), sizeof(uint32_t), 1, fptr) != 1) return -1;


        if (nDiffer > 0)
        {
            fseek(fptr, nDiffer, SEEK_CUR);// skip the extra data
        }


        return 0;
    }

    // data block
    else if (strcmp(label, dataStr) == 0)
    {
        memcpy(buffer.data.dataSign, dataStr, 4);
        if (fread(&(buffer.data.lenData), sizeof(uint), 1, fptr) != 1) return -1;

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
    if ((buffer.format.ChannelNum < 1)  || (buffer.format.ChannelNum > 9) ||
            (buffer.format.SampleRate < 4000)  || (buffer.format.SampleRate > 192000) ||
            (buffer.format.BlockAlign < 1) || (buffer.format.BlockAlign > 320) ||
            (buffer.format.BitsPerSample < 8) || (buffer.format.BitsPerSample > 32)) {
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
     return (dataRead == buffer.riff.lenAll || feof(fptr));
}

uint WavInFile::getSampleRate() const
{
    return buffer.format.SampleRate;
}

uint WavInFile::getBitsPerSample() const
{
    return buffer.format.BitsPerSample;
}

// get the sizes of the data in bytes.
uint WavInFile::getlenS3InBytes() const
{
    return buffer.data.lenData;
}

uint WavInFile::getNumSamples() const
{
    if (buffer.format.BlockAlign == 0) return 0;
    if (buffer.format.type > 1) return buffer.fact.factSamplelen;
    return buffer.data.lenData / static_cast<uint16_t>(buffer.format.BlockAlign);
}

uint WavInFile::getBytesPerSample() const
{
    return getChannels() * getBitsPerSample() / 8;
}

uint WavInFile::getByteRate() const
{
    return buffer.format.ByteRate;
}

uint WavInFile::getChannels() const
{
    return buffer.format.ChannelNum;
}

string WavInFile::getLengthInMS() const
{
    uint timeInMS, ms;
    string s, min, h;
    string time;
    double numSamples;
    double sampleRate;

    numSamples = static_cast<double>(getNumSamples());
    sampleRate = static_cast<double>(getSampleRate());
    timeInMS = static_cast<uint>(1000.0 * numSamples / sampleRate + 0.5);
    ms = timeInMS%1000;
    timeInMS = timeInMS/1000;
    if (timeInMS%1000 < 10) {
        s = "0"+to_string(timeInMS%1000);
    }
    timeInMS = timeInMS/1000;
    if (timeInMS%1000 < 10) {
        min = "0"+to_string(timeInMS%1000);
    }
    timeInMS = timeInMS/1000;
    if (timeInMS%1000 < 10) {
        h = "0"+to_string(timeInMS%1000);
    }
    time = h+":"+min+":"+s;
    return time;
}

/// Returns how many milliseconds of audio have so far been read from the file
uint WavInFile::getElapsedMS() const
{
    return static_cast<uint>(1000.0 * static_cast<double>(dataRead) / static_cast<double>(buffer.format.ByteRate));
}

/*----------------------------------------------------------------------------------------------------------
 * ---------------------------------------------------------------------------------------------------------
 */

// Read data in float format. Notice that when reading in float format
// 8/16/24/32 bit sample formats are supported
int WavInFile::read()
{
    unsigned int afterDataRead;
    int maxElems = buffer.getDataNum();
    int numBytes;
    int numElems;
    int bytesPerSample;

    buffer.initializeData();
    bytesPerSample = buffer.format.BitsPerSample / 8;

    if ((bytesPerSample < 1) || (bytesPerSample > 4))
    {
       checkFlag = 1;
    }

    numBytes = maxElems * bytesPerSample;
    afterDataRead = dataRead + numBytes;
    if (afterDataRead > buffer.data.lenData)
    {
        // Don't read more samples than are marked available in header
        numBytes = (int)buffer.data.lenData - (int)dataRead;
    }

    // read raw data into temporary buffer
    int convBuffSize = (numBytes + 15) & -8;
    char *temp = new char[convBuffSize];
    numBytes = static_cast<int>(fread(temp, 1, numBytes, fptr));
    dataRead += numBytes;

    numElems = numBytes / bytesPerSample;

    // swap byte ordert & convert to float, depending on sample format
    switch (bytesPerSample)
    {
        case 1:
        {
            unsigned char *temp2 = (unsigned char*)temp;
            double conv = 1.0 / 128.0;
            for (int i = 0; i < numElems; i ++)
            {
                buffer.pData[i] = (float)(temp2[i] * conv - 1.0);
            }
            break;
        }

        case 2:
        {
            short *temp2 = (short*)temp;
            double conv = 1.0 / 32768.0;
            for (int i = 0; i < numElems; i ++)
            {
                short value = temp2[i];
                buffer.pData[i] = (float)(value * conv);
            }
            break;
        }

        case 3:
        {
            char *temp2 = (char *)temp;
            double conv = 1.0 / 8388608.0;
            for (int i = 0; i < numElems; i ++)
            {
                int value = *((int*)temp2);
                value = value & 0x00ffffff;             // take 24 bits
                value |= (value & 0x00800000) ? 0xff000000 : 0;  // extend minus sign bits
                buffer.pData[i] = (float)(value * conv);
                temp2 += 3;
            }
            break;
        }

        case 4:
        {
            int *temp2 = (int *)temp;
            double conv = 1.0 / 2147483648.0;
            assert(sizeof(int) == 4);
            for (int i = 0; i < numElems; i ++)
            {
                int value = temp2[i];
                buffer.pData[i] = (float)(value * conv);
            }
            break;
        }
    }

    return numElems;
}





/*
 * --------------------------------------------------------------------------------------------------
 * --------------------------------------------------------------------------------------------------
 * --------------------------------------------------------------------------------------------------
 */

WavOutFile::WavOutFile(const char *fileName, MMbuffer<float> &buffer)
{
    fptr = fopen(fileName, "wb");
    if (fptr == NULL)
    {
        checkflag = 1;
    }
    writeBaseHeader(buffer);
    write(buffer);
}

WavOutFile::~WavOutFile()
{
    if (fptr) fclose(fptr);
    fptr = NULL;
}


void WavOutFile::writeBaseHeader(const MMbuffer<float> &buffer)
{
    fwrite(&(buffer.riff), sizeof (buffer.riff), 1, fptr);
    if(fwrite(&(buffer.format),sizeof (buffer.format),1,fptr)) {
        cout<< "success2"<<endl;
    };
    if(buffer.fact.factSign == factStr){
        fwrite(&(buffer.fact),sizeof (buffer.fact),1,fptr);

    }
    fwrite(&(buffer.data),sizeof (buffer.data),1,fptr);
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


void WavOutFile::write( MMbuffer<float> &buffer)
{
    int numBytes;
    int bytesPerSample;
    int numElems = buffer.getDataNum();
    const float *dataBuffer = buffer.pData;
    if (numElems == 0) return;

    bytesPerSample = buffer.format.BitsPerSample / 8;
    numBytes = numElems * bytesPerSample;
    int convBuffSize = numBytes + 7;
    char *temp = new char[convBuffSize]; // round bit up to avoid buffer overrun with 24bit-value assignment

    switch (bytesPerSample)
    {
        case 1:
        {
            unsigned char *temp2 = (unsigned char*) temp;
            for (int i = 0; i < numElems; i ++)
            {
                temp2[i] = (unsigned char)saturate(dataBuffer[i] * 128.0f + 128.0f, 0.0f, 255.0f);
            }
            break;
        }

        case 2:
        {
            short *temp2 = (short*) temp;
            for (int i = 0; i < numElems; i ++)
            {
                short value = (short)saturate(dataBuffer[i] * 32768.0f, -32768.0f, 32767.0f);
                temp2[i] = value;
            }
            break;
        }

        case 3:
        {
            char *temp2 = (char*) temp;
            for (int i = 0; i < numElems; i ++)
            {
                int value = saturate(dataBuffer[i] * 8388608.0f, -8388608.0f, 8388607.0f);
                *((int*)temp2) = value;
                temp2 += 3;
            }
            break;
        }

        case 4:
        {
            int *temp2 = (int*) temp;
            for (int i = 0; i < numElems; i ++)
            {
                int value = saturate(dataBuffer[i] * 2147483648.0f, -2147483648.0f, 2147483647.0f);
                temp2[i] = value;
            }
            break;
        }

    }
    int res = (int)fwrite(temp, 1, numBytes, fptr);

    if (res != numBytes)
    {
        checkflag = 1;
    }
    delete[] temp;
}
