#ifndef MMRATE_H
#define MMRATE_H

#include "readwav.h"
#include "iostream"
using namespace std;

enum Method{Linear, Cubic};

template<typename ValueType>
void setRateLinear(double newRate, MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome);

template<typename ValueType>
void setRateCubic(double newRate, MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome);

template<typename ValueType>
void setRate(double newRate, MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome, int method = 0);

template<typename ValueType>
void setPitch(double newPitch, MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome, int method = 0);

template<typename ValueType>
void monoToStereo(MMbuffer<ValueType> &source1, MMbuffer<ValueType> &source2, MMbuffer<ValueType> &outcome);

template<typename ValueType>
void stereoToMono(MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome1, MMbuffer<ValueType> &outcome2);

//The following two setRate functions use the algorithms in the SoundTouch library

template<typename ValueType>
void setRateLinear(double newRate, MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome){
    double rate = 0;
    int i = 0;
    int count = 0;
    int index = 0;
    int sampleEnd = source.getSampleNum() - 1;

    if (source.format.ChannelNum == 1){

        while (count < sampleEnd){
            double out;
            out = (1.0 - rate) * source.pData[count] + rate * source.pData[count + 1];
            outcome.pData[i] = (ValueType)out;
            i ++;

            rate += newRate;
            int integer = (int)rate;
            rate -= integer;
            count += integer;
        }
        outcome.data.lenData = (i - 1) * outcome.format.BitsPerSample/8;
        // After putting data in the outcome buffer, some parameters of it shoulde be changed
        outcome.callenAll();

    }else if (source.format.ChannelNum == 2){

        while (count < sampleEnd){
            double out0, out1;
            out0 = (1.0 - rate) * source.pData[index] + rate * source.pData[index + 2];
            out1 = (1.0 - rate) * source.pData[index + 1] + rate * source.pData[index + 3];
            outcome.pData[2*i] = (ValueType)out0;
            outcome.pData[2*i+1] = (ValueType)out1;
            i++;

            rate += newRate;
            int integer = (int)rate;
            rate -= integer;
            index += 2*integer;
            count += integer;
        }
        outcome.data.lenData = (i - 1) * 2 * outcome.format.BitsPerSample/8;
        outcome.callenAll();
    }
}

static const float _coeffs[]=
{ -0.5f,  1.0f, -0.5f, 0.0f,
   1.5f, -2.5f,  0.0f, 1.0f,
  -1.5f,  2.0f,  0.5f, 0.0f,
   0.5f, -0.5f,  0.0f, 0.0f};

template<typename ValueType>
void setRateCubic(double newRate, MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome){
    double rate = 0;
    int i = 0;
    int sampleEnd = source.getSampleNum() - 4;
    int index = 0;
    int count = 0;
    if (source.format.ChannelNum == 1){
        while (count < sampleEnd){
            float out;
            const float x3 = 1.0f;
            const float x2 = (float)rate;    // x
            const float x1 = x2*x2;           // x^2
            const float x0 = x1*x2;           // x^3
            float y0, y1, y2, y3;

            y0 =  _coeffs[0] * x0 +  _coeffs[1] * x1 +  _coeffs[2] * x2 +  _coeffs[3] * x3;
            y1 =  _coeffs[4] * x0 +  _coeffs[5] * x1 +  _coeffs[6] * x2 +  _coeffs[7] * x3;
            y2 =  _coeffs[8] * x0 +  _coeffs[9] * x1 + _coeffs[10] * x2 + _coeffs[11] * x3;
            y3 =  _coeffs[12] * x0 + _coeffs[13] * x1 + _coeffs[14] * x2 + _coeffs[15] * x3;

            out = y0 * source.pData[count] + y1 * source.pData[count+1] + y2 * source.pData[count+2] + y3 * source.pData[count+3];

            outcome.pData[i] = (ValueType)out;
            i ++;

            rate += newRate;
            int integer = (int)rate;
            rate -= integer;
            count += integer;
        }
        outcome.data.lenData = (i - 1) * outcome.format.BitsPerSample/8;
        outcome.callenAll();

    }else if (source.format.ChannelNum == 2){
        while (count < sampleEnd){
            const float x3 = 1.0f;
            const float x2 = (float)rate;    // x
            const float x1 = x2*x2;           // x^2
            const float x0 = x1*x2;           // x^3
            float y0, y1, y2, y3;
            float out0, out1;

            y0 =  _coeffs[0] * x0 +  _coeffs[1] * x1 +  _coeffs[2] * x2 +  _coeffs[3] * x3;
            y1 =  _coeffs[4] * x0 +  _coeffs[5] * x1 +  _coeffs[6] * x2 +  _coeffs[7] * x3;
            y2 =  _coeffs[8] * x0 +  _coeffs[9] * x1 + _coeffs[10] * x2 + _coeffs[11] * x3;
            y3 = _coeffs[12] * x0 + _coeffs[13] * x1 + _coeffs[14] * x2 + _coeffs[15] * x3;

            out0 = y0 * source.pData[index] + y1 * source.pData[index+2] + y2 * source.pData[index+4] + y3 * source.pData[index+6];
            out1 = y0 * source.pData[index+1] + y1 * source.pData[index+3] + y2 * source.pData[index+5] + y3 * source.pData[index+7];

            outcome.pData[2*i]   = (ValueType)out0;
            outcome.pData[2*i+1] = (ValueType)out1;
            i ++;

            rate += newRate;
            int integer = (int)rate;
            rate -= integer;
            index += 2 * integer;
            count += integer;
        }
        outcome.data.lenData = (i - 1) * 2 * outcome.format.BitsPerSample/8;
        outcome.callenAll();
    }
}

