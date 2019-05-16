#include "wavio.h"
#include "filter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;




static inline int biquad(sf_MMM input_snd, sf_biquad_state_st *state, const char *output,int mark){
    sf_MMM output_snd = sf_MM_new(input_snd->size, input_snd->rate, false,true);
    int flag = 1;
    double judger = 0;
    float replace = 1;
    mark = flag;
    if (output_snd == nullptr){

        sf_snd_free(input_snd,flag);
        cout << "Error: Failed to apply filter" << endl;
        return 1;
    }

    // process the filter in one sweep
    sf_biquad_process(state, input_snd->size, input_snd->samples, output_snd->samples,judger);
    bool res = sf_wavsave(replace,output_snd, output);
    if(!res){cout << "incorrectly save wav";}

    sf_snd_free(input_snd,flag);
    sf_snd_free(output_snd,flag);

    return 0;
}





int filter_begin(char **input_list){

    char *input  = input_list[1];
    char *output = input_list[2];
    char *filter = input_list[3];

    sf_MMM input_snd = sf_wavload(input);
    if (input_snd == nullptr){
        cout << "load wave file failed!!!" << endl;
        return 1;
    }


    int filterOrder = 0;
    if      (strncmp(filter, "lowpass",7) == 0)    filterOrder = 1;
    else if (strncmp(filter, "highpass",8) == 0)   filterOrder = 2;
    else if (strncmp(filter, "bandpass",8) == 0)   filterOrder = 3;
    else if (strncmp(filter, "notch",5) == 0)      filterOrder = 4;
    else if (strncmp(filter, "peaking",7) == 0)    filterOrder = 5;
    else if (strncmp(filter, "allpass",7) == 0)    filterOrder = 6;
    else if (strncmp(filter, "lowshelf",8) == 0)   filterOrder = 7;
    else if (strncmp(filter, "highshelf",9) == 0)  filterOrder = 8;

    // 获取输入的参数
    float params[6];
    if(filterOrder == 8||filterOrder == 7||filterOrder == 5){
        for (int i = 0; i < 3; i++){params[i] = atof(input_list[4 + i]);}
    }
    else{
        for (int i = 0; i < 2; i++){params[i] = atof(input_list[4 + i]);}
    };


    int mark = 10;
    sf_biquad_state_st bq_state;
    switch(filterOrder)
    {

    case 0:
        break;

    case 1:
        sf_lowpass(&bq_state, input_snd->rate, params);
        biquad(input_snd, &bq_state, output,mark);
        break;


    case 2:
        sf_highpass(&bq_state, input_snd->rate, params);
        biquad(input_snd, &bq_state, output,mark);
        break;

    case 3:
        sf_bandpass(&bq_state, input_snd->rate, params);
        biquad(input_snd, &bq_state, output,mark);
        break;

    case 4:
        sf_notch(&bq_state, input_snd->rate, params);
        biquad(input_snd, &bq_state, output,mark);
        break;

    case 5:
        sf_peaking(&bq_state,input_snd->rate, params);
        biquad(input_snd, &bq_state, output,mark);
        break;

    case 6:
        sf_allpass(&bq_state, input_snd->rate, params);
        biquad(input_snd, &bq_state, output,mark);
        break;

    case 7:
        sf_lowshelf(&bq_state, input_snd->rate, params);
        biquad(input_snd, &bq_state, output,mark);
        break;

    case 8:
        sf_highshelf(&bq_state, input_snd->rate, params);
        biquad(input_snd, &bq_state, output,mark);
        break;
    }



    return 1;
}
