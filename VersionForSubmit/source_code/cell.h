// (c) Copyright 2016, Sean Connelly (@voidqk), http://syntheti.cc
// MIT License
// Project Home: https://github.com/voidqk/sndfilter

// data structure for a 2-channel 32-bit floating point sound in memory

#ifndef SNDFILTER_SND__H
#define SNDFILTER_SND__H
#include <stdbool.h>

typedef struct {
    float L; // left channel sample
    float R; // right channel sample
} sf_sample_MM;

typedef struct {
    sf_sample_MM *samples;
    int size; // number of samples
    int rate; // samples per second
} sf_MM, *sf_MMM;

sf_MMM sf_MM_new(int size, int rate, bool clear,bool standard);
void   sf_snd_free(sf_MMM snd,int flag);

#endif // SNDFILTER_SND__H
