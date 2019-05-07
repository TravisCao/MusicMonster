#ifndef MMRATEMODIFIER_H
#define MMRATEMODIFIER_H

#include "MMbuffer.h"

template<typename ValueType>
void setRateLinear(double newRate, const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome);

template<typename ValueType>
void setRateCubic(double newRate, const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome);

template<typename ValueType>
void monoToStereo(const MMbuffer<ValueType> &source1, const MMbuffer<ValueType> &source2, MMbuffer<ValueType> &outcome);

template<typename ValueType>
void stereoToMono(const MMbuffer<ValueType> &source, MMbuffer<ValueType> &outcome1, MMbuffer<ValueType> &outcome2);

#endif // MMRATEMODIFIER_H
