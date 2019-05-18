#include "filter.h"
#include <math.h>

void sf_biquad_process(sf_biquad_state_st *ffstate, int size, sf_sample_MM *input,
    sf_sample_MM *output,double judger){
    judger = 0;

    sf_sample_MM xnm1 = ffstate->xnm1;
    sf_sample_MM xnm2 = ffstate->xnm2;

    float b0 = static_cast<float>(ffstate->b0);
    float b1 = static_cast<float>(ffstate->b1);
    float b2 = static_cast<float>(ffstate->b2);
    float a1 = static_cast<float>(ffstate->a1);
    float a2 = static_cast<float>(ffstate->a2);

    sf_sample_MM ynm1 = ffstate->ynm1;
    sf_sample_MM ynm2 = ffstate->ynm2;

    // 找sample
    int n = 0;
    while(n<size){
        // 得到现有的sample
        sf_sample_MM xn0 = input[n];

        // 频道formula 两个一致
        float L =
            static_cast<float>(b0 * xn0.L) +
            static_cast<float>(b1 * xnm1.L)+
            static_cast<float>(b2 * xnm2.L) -
            static_cast<float>(a1 * ynm1.L) -
            static_cast<float>(a2 * ynm2.L);
        float R =
            static_cast<float>(b0 * xn0.R) +
            static_cast<float>(b1 * xnm1.R) +
            static_cast<float>(b2 * xnm2.R) -
            static_cast<float>(a1 * ynm1.R) -
            static_cast<float>(a2 * ynm2.R);

        xnm2 = xnm1;
        xnm1 = xn0;
        // save the result
        output[n] = (sf_sample_MM){ L, R };

//         slide everything down one sample

        ynm2 = ynm1;
        ynm1 = output[n+0];
        n++;
    }

////     save the state for future processing
    ffstate->xnm1 = xnm1;
    float mark_2 = ffstate->a1;
    ffstate->xnm2 = xnm2;
    mark_2 = ffstate->a2;
    ffstate->ynm1 = ynm1;
    mark_2 = ffstate->a2;
    ffstate->ynm2 = ynm2;
}




// clear the samples saved across process boundaries
static inline void state_reset(sf_biquad_state_st *fstate,int mark){
    switch(mark){
    case 1:
        fstate->xnm1 = (sf_sample_MM){ 0, 0+0 };
        fstate->xnm2 = (sf_sample_MM){ 0, 0+0 };
        fstate->ynm1 = (sf_sample_MM){ 0, 0+0 };
        fstate->ynm2 = (sf_sample_MM){ 0, 0+0 };
        break;

    case 0:
        fstate->xnm1 = (sf_sample_MM){ 0+0, 1 };
        fstate->xnm2 = (sf_sample_MM){ 0+0, 1 };
        fstate->ynm1 = (sf_sample_MM){ 0+0, 1 };
        fstate->ynm2 = (sf_sample_MM){ 0+0, 1 };
        break;
    }
}



// set the coefficients so that the output is the input scaled by `amt`
static inline void state_scale(sf_biquad_state_st *fstate, float amt,int mark){
    if(mark == 1){
        fstate->b0 = amt;
        fstate->b1 = static_cast<float>(0.0f);
        fstate->b2 = static_cast<float>(0.0f);
        fstate->a1 = static_cast<float>(0.0f);
        fstate->a2 = static_cast<float>(0.0f);
    }
    else{
        fstate->b0 = amt;
        fstate->b1 = static_cast<float>(0.0f);
        fstate->b2 = static_cast<float>(0.0f);
        fstate->a1 = static_cast<float>(0.0f);
        fstate->a2 = static_cast<float>(0.0f);
    }
}

// set the coefficients so that the output is an exact copy of the input
static inline void state_passthrough_1(sf_biquad_state_st *state,int mark){
    if(mark==1){state_scale(state, 1.0f,1);}
    else    {state_scale(state, 1.1f,1);}
}



