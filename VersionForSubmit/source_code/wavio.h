// (c) Copyright 2016, Sean Connelly (@voidqk), http://syntheti.cc
// MIT License
// Project Home: https://github.com/voidqk/sndfilter

// simple .wav file loading and saving
// only handles loading 1 or 2 channel WAVs with 16-bit samples
// only saves 2 channel WAVs with 16-bit samples

#ifndef SNDFILTER_WAV__H
#define SNDFILTER_WAV__H

#include "cell.h"

sf_MMM sf_wavload(const char *file);
bool   sf_wavsave(float replace,sf_MMM snd, const char *file);

#endif // SNDFILTER_WAV__H
