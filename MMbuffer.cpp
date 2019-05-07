#include "MMbuffer.h"

template <typename ValueType>
MMbuffer<ValueType>::MMbuffer(){

    fullSizeInByte = 0;

    fmtSizeInByte = 16;

    audioFormat = 1;

    channelNum = 0;

    sampleRate = 0;

    byteRate = 0;

    blockAlign = 0;

    bitPerSample = 0;

    dataSizeInByte = 0;

    dataSizeInByte = 0;

    data = nullptr;
}

template <typename ValueType>
MMbuffer<ValueType>::~MMbuffer(){
    delete [] data;
}

template <typename ValueType>
void MMbuffer<ValueType>::setFullSize(unsigned long fullSize){
    this->fullSizeInByte = fullSize;
}

template <typename ValueType>
void MMbuffer<ValueType>::setFmtSize(unsigned long fmtSize){
    this->fmtSizeInByte = fmtSize;
}

template <typename ValueType>
void MMbuffer<ValueType>::setAudioFormat(unsigned short audioFormat){
    this->audioFormat = audioFormat;
}

template <typename ValueType>
void MMbuffer<ValueType>::setChannelNum(unsigned short channelNum){
    this->channelNum = channelNum;
}

template <typename ValueType>
void MMbuffer<ValueType>::setSampleRate(unsigned long sampleRate){
    this->sampleRate = sampleRate;
}

template <typename ValueType>
void MMbuffer<ValueType>::setByteRate(unsigned long byteRate){
    this->byteRate = byteRate;
}

template <typename ValueType>
void MMbuffer<ValueType>::setBlockAlign(unsigned short blockAlign){
    this->blockAlign = blockAlign;
}

template <typename ValueType>
void MMbuffer<ValueType>::setBitPerSample(unsigned short bitPerSample){
    this->bitPerSample = bitPerSample;
}

template <typename ValueType>
void MMbuffer<ValueType>::setDataSize(unsigned long dataSize){
    this->dataSizeInByte = dataSize;
}

template <typename ValueType>
unsigned long MMbuffer<ValueType>::getFullSizeInByte() const{
    return this->fullSizeInByte;
}

template <typename ValueType>
unsigned long MMbuffer<ValueType>::getSampleRate() const{
    return this->sampleRate;
}

template <typename ValueType>
unsigned short MMbuffer<ValueType>::getBitPerSample () const{
    return this->bitPerSample;
}

template <typename ValueType>
unsigned long MMbuffer<ValueType>::getDataSize() const{
    return this->dataSizeInByte;
}

template <typename ValueType>
unsigned short MMbuffer<ValueType>::getChannelNum() const{
    return this->channelNum;
}

template <typename ValueType>
int MMbuffer<ValueType>::getDataNum() const{
    int dataNum = this->dataSizeInByte * 8 / this->bitPerSample;
    return dataNum;
}

template <typename ValueType>
int MMbuffer<ValueType>::getSampleNum() const{
    int sampleNum = this->getDataNum();
    if (this->channelNum == 1) sampleNum = sampleNum/2;
    return sampleNum;
}

template <typename ValueType>
void MMbuffer<ValueType>::iniData(){
    int dataNum = this->getDataNum();
    data = new ValueType[dataNum];
}

template <typename ValueType>
void MMbuffer<ValueType>::calFullSizeInByte(){
    this->fullSizeInByte = this->dataSizeInByte + 36;
}

template <typename ValueType>
void MMbuffer<ValueType>::calByteRate(){
    this->byteRate = this->sampleRate * this->channelNum * this->bitPerSample / 8;
}

template <typename ValueType>
void MMbuffer<ValueType>::calBlockAlign(){
    this->blockAlign = this->channelNum * this->bitPerSample / 8;
}