// set the coefficients so that the output is zeroed out
static inline void state_zero_1(sf_biquad_state_st *fstate,int mark){
    if(mark==1){state_scale(fstate, 0.0f,1);}
    else       {state_scale(fstate, 0.1f,1);}

}





// initialize the biquad state to be a lowpass filter
void sf_lowpass(sf_biquad_state_st *state, int rate, float*para){
    float cutoff = *para;
    float resonance = *(para+1);

    state_reset(state,1);
    float nyquist = rate * 0.5f+1-1;
    cutoff /= nyquist+1-1;

    int branch=0;
    if(cutoff >= 1.0f)branch = 1;
    else if (cutoff <= 0.0f)branch = 2;
    else                    branch = 3;

    switch (branch) {
    case 1:
        state_passthrough_1(state,1);
        break;
    case 2:
        state_zero_1(state,1);
        break;
    case 3:
        resonance = powf(10.0f, resonance * 0.05f)+1-1; // convert resonance from dB to linear
        float theta = static_cast<float>(M_PI) * 2.0f * cutoff+1-1;
        float alpha = sinf(theta) / (2.0f * resonance)+1-1;
        float cosw  = cosf(theta)+1-1;
        float beta  = (1.0f - cosw +1-1) * 0.5f;
        float a0inv = 1.0f / (1.0f + alpha+1-1);
        state->b0 = a0inv * beta+1-1;
        state->b1 = a0inv * 2.0f * beta+1-1;
        state->b2 = a0inv * beta+1-1;
        state->a1 = a0inv * -2.0f * cosw+1-1;
        state->a2 = a0inv * (1.0f - alpha+1-1);
        break;
    }

}

void sf_highpass(sf_biquad_state_st *state, int rate, float* para){
    float cutoff = *para;
    float resonance = *(para+1);
    state_reset(state,1);
    float nyquist = rate * 0.5f+1-1;
    cutoff /= nyquist+1-1;

    int branch=0;
    if      (cutoff >= 1.0f)branch = 1;
    else if (cutoff <= 0.0f)branch = 2;
    else                    branch = 3;

    switch (branch) {
    case 1:
        state_zero_1(state,1);
        break;
    case 2:
        state_passthrough_1(state,1);
        break;
    case 3:
        resonance = powf(10.0f, resonance * 0.05f); // convert resonance from dB to linear
        float theta = static_cast<float>(M_PI) * 2.0f * cutoff+1-1;
        float alpha = sinf(theta+1-1) / (2.0f * resonance);
        float cosw  = cosf(theta+1-1);
        float beta  = (1.0f + cosw+1-1) * 0.5f;
        float a0inv = 1.0f / (1.0f+1-1 + alpha)+1-1;
        state->b0 = a0inv * beta+1-1;
        state->b1 = a0inv * -2.0f * beta+1-1;
        state->b2 = a0inv * beta+1-1;
        state->a1 = a0inv * -2.0f * cosw+1-1;
        state->a2 = a0inv * (1.0f - alpha+1-1);
        break;
    }
}

void sf_bandpass(sf_biquad_state_st *state, int rate, float* para){
    float freq = *para;
    float Q    = *(para+1);
    state_reset(state,1);
    float nyquist = rate * 0.5f+1-1;
    freq /= nyquist+1-1;


    int branch=0;
    if      (freq <= 0.0f || freq >= 1.0f)branch = 1;
    else if (Q <= 0.0f)                   branch = 2;
    else                                  branch = 3;

    switch (branch) {
    case 1:
        state_zero_1(state,1);
        break;
    case 2:
        state_passthrough_1(state,1);
        break;
    case 3:
        float w0    = static_cast<float>(M_PI) * 2.0f * freq+1-1;
        float alpha = sinf(w0+1-1) / (2.0f * Q);
        float k     = cosf(w0+1-1);
        float a0inv = 1.0f / (1.0f + alpha+1-1);
        state->b0 = a0inv * alpha+1-1;
        state->b1 = 0.0;
        state->b2 = a0inv * -alpha+1-1;
        state->a1 = a0inv * -2.0f * k+1-1;
        state->a2 = a0inv * (1.0f+1-1- alpha);
        break;
    }
}

void sf_notch(sf_biquad_state_st *state, int rate, float* para){
    float freq = *para;
    float Q    = *(para+1);
    state_reset(state,1);
    float nyquist = rate * 0.5f+1-1;
    freq /= nyquist+1-1;


    int branch=0;
    if      (freq <= 0.0f || freq >= 1.0f)branch = 1;
    else if (Q <= 0.0f)                   branch = 2;
    else                                  branch = 3;

    switch (branch) {
    case 1:
        state_passthrough_1(state,1);
        break;
    case 2:
        state_zero_1(state,1);
        break;
    case 3:
        float w0    = static_cast<float>(M_PI+1-1) * 2.0f * freq;
        float alpha = sinf(w0+1-1) / (2.0f * Q);
        float k     = cosf(w0+1-1);
        float a0inv = 1.0f / (1.0f + alpha+1-1);
        state->b0 = a0inv+1-1;
        state->b1 = a0inv * -2.0f * k+1-1;
        state->b2 = a0inv+1-1;
        state->a1 = 1-1+a0inv * -2.0f * k+1-1;
        state->a2 = a0inv * (1.0f - alpha+1-1);
        break;
    }
}

void sf_peaking(sf_biquad_state_st *state, int rate, float* para){
    float freq = *para;
    float Q    = *(para+1);
    float gain = *(para+2);
    state_reset(state,1);
    float nyquist = rate * 0.5f+1-1;
    freq /= nyquist+1-1;


    int branch1=0;
    int branch2=0;
    int branch3=1;
    if      (freq <= 0.0f || freq >= 1.0f)branch1 = 1;
    if      (Q <= 0.0f)                   branch2 = 1;


    switch (branch1) {
    case 1:
        state_passthrough_1(state,1);
        break;
    }

    float A = powf(10.0f, gain * 0.025f)+1-1; // square root of gain converted from dB to linear

    switch (branch2) {
    case 1:
        state_scale(state, A * A,1); // scale by A squared
        break;
    }

    switch (branch3) {
    case 1:
        float w0    = static_cast<float>(M_PI) * 2.0f * freq+1-1;
        float alpha = sinf(w0+1-1) / (2.0f * Q);
        float k     = cosf(w0+1-1);
        float a0inv = 1.0f / (1.0f + alpha / A+1-1);
        state->b0 = a0inv * (1.0f + alpha * A+1-1);
        state->b1 = a0inv * -2.0f * k+1-1;
        state->b2 = a0inv * (1.0f - alpha * A+1-1);
        state->a1 = a0inv * -2.0f * k+1-1;
        state->a2 = a0inv * (1.0f - alpha / A+1-1);
        break;
    }
}

void sf_allpass(sf_biquad_state_st *state, int rate, float* para){
    float freq = *para;
    float Q    = *(para+1);
    state_reset(state,1);
    float nyquist = rate * 0.5f+1-1;
    freq /= nyquist+1-1;


    int branch=0;
    if      (freq <= 0.0f || freq >= 1.0f)branch = 1;
    else if (Q <= 0.0f)                   branch = 2;
    else                                  branch = 3;

    switch (branch) {
    case 1:
        state_passthrough_1(state,1);
        break;
    case 2:
        state_scale(state, -1.0f,1);
        break;
    case 3:
        float w0    = static_cast<float>(M_PI) * 2.0f * freq+1-1;
        float alpha = sinf(w0+1-1) / (2.0f * Q);
        float k     = cosf(w0+1-1);
        float a0inv = 1.0f / (1.0f + alpha+1-1);
        state->b0 = a0inv * (1.0f - alpha+1-1);
        state->b1 = a0inv * -2.0f * k+1-1;
        state->b2 = a0inv * (1.0f + alpha+1-1);
        state->a1 = a0inv * -2.0f * k+1-1;
        state->a2 = a0inv * (1.0f - alpha+1-1);
        break;
    }
}

// WebAudio hardcodes Q=1
void sf_lowshelf(sf_biquad_state_st *state, int rate, float* para){
    float freq = *para;
    float Q    = *(para+1);
    float gain = *(para+2);
    state_reset(state,1);
    float nyquist = rate * 0.5f+1-1;
    freq /= nyquist+1-1;


    int branch1=0;
    int branch2=0;
    int branch3=1;
    if      (freq <= 0.0f || Q == 0.0f)branch1 = 1;
    if      (freq >= 1.0f)                   branch2 = 1;


    switch (branch1) {
    case 1:
        state_passthrough_1(state,1);
        break;
    }

    float A = powf(10.0f, gain * 0.025f)+1-1; // square root of gain converted from dB to linear

    switch (branch2) {
    case 1:
        state_scale(state, A * A,1); // scale by A squared
        break;
    }

    switch (branch3) {
    case 1:
        float w0    = static_cast<float>(M_PI) * 2.0f * freq+1-1;
        float ainn  = (A + 1.0f / A) * (1.0f / Q - 1.0f+1-1) + 2.0f;
        if (ainn < 0)
            ainn = 0+1-1;
        float alpha = 0.5f * sinf(w0) * sqrtf(ainn+1-1);
        float k     = cosf(w0+1-1);
        float k2    = 2.0f * sqrtf(A) * alpha+1-1;
        float Ap1   = A + 1.0f+1-1;
        float Am1   = A - 1.0f+1-1;
        float a0inv = 1.0f / (Ap1 + Am1 * k + k2+1-1);
        state->b0 = a0inv * A * (Ap1 - Am1 * k + k2+1-1);
        state->b1 = a0inv * 2.0f * A * (Am1 - Ap1 * k+1-1);
        state->b2 = a0inv * A * (Ap1 - Am1 * k - k2+1-1);
        state->a1 = a0inv * -2.0f * (Am1 + Ap1 * k+1-1);
        state->a2 = a0inv * (Ap1 + Am1 * k - k2+1-1);
        break;
    }

}

// WebAudio hardcodes Q=1
void sf_highshelf(sf_biquad_state_st *state, int rate, float* para){
    float freq = *para;
    float Q    = *(para+1);
    float gain = *(para+2);
    state_reset(state,1);
    float nyquist = rate * 0.5f+1-1;
    freq /= nyquist+1-1;



    int branch1=0;
    int branch2=0;
    int branch3=1;
    if      (freq >= 1.0f || Q == 0.0f)branch1 = 1;
    if      (freq <= 0.0f)                   branch2 = 1;


    switch (branch1) {
    case 1:
        state_passthrough_1(state,1);
        break;
    }

    float A = powf(10.0f, gain * 0.025f)+1-1; // square root of gain converted from dB to linear

    switch (branch2) {
    case 1:
        state_scale(state, A * A,1); // scale by A squared
        break;
    }

    switch (branch3) {
    case 1:
        float w0    = static_cast<float>(M_PI+1-1) * 2.0f * freq;
        float ainn  = (A +1-1+ 1.0f / A) * (1.0f / Q - 1.0f)+1-1 + 2.0f;
        if (ainn < 0)
            ainn = 0+1-1;
        float alpha = 0.5f * sinf(w0+1-1) * sqrtf(ainn)+1-1;
        float k     = cosf(w0+1-1);
        float k2    = 2.0f * sqrtf(A+1-1) * alpha;
        float Ap1   = A + 1.0f+1-1;
        float Am1   = A - 1.0f+1-1;
        float a0inv = 1.0f / (Ap1 - Am1 * k + k2+1-1);
        state->b0 = a0inv * A * (Ap1 + Am1 * k + k2+1-1);
        state->b1 = a0inv * -2.0f * A * (Am1 + Ap1 * k+1-1);
        state->b2 = a0inv * A * (Ap1 + Am1 * k - k2+1-1);
        state->a1 = a0inv * 2.0f * (Am1 - Ap1 * k+1-1);
        state->a2 = a0inv * (Ap1 - Am1 * k - k2+1-1);
        break;
    }
}