template<typename ValueType>
void setRate(double newRate, MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome, int method){
    outcome = source;
    outcome.data.lenData = double(outcome.data.lenData)/newRate + 1;
    outcome.initializeData();

    if (method == 0){
        setRateLinear(newRate, source, outcome);

    }else if (method == 1){
        setRateCubic(newRate, source, outcome);
    }
}


//template<typename ValueType>
//void setPitch(double newPitch, MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome, int method){
//    setRate(newPitch, source, outcome, method);
//    // tempo to 1/newPitch
//}



template<typename ValueType>
void monoToStereo(const MMbuffer<ValueType> &source1, MMbuffer<ValueType> &source2, MMbuffer<ValueType> &outcome){
    if ((source1.format.BitsPerSample != source2.format.BitsPerSample) || (source1.format.SampleRate != source2.format.SampleRate)){
        cout << "Invalid operation" << endl;
    }

    outcome.format.SampleRate = source1.format.SampleRate;
    outcome.format.BitsPerSample = source1.format.BitsPerSample;
    int outDataSize = source1.data.lenData + source2.data.lenData;
    outcome.data.lenData = outDataSize;

    int firstDataNum = source1.getDataNum();
    int secondDataNum = source2.getDataNum();
    int outDataNum = outcome.getDataNum();
    outcome.initializeData();

    for (int i = 0; i < outDataNum; i++){
        if (i % 2 == 0){
            if (i/2 > firstDataNum){
                outcome.pData[i] = 0;
                outcome.data.lenData += outcome.format.BitsPerSample/8;

            }else{
                outcome.pData[i] = source1.pData[i/2];
            }

        }else if (i % 2 == 1){
            if ((i - 1)/2 > secondDataNum){
                outcome.pData[i] = 0;
                outcome.data.lenData += outcome.format.BitsPerSample/8;

            }else{
                outcome.pData[i] = source2.pData[(i - 1)/2];
            }
        }
    }

    outcome.writeTags();
    outcome.calBlockAlign();
    outcome.calByteRate();
    outcome.callenAll();
}

template<typename ValueType>
void stereoToMono(MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome1, MMbuffer<ValueType> &outcome2){
    outcome1.writeTags();
    outcome1.format.BitsPerSample = source.format.BitsPerSample;
    outcome1.format.SampleRate = source.format.SampleRate;
    outcome1.data.lenData = source.data.lenData/2;
    outcome1.initializeData();

    outcome2.writeTags();
    outcome2.format.BitsPerSample = source.format.BitsPerSample;
    outcome2.format.SampleRate = source.format.SampleRate;
    outcome2.data.lenData = source.data.lenData/2;
    outcome2.initializeData();
    int dataNum = source.getDataNum();

    for (int i = 0; i < dataNum; i++){
        if (i % 2 == 0){
            outcome1.pData[i/2] = source.pData[i];

        }else if (i % 2 == 1){
            outcome2.pData[(i - 1)/2] = source.pData[i];
        }
    }

    outcome1.calBlockAlign();
    outcome1.calByteRate();
    outcome1.callenAll();
    outcome2.calBlockAlign();
    outcome2.calByteRate();
    outcome2.callenAll();
}
#endif // MMRATE_H
