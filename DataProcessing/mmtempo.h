#ifndef MMREALTEMPO_H
#define MMREALTEMPO_H

#include "readwav.h"
#include "iostream"
#include "math.h"
using namespace std;

//The following functions are developed and tested by ourselves one by one.

template<typename ValueType>
void setTempo(double newTempo, MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome){
    int i_forin = 0;
    int i_forout = 0;
    int sampleEnd = source.getDataNum() - 1;
    /*change rate to 0.5, 0.33, 0.25, 2.0, 1.5 and all of them support double channels */

/********************************************/
    if (newTempo == 0.5){
        outcome.setDataSize(2 * source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out1 = source.pData[i_forin];
                float out2 = source.pData[i_forin];
                outcome.pData[i_forout] = out1;
                outcome.pData[i_forout + 1] = out2;
                i_forin += 1;
                i_forout += 2;
        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_forin];
                float outl2 = source.pData[i_forin];
                outcome.pData[i_forout] = outl1;
                outcome.pData[i_forout + 2] = outl2;
                float outr1 = source.pData[i_forin];
                float outr2 = source.pData[i_forin];
                outcome.pData[i_forout + 1] = outr1;
                outcome.pData[i_forout + 3] = outr2;
                i_forin += 2;
                i_forout += 4;
            }

        }
    }
    else if (newTempo == 0.33){
        outcome.setDataSize(3 * source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out1 = source.pData[i_forin];
                float out2 = source.pData[i_forin];
                float out3 = source.pData[i_forin];
                outcome.pData[i_forout] = out1;
                outcome.pData[i_forout + 1] = out2;
                outcome.pData[i_forout + 2] = out3;

                i_forin += 1;
                i_forout += 3;

        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_forin];
                float outl2 = source.pData[i_forin];
                float outl3 = source.pData[i_forin];
                outcome.pData[i_forout] = outl1;
                outcome.pData[i_forout + 2] = outl2;
                outcome.pData[i_forout + 4] = outl3;

                float outr1 = source.pData[i_forin + 1];
                float outr2 = source.pData[i_forin + 1];
                float outr3 = source.pData[i_forin + 1];
                outcome.pData[i_forout + 1] = outr1;
                outcome.pData[i_forout + 3] = outr2;
                outcome.pData[i_forout + 5] = outr3;
                i_forin += 2;
                i_forout += 6;
            }

        }
        cout<<"finished 0.33"<<endl;
    }
    else if (newTempo == 0.25){            //guaishou
        outcome.setDataSize(4 * source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out1 = source.pData[i_forin];
                float out2 = source.pData[i_forin];
                float out3 = source.pData[i_forin];
                float out4 = source.pData[i_forin];
                outcome.pData[i_forout] = out1;
                outcome.pData[i_forout + 1] = out2;
                outcome.pData[i_forout + 2] = out3;
                outcome.pData[i_forout + 3] = out4;

                i_forin += 1;
                i_forout += 4;

        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_forin];
                float outl2 = source.pData[i_forin];
                float outl3 = source.pData[i_forin];
                float outl4 = source.pData[i_forin];
                outcome.pData[i_forout] = outl1;
                outcome.pData[i_forout + 2] = outl2;
                outcome.pData[i_forout + 4] = outl3;
                outcome.pData[i_forout + 6] = outl4;

                float outr1 = source.pData[i_forin + 1];
                float outr2 = source.pData[i_forin + 1];
                float outr3 = source.pData[i_forin + 1];
                float outr4 = source.pData[i_forin + 1];
                outcome.pData[i_forout + 1] = outr1;
                outcome.pData[i_forout + 3] = outr2;
                outcome.pData[i_forout + 5] = outr3;
                outcome.pData[i_forout + 7] = outr4;
                i_forin += 2;
                i_forout += 8;
            }

        }

    }
    else if (newTempo == 2.0){
        outcome.setDataSize(0.5 * source.getDataSize());
        outcome.initializeData();//tempo为原来 2 倍
        if (source.getChannelNum() == 1){      //单声道
            while (i_forin < sampleEnd){
                //float j = source.pData[i_forin];
                float out = source.pData[i_forin];
                outcome.pData[i_forout] = out; //source.pData[i_forin];
                cout<< outcome.pData[i_forout];
                i_forout += 1;
                i_forin += 2;
                //if (i_forout == outcome.getDataSize() - 2)  break;
                //cout << outcome.pData[i_forout] ;
                //cout <<"out:"<<outcome.pData[i_forout]<<" endd" ;
            }

            cout<<"finished change rate to 2.0, good! ";
        }

        else if (source.getChannelNum() == 2){      //双声道

            while (i_forin < sampleEnd) {
                outcome.pData[i_forout] = source.pData[i_forin];
                outcome.pData[i_forout + 1] = source.pData[i_forin + 1];
                i_forout += 2;
                i_forin += 4;
            }

            cout<<"finished2.0   2";

        }
}
    else if (newTempo == 1.5) {
        outcome.setDataSize((2/3)*source.getDataSize());
        outcome.initializeData();

        if(source.getDataNum() == 1){
            while (i_forin < sampleEnd){

            }
        }
        else if (source.getSampleNum() == 2) {
            while (i_forin < sampleEnd){

            }

        }

    }
    else if (newTempo == 1.55){                 //tempo为原来 1.5 倍
            outcome.setDataSize( (2/3) * source.getDataSize());
            outcome.initializeData();

            if (source.getChannelNum() == 1){           //单声道
                while (i_forin < sampleEnd) {

                float out1 = source.pData[i_forin];
                float mid1 = source.pData[i_forin + 1];
                float mid2 = source.pData[i_forin + 2];
                float out3 = source.pData[i_forin + 3];
                float out2 = ( out1 + out3 + mid1 + mid2 ) / 4 ;

                outcome.pData[i_forout] = out1;
                outcome.pData[i_forout + 1] = out2;

                cout<<"kk"<<out1<<"jj"<<out2;

                i_forout += 2;
                i_forin += 3;
                cout<<outcome.pData[i_forout];
                }
                cout<<"finished1.5    1    "<<endl;


            }
            else if (source.getChannelNum() == 2){      //双声道

                while (i_forin < sampleEnd) {
                    float outl1, outl2, outl3, midl1, midl2;
                    outl1 = source.pData[i_forin];
                    midl1 = source.pData[i_forin + 2];
                    midl2 = source.pData[i_forin + 4];
                    outl3 = source.pData[i_forin + 6];
                    outl2 = ( outl1 + outl3 + midl1 + midl2 ) / 4 ;
                    outcome.pData[i_forout] = outl1;
                    outcome.pData[i_forout + 2] = outl2;

                    float outr1, outr2, outr3, midr1, midr2;
                    outr1 = source.pData[i_forin + 1];
                    midr1 = source.pData[i_forin + 3];
                    midr2 = source.pData[i_forin + 5];
                    outr3 = source.pData[i_forin + 7];
                    outr2 = ( outr1 + outr3 + midr1 + midr2 ) / 4 ;

                    outcome.pData[i_forout + 1] = outr1;
                    outcome.pData[i_forout + 3] = outr2;

                    i_forout += 4;
                    i_forin += 6;
                }
                cout<<"finished   1.5     2    ";

                }

}
    /*some special changes*/
    else if (newTempo == 22.0){
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out = source.pData[i_forin];
                outcome.pData[i_forout] = out*out;
                i_forin += 1;
                i_forout += 1;

        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_forin];
                outcome.pData[i_forout] = outl1*outl1;
                float outr1 = source.pData[i_forin];
                outcome.pData[i_forout + 1] = outr1*outr1;
                i_forin += 2;
                i_forout += 2;
            }

        }
    }
    else if (newTempo == 23.0){
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out = source.pData[i_forin];
                outcome.pData[i_forout] = out*out*out;
                i_forin += 1;
                i_forout += 1;

        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_forin];
                outcome.pData[i_forout] = outl1*outl1*outl1;
                float outr1 = source.pData[i_forin];
                outcome.pData[i_forout + 1] = outr1*outr1*outr1;
                i_forin += 2;
                i_forout += 2;
            }

        }
    }
    else if (newTempo == 24.0){
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out = source.pData[i_forin];
                outcome.pData[i_forout] = out*(0.5*out);
                i_forin += 1;
                i_forout += 1;

        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_forin];
                outcome.pData[i_forout] = outl1*(0.5*outl1);
                float outr1 = source.pData[i_forin];
                outcome.pData[i_forout + 1] = outr1*(0.5*outr1);
                i_forin += 2;
                i_forout += 2;
            }

        }
    }
    else if (newTempo == 32.0){   //两倍
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out = source.pData[i_forin];
                outcome.pData[i_forout] = out*2;
                i_forin += 1;
                i_forout += 1;

        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_forin];
                outcome.pData[i_forout] = outl1*2;
                float outr1 = source.pData[i_forin];
                outcome.pData[i_forout + 1] = outr1*2;
                i_forin += 2;
                i_forout += 2;
            }

        }
    }
    else if (newTempo == 33.0){   //三倍
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out = source.pData[i_forin];
                outcome.pData[i_forout] = out * 3;
                i_forin += 1;
                i_forout += 1;

        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_forin];
                outcome.pData[i_forout] = outl1*2;
                float outr1 = source.pData[i_forin];
                outcome.pData[i_forout + 1] = outr1*3;
                i_forin += 2;
                i_forout += 2;
            }

        }
    }
    else if (newTempo == 40.0){   //声音， 震颤, best parameterr by testing +1 -1 or 1.05 -1.05
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out1 = source.pData[i_forin];
                float out2 = source.pData[i_forin];
                outcome.pData[i_forout] = out1*1000;//+ 1.05;
                outcome.pData[i_forout + 1] = out2*0.001;// - 1.05;
                i_forin += 2;
                i_forout += 2;
 }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_forin];
                float outl2 = source.pData[i_forin + 2];
                outcome.pData[i_forout] = outl1*1000;
                outcome.pData[i_forout + 2] = outl2*0.001;
                float outr1 = source.pData[i_forin + 1];
                float outr2 = source.pData[i_forin + 3];
                outcome.pData[i_forout + 1] = outr1*1000;
                outcome.pData[i_forout + 3] = outr2*0.001;
                i_forin += 4;
                i_forout += 4;
            }

        }
    }
    else if (newTempo == 41.0){   //慢逐渐快
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        int times = 1;
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out = source.pData[i_forin];
                for (int i = 0; i < times; i++){
                     out = out * out;
                }
                outcome.pData[i_forout] = out;
                if(i_forin == sampleEnd/4 || i_forin == sampleEnd/2 || i_forin == sampleEnd*3/4){
                       times += 0.5;
                }

                i_forin += 1;
                i_forout += 1;

        }
        }/*只支持单声道*/

    }
    else if (newTempo == 42.0){   //快逐渐慢
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        int times = 10;
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out = source.pData[i_forin];
                for (int i = 0; i < times; i++){
                     out = out * out;
                }
                outcome.pData[i_forout] = out;
                if(i_forin == sampleEnd/4 || i_forin == sampleEnd/2 || i_forin == sampleEnd*3/4){
                       times -= 2;
                }

                i_forin += 1;
                i_forout += 1;

        }
            }


        }/*只支持单声道*/

    else if (newTempo == 99.0){          //make the reverse music, butttt it may not run,,,
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        int i_reverse = sampleEnd;
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out = source.pData[i_reverse];
                outcome.pData[i_forout] = out;
                i_reverse -= 1;
                i_forout += 1;
                i_forin += 1;
        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_reverse - 1];
                outcome.pData[i_forout] = outl1;
                float outr1 = source.pData[i_reverse];
                outcome.pData[i_forout + 1] = outr1;
                i_reverse -= 2;
                i_forout += 2;
                i_forin += 2;
            }

        }
    }
   else if (newTempo == 98.0){          //reverse 2.0 speed up.
        outcome.setDataSize(0.5*source.getDataSize());
        outcome.initializeData();
        int i_reverse = sampleEnd;
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out = source.pData[i_reverse];
                outcome.pData[i_forout] = out;
                i_reverse -= 2;
                i_forout += 1;
                i_forin += 2;
        }
        }
        else if (source.getChannelNum() == 2) {
            while (i_forin < sampleEnd) {
                float outl1 = source.pData[i_reverse - 1];
                outcome.pData[i_forout] = outl1;
                float outr1 = source.pData[i_reverse];
                outcome.pData[i_forout + 1] = outr1;
                i_reverse -= 4;
                i_forout += 2;
                i_forin += 4;
            }

        }
    }
    else if (newTempo == 97.0){          //reverse 0.5 speed lower.
         outcome.setDataSize(2*source.getDataSize());
         outcome.initializeData();
         int i_reverse = sampleEnd;
         if(source.getChannelNum() == 1){
             while(i_forin < sampleEnd){
                 float out = source.pData[i_reverse];
                 outcome.pData[i_forout] = out;
                 outcome.pData[i_forout -1] = out;
                 i_reverse -= 1;
                 i_forout += 2;
                 i_forin += 1;
         }
         }
         else if (source.getChannelNum() == 2) {
             while (i_forin < sampleEnd) {
                 float outl1 = source.pData[i_reverse - 1];
                 outcome.pData[i_forout] = outl1;
                 outcome.pData[i_forout - 2] = outl1;
                 float outr1 = source.pData[i_reverse];
                 outcome.pData[i_forout + 1] = outr1;
                 outcome.pData[i_forout + 3] = outr1;
                 i_reverse -= 2;
                 i_forout += 4;
                 i_forin += 2;
             }

         }
     }
    else if (newTempo == 88.0){     //increase the pitch, ' mission succeed and 222  '
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out1 = source.pData[i_forin];
                float out2 = source.pData[i_forin + 1];
                float out3 = source.pData[i_forin + 2];
                outcome.pData[i_forout] = (out1 * out2) *3; ;
                outcome.pData[i_forout + 1] =( out2 * out3 )*3 ;
                i_forin += 2;
                i_forout += 2;
        }
        }
        if(source.getChannelNum() == 2){
            while(i_forin < sampleEnd){
                float outl1 = source.pData[i_forin];
                float outl2 = source.pData[i_forin + 2];
                float outl3 = source.pData[i_forin + 4];
                outcome.pData[i_forout] = (outl1 * outl2) *3; ;
                outcome.pData[i_forout + 1] =( outl2 * outl3 )*3 ;
                float outr1 = source.pData[i_forin + 1];
                float outr2 = source.pData[i_forin + 3];
                float outr3 = source.pData[i_forin + 5];
                outcome.pData[i_forout] = (outr1 * outr2) *3; ;
                outcome.pData[i_forout + 1] =( outr2 * outr3 )*3 ;
                i_forin += 4;
                i_forout += 4;
        }
        }
    }
    else if (newTempo == 89.0){     //decrease the pitch test as ttt,
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out1 = source.pData[i_forin];
                float out2 = source.pData[i_forin + 1];
                float out3 = source.pData[i_forin + 2];
                float out4 = source.pData[i_forin + 3];
                outcome.pData[i_forout] = (cos(out1)*cos(out2)*cos(out3)*sin(out2)*sin(out3)*sin(out1))*3;
                outcome.pData[i_forout + 1] = (cos(out4)*cos(out2)*cos(out3)*sin(out1)*sin(out2)*sin(out3))*3;
                i_forin += 2;
                i_forout += 2;
        }
        }
    }
    else if (newTempo == 90.0){
        outcome.setDataSize(source.getDataSize());
        outcome.initializeData();
        if(source.getChannelNum() == 1){
            while(i_forin < sampleEnd){
                float out1 = source.pData[i_forin];
                float out2 = source.pData[i_forin + 1];
                outcome.pData[i_forout] = sin(out1/2+out2/2) * sin(out1/2+out2/2);
                i_forin += 1;
                i_forout += 1;
        }
    }
    }
    outcome.calBlockAlign();
    outcome.calByteRate();
    outcome.callenAll();
}
#endif // MMREALTEMPO_H
