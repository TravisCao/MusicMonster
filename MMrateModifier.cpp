#include "MMrateModifier.h"
#include "MMbuffer.h"
#include "iostream"
using namespace std;

//The following two setRate functions use the algorithms in the SoundTouch library

template<typename ValueType>
void setRateLinear(double newRate, const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome){
    double fract = 0;
    int i = 0;
    int count = 0;
    int index = 0;
    int sampleEnd = source.getSampleNum() - 1;

    if (source.channelNum == 0){
        while (count < sampleEnd){
            double out;
            out = (1.0 - fract) * source[count] + fract * source[count + 1];
            outcome[i] = (ValueType)out;
            i ++;

            fract += newRate;
            int whole = (int)fract;
            fract -= whole;
            count += whole;
        }
        outcome.dataSizeInByte = (i - 1) * outcome.bitPerSample/8;

    }else if (source.channelNum == 1){
        while (count < sampleEnd){
            double out0, out1;
            out0 = (1.0 - fract) * source[index] + fract * source[index + 2];
            out1 = (1.0 - fract) * source[index + 1] + fract * source[index + 3];
            outcome[2*i] = (ValueType)out0;
            outcome[2*i+1] = (ValueType)out1;
            i++;
            fract += newRate;
            int whole = (int)fract;
            fract -= whole;
            index += 2*whole;
            count += whole;
        }
        outcome.dataSizeInByte = (i - 1) * 2 * outcome.bitPerSample/8;
    }
}

static const float _coeffs[]=
{ -0.5f,  1.0f, -0.5f, 0.0f,
   1.5f, -2.5f,  0.0f, 1.0f,
  -1.5f,  2.0f,  0.5f, 0.0f,
   0.5f, -0.5f,  0.0f, 0.0f};

template<typename ValueType>
void setRateCubic(double newRate, const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome){
    double fract = 0;
    int i = 0;
    int sampleEnd = source.getSampleNum() - 4;
    int index = 0;
    int count = 0;
    if (source.channelNum == 0){
        while (count < sampleEnd){
            float out;
            const float x3 = 1.0f;
            const float x2 = (float)fract;    // x
            const float x1 = x2*x2;           // x^2
            const float x0 = x1*x2;           // x^3
            float y0, y1, y2, y3;

            y0 =  _coeffs[0] * x0 +  _coeffs[1] * x1 +  _coeffs[2] * x2 +  _coeffs[3] * x3;
            y1 =  _coeffs[4] * x0 +  _coeffs[5] * x1 +  _coeffs[6] * x2 +  _coeffs[7] * x3;
            y2 =  _coeffs[8] * x0 +  _coeffs[9] * x1 + _coeffs[10] * x2 + _coeffs[11] * x3;
            y3 =  _coeffs[12] * x0 + _coeffs[13] * x1 + _coeffs[14] * x2 + _coeffs[15] * x3;

            out = y0 * source[count] + y1 * source[count+1] + y2 * source[count+2] + y3 * source[count+3];

            outcome[i] = (ValueType)out;
            i ++;

            fract += newRate;
            int whole = (int)fract;
            fract -= whole;
            count += whole;
        }
        outcome.dataSizeInByte = (i - 1) * outcome.bitPerSample/8;

    }else if (source.channelNum == 1){
        while (count < sampleEnd){
            const float x3 = 1.0f;
            const float x2 = (float)fract;    // x
            const float x1 = x2*x2;           // x^2
            const float x0 = x1*x2;           // x^3
            float y0, y1, y2, y3;
            float out0, out1;

            y0 =  _coeffs[0] * x0 +  _coeffs[1] * x1 +  _coeffs[2] * x2 +  _coeffs[3] * x3;
            y1 =  _coeffs[4] * x0 +  _coeffs[5] * x1 +  _coeffs[6] * x2 +  _coeffs[7] * x3;
            y2 =  _coeffs[8] * x0 +  _coeffs[9] * x1 + _coeffs[10] * x2 + _coeffs[11] * x3;
            y3 = _coeffs[12] * x0 + _coeffs[13] * x1 + _coeffs[14] * x2 + _coeffs[15] * x3;

            out0 = y0 * source[index] + y1 * source[index+2] + y2 * source[index+4] + y3 * source[index+6];
            out1 = y0 * source[index+1] + y1 * source[index+3] + y2 * source[index+5] + y3 * source[index+7];

            outcome[2*i]   = (ValueType)out0;
            outcome[2*i+1] = (ValueType)out1;
            i ++;

            fract += newRate;
            int whole = (int)fract;
            fract -= whole;
            index += 2 * whole;
            count += whole;
        }
        outcome.dataSizeInByte = (i - 1) * 2 * outcome.bitPerSample/8;
    }
}



template<typename ValueType>
void monoToStereo(const MMbuffer<ValueType> &source1, const MMbuffer<ValueType> &source2, MMbuffer<ValueType> &outcome){
    if ((source1.bitPerSample != source2.bitPerSample) || (source1.sampleRate != source2.sampleRate)){
        cout << "Invalid operation" << endl;
    }
    outcome.sampleRate = source1.sampleRate;
    outcome.bitPerSample = source1.bitPerSample;
    int outDataSize = source1.dataSizeInByte + source2.dataSizeInByte;
    outcome.dataSizeInByte = outDataSize;
    int firstDataNum = source1.getDataNum();
    int secondDataNum = source2.getDataNum();
    int outDataNum = outcome.getDataNum();

    for (int i = 0; i < outDataNum; i++){
        if (i % 2 == 0){
            if (i/2 > firstDataNum){
                outcome[i] = 0;
                outcome.dataSizeInByte += outcome.bitPerSample/8;
            }else{
                outcome[i] = source1[i/2];
            }

        }else if (i % 2 == 1){
            if ((i - 1)/2 > secondDataNum){
                outcome[i] = 0;
                outcome.dataSizeInByte += outcome.bitPerSample/8;
            }else{
                outcome[i] = source2[(i - 1)/2];
            }
        }
    }

    outcome.calBlockAlign();
    outcome.calByteRate();
    outcome.calFullSizeInByte();
}

template<typename ValueType>
void stereoToMono(MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome1, MMbuffer<ValueType> &outcome2){
    outcome1.bitPerSample = source.bitPerSample;
    outcome1.sampleRate = source.sampleRate;
    outcome1.dataSizeInByte = source.dataSizeInByte/2;
    outcome2.bitPerSample = source.bitPerSample;
    outcome2.sampleRate = source.sampleRate;
    outcome2.dataSizeInByte = source.dataSizeInByte/2;
    int dataNum = source.getDataNum();

    for (int i = 0; i < dataNum; i++){
        if (i % 2 == 0){
            outcome1[i/2] = source[i];
        }else if (i % 2 == 1){
            outcome2[(i - 1)/2] = source[i];
        }
    }

    outcome1.calBlockAlign();
    outcome1.calByteRate();
    outcome1.calFullSizeInByte();
    outcome2.calBlockAlign();
    outcome2.calByteRate();
    outcome2.calFullSizeInByte();
}



