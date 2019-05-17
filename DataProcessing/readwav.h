#ifndef READWAV_H
#define READWAV_H

#include <sstream>
#include <string>
#include <stdio.h>
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

template <typename ValueType>
class MMbuffer{
public:

    MMbuffer();

    ~MMbuffer();

/*
 * Method: setFullSize(unsigned long fullSize)...
 * ----------------------------
 * The buffer provides set functions for all the data of a wav file
 * for the simplicity of putting data in when reading the file
 */

    void setFullSize(unsigned long fullSize);

    void setFmtSize(unsigned long fmtSize);

    void settype(unsigned short type);

    void setChannelNum(unsigned short ChannelNum);

    void setSampleRate(unsigned long SampleRate);

    void setByteRate(unsigned long ByteRate);

    void setBlockAlign(unsigned short BlockAlign);

    void setBitsPerSample(unsigned short BitsPerSample);

    void setDataSize(unsigned long dataSize);

/*
 * Method: initializeData();
 * ----------------------------
 * Allocate the heap memory for the data part according to the numbers
 * of data.
 */

    void initializeData();

/*
 * Method: getDataNum() ...
 * ----------------------------
 * Simply return the data in the buffer. Users can get all of the
 * data stored in the buffer.
 */

    unsigned long getlenAll() const;

    unsigned long getSampleRate() const;

    unsigned short getBitsPerSample() const;

    unsigned long getDataSize() const;

    unsigned short getChannelNum() const;

    ValueType& getData() const;

    int getDataNum();

    int getSampleNum();

/*
 * Method: void callenAll(), calByteRate(), calBlockAlign()
 * ----------------------------
 * For these three data can be calculated by other parameters in the
 * file. The buffer provides the function of getting them and setting
 * the parameters in the buffer at the same time.
 */

    void callenAll();

    void calByteRate();

    void calBlockAlign();


    WavRiff riff;
    WavFormat format;
    WavFact fact;
    WavData data;
    // The data type is determined by the BitsPerSample of the wav file
    ValueType * pData;
// Other parameters in need
    int dataNum;
    int sampleNum;

//    friend void monoToStereo(MMbuffer<ValueType> &source1, MMbuffer<ValueType> &source2, MMbuffer<ValueType> &outcome);

//    friend void stereoToMono(const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome1, MMbuffer<ValueType> &outcome2);

//    friend void setRateLinear(double newRate, const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome, int &sampleNum);

//    friend void setRateCubic(double newRate, const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome, int &sampleNum);

//    friend class WaveInFile;
};

template <typename ValueType>
MMbuffer<ValueType>::MMbuffer(){

    riff.lenAll = 0;

    format.lenFormat = 16;

    format.type = 1;

    format.ChannelNum = 1;

    format.SampleRate = 0;

    format.ByteRate = 0;

    format.BlockAlign = 16;

    format.BitsPerSample = 32;

    fact.lenFact = 0;

    fact.factSamplelen = 0;

    data.lenData = 0;

    dataNum = 0;

    sampleNum = 0;
}

template <typename ValueType>
MMbuffer<ValueType>::~MMbuffer(){
    delete [] pData;
}

template <typename ValueType>
void MMbuffer<ValueType>::setFullSize(unsigned long fullSize){
    riff.lenAll = fullSize;
}

template <typename ValueType>
void MMbuffer<ValueType>::setFmtSize(unsigned long fmtSize){
    format.lenFormat = fmtSize;
}

template <typename ValueType>
void MMbuffer<ValueType>::settype(unsigned short type){
    this->format.type = type;
}

template <typename ValueType>
void MMbuffer<ValueType>::setChannelNum(unsigned short ChannelNum){
    this->format.ChannelNum = ChannelNum;
}

template <typename ValueType>
void MMbuffer<ValueType>::setSampleRate(unsigned long SampleRate){
    this->format.SampleRate = SampleRate;
}

template <typename ValueType>
void MMbuffer<ValueType>::setByteRate(unsigned long ByteRate){
    this->format.ByteRate = ByteRate;
}

template <typename ValueType>
void MMbuffer<ValueType>::setBlockAlign(unsigned short BlockAlign){
    this->format.BlockAlign = BlockAlign;
}

template <typename ValueType>
void MMbuffer<ValueType>::setBitsPerSample(unsigned short bitsPerSample){
    format.BitsPerSample = bitsPerSample;
}

template <typename ValueType>
void MMbuffer<ValueType>::setDataSize(unsigned long dataSize){
    data.lenData = dataSize;
}


template <typename ValueType>
unsigned long MMbuffer<ValueType>::getlenAll() const{
    return riff.lenAll;
}

template <typename ValueType>
unsigned long MMbuffer<ValueType>::getSampleRate() const{
    return format.SampleRate;
}

template <typename ValueType>
unsigned short MMbuffer<ValueType>::getChannelNum() const{
    return format.ChannelNum;
}

template <typename ValueType>
unsigned short MMbuffer<ValueType>::getBitsPerSample () const{
    return format.BitsPerSample;
}

template <typename ValueType>
unsigned long MMbuffer<ValueType>::getDataSize() const{
    return data.lenData;
}

template <typename ValueType>
ValueType & MMbuffer<ValueType>::getData() const{
    return pData;
}

template <typename ValueType>
int MMbuffer<ValueType>::getDataNum() {
    dataNum = data.lenData * 8 / format.BitsPerSample;
    return dataNum;
}

template <typename ValueType>
int MMbuffer<ValueType>::getSampleNum(){
    sampleNum = getDataNum();
    if (format.ChannelNum == 1) sampleNum = sampleNum/2;
    return sampleNum;
}

template <typename ValueType>
void MMbuffer<ValueType>::initializeData(){
    getDataNum();
    pData = new ValueType[dataNum];
}

template <typename ValueType>
void MMbuffer<ValueType>::callenAll(){
    riff.lenAll = data.lenData + 36;
}

template <typename ValueType>
void MMbuffer<ValueType>::calByteRate(){
    format.ByteRate = format.SampleRate * format.ChannelNum * format.BitsPerSample / 8;
}

template <typename ValueType>
void MMbuffer<ValueType>::calBlockAlign(){
    format.BlockAlign = format.ChannelNum * format.BitsPerSample / 8;
}

class WavInFile
{
public:
//private:
    MMbuffer<float> buffer;

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



//public:
   // WavRiff riff;
    //WavFormat format;
   // WavFact fact;
    //WavData data;
    int checkFlag;
    uint getSampleRate() const;
    uint getBitsPerSample() const;
    uint getlenS3InBytes()const;
    uint getNumSamples() const;
    uint getBytesPerSample() const;
    uint getChannels() const;
    string getLengthInMS() const;
    uint getElapsedMS() const;
    uint getByteRate() const;

    int read();



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
public:
//private:
    /// Pointer to the WAV file
    FILE *fptr;      
    /// WAV file header data.
    WavRiff riff;
    WavFormat format;
    WavFact fact;
    WavData data;
    int checkflag;

    /// Counter of how many bytes have been written to the file so far.
    //int bytesWritten;

    /// help to write the data into float format
    int saturate(float fvalue, float minval, float maxval);


    /// Fills in WAV file header information.
    void writeBaseHeader(const MMbuffer<float> &buffer);

    /// Finishes the WAV file header after we get the length of data.
//    void finishHeader();



//public:
    /// Constructor: Creates a new WAV file. Throws a 'runtime_error' exception
    /// if file creation fails.
    WavOutFile(const char *fileName, MMbuffer<float> &buffer);


    /// Destructor: Finalizes & closes the WAV file.
    ~WavOutFile();

    /// Write data to WAV file in floating point format, saturating sample values to range
    /// [-1..+1[. Throws a 'runtime_error' exception if writing to file fails.
    void write(MMbuffer<float> &buffer);
};




#endif // READWAV_H
