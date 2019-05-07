#ifndef MMBUFFER_H
#define MMBUFFER_H

template <typename ValueType>
class MMbuffer{

    MMbuffer();

    ~MMbuffer();

    void setFullSize(unsigned long fullSize);

    void setFmtSize(unsigned long fmtSize);

    void setAudioFormat(unsigned short audioFormat);

    void setChannelNum(unsigned short channelNum);

    void setSampleRate(unsigned long sampleRate);

    void setByteRate(unsigned long byteRate);

    void setBlockAlign(unsigned short blockAlign);

    void setBitPerSample(unsigned short bitPerSample);

    void setDataSize(unsigned long dataSize);

    void iniData();

    int getDataNum() const;

    int getSampleNum() const;

    unsigned long getFullSizeInByte() const;

    unsigned long getSampleRate() const;

    unsigned short getBitPerSample() const;

    unsigned long getDataSize() const;

    unsigned short getChannelNum() const;

    void calFullSizeInByte();

    void calByteRate();

    void calBlockAlign();

//    ValueType * getData();

private:

    MMbuffer deepCopy();

    unsigned long fullSizeInByte;

    unsigned long fmtSizeInByte;

    unsigned short audioFormat;

    unsigned short channelNum;

    unsigned long sampleRate;

    unsigned long byteRate;

    unsigned short blockAlign;

    unsigned short bitPerSample;

    unsigned long dataSizeInByte;

    ValueType * data;

    friend void monoToStereo(MMbuffer<ValueType> &source1, MMbuffer<ValueType> &source2, MMbuffer<ValueType> &outcome);

    friend void stereoToMono(const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome1, MMbuffer<ValueType> &outcome2);

    friend void setRateLinear(double newRate, const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome, int &sampleNum);

    friend void setRateCubic(double newRate, const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome, int &sampleNum);
};

#endif // MMBUFFER_H
