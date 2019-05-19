#ifndef _FFT_H_
#define _FFT_H_

#include	<complex>
#include	<vector>

uint64_t	floor_exp2(float value);
uint64_t	ceil_exp2(float value);

/**
 *	@brief	Interface for FFT
 *	@param	time_samples	Array of time-domain sample data
 *	@return	An equally-sized array of frequency-domain sample data
 *	@sa		data_fft
 *	@sa		data_ifft
 *	@sa		ifft
 */

std::vector<float>	fft(const std::vector<float>& time_samples);

/**
 *	@brief	Interface for iFFT
 *	@param	frequency_samples	Array of frequency-domain sample data
 *	@return	An equally-sized array of time-domain sample data
 *	@sa		data_ifft
 *	@sa		data_fft
 *	@sa		fft
 */

std::vector<float>	ifft(const std::vector<float>& frequency_samples);

#endif