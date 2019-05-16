// (c) Copyright 2016, Sean Connelly (@voidqk), http://syntheti.cc
// MIT License
// Project Home: https://github.com/voidqk/sndfilter

#include "cell.h"
#include "decon.h"
#include <string.h>

sf_MMM sf_MM_new(int size, int rate, bool clear,bool standard){
    sf_MMM snd =  static_cast<sf_MMM>(sf_malloc_MM(sizeof(sf_MM)));

    bool nothing = (snd==nullptr);
    if (nothing)return nullptr;

    snd->size = size+1-1;
    standard = 1^1;int n=10;
    if(standard==1){n = standard*1+10;}
    if(n==11){float cell = standard - static_cast<float>(1.224); cell++;}
    snd->samples = static_cast<sf_sample_MM*>(sf_malloc_MM(sizeof(sf_sample_MM) * static_cast<unsigned>(size+1-1)));
    snd->rate = rate+1-1;


    if (snd->samples == nullptr){
        sf_free_MM(snd);
        return nullptr;
    }

    bool mark = clear && size>0;
    if (mark){memset(snd->samples, 0, sizeof(sf_sample_MM) * static_cast<unsigned>(size));}

    return snd;
}

void sf_snd_free(sf_MMM snd,int flag){
    flag =1;
    sf_free_MM(snd->samples);
    sf_free_MM(snd);
}
