#include "fft.h"

const float pi = 3.14159265;

uint64_t	floor_exp2(float value)
{
	return uint64_t(std::exp2(std::floor(log2(value))));
}

uint64_t	ceil_exp2(float value)
{
	return uint64_t(std::exp2(std::ceil(log2(value))));
}

/**
 *	@brief	Compile-time checking of whether a value is integral or not
 *	@param	value	Value to be checked
 *	@return	Returns true if the value is an integer, false if it is not
 */
constexpr bool	integer(float value)
{
	return (uint64_t(value) == value);
}

class	__fft_private
{
private:	
	static void	__split(std::complex<float>* data, uint64_t N);
	static void	__data_fft(std::complex<float>* data, uint64_t N);	
	static void	__data_ifft(std::complex<float>* data, uint64_t N);

public:	
	friend std::vector<float>	fft(const std::vector<float>& time_samples);	
	friend std::vector<float>	ifft(const std::vector<float>& frequency_samples);
};

/**
 *	@brief	Splits an array into even terms (bottom half) and odd terms (top half)
 *	@param	data	An array of some type
 *	@param	N	The array size
 */

void	__fft_private::__split(std::complex<float>* data, uint64_t N)
{
	std::complex<float>* __temp = new std::complex<float>[N/2];
	for(uint64_t i = 0; i < N / 2; ++i)
		__temp[i] = data[2 * i + 1];
	for(uint64_t i = 0; i < N / 2; ++i)
		data[i] = data[2 * i];
	for(uint64_t i = 0; i < N / 2; ++i)
		data[i + N / 2] = __temp[i];
	delete[] __temp;
}

/**
 *	@brief	Data-level function to recursively compute the FFT of a data set
 *	@param	data	Data array
 *	@param	N	Array size
 *	@sa		fft
 *	@sa		data_ifft
 *	@sa		ifft
 */

void	__fft_private::__data_fft(std::complex<float>* data, uint64_t N)
{
	if (N > 1)
	{
		if (N > 2) __fft_private::__split(data, N);
		__data_fft(data, N/2);
		__data_fft(data + N/2, N/2);
		for (uint64_t n = 0; n < N/2; ++n)
		{
			std::complex<float>	even = data[n];
			std::complex<float>	odd = data[n + N/2];
			std::complex<float>	twiddle = exp(std::complex<float>(0, float(-2 * pi) * n / N));
			data[n] = even + (twiddle * odd);
			data[n + N/2] = even - (twiddle * odd);
		}
	}
}
/**
 *	@brief	Data-level function to recursively compute the iFFT of a data set
 *	@param	data	Data array
 *	@param	N	Array size
 *	@sa		fft
 *	@sa		data_fft
 *	@sa		ifft
 */

void	__fft_private::__data_ifft(std::complex<float>* data, uint64_t N)
{
	if (N >= 2)
	{
		__split(data, N);
		__data_ifft(data, N/2);
		__data_ifft(data + N/2, N/2);
		for (uint64_t k = 0; k < N/2; ++k)
		{
			std::complex<float>	even = data[k];
			std::complex<float>	odd = data[k + N/2];
			std::complex<float>	twiddle = exp(std::complex<float>(0, float(2 * pi) * k / N));
			data[k] = float(0.5) * even + twiddle * odd;
			data[k + N/2] = float(0.5) * even - twiddle * odd;
		}
	}
}

/**
 *	@brief	Interface for FFT
 *	@param	time_samples	Array of time-domain sample data
 *	@return	An equally-sized array of frequency-domain sample data
 *	@sa		data_fft
 *	@sa		data_ifft
 *	@sa		ifft
 */

std::vector<float>	fft(const std::vector<float>& time_samples)
{
	uint64_t	N = floor_exp2(time_samples.size());
	if (!integer(log2(N))) throw std::invalid_argument("N must be a power of 2");
	std::vector<std::complex<float>>	frequency_complex;
	for (uint64_t i = 0; i < N; ++i)
		frequency_complex.emplace_back(time_samples.at(i));
	__fft_private::__data_fft(frequency_complex.data(), N);
	std::vector<float>	frequency_samples;
	for (uint64_t i = 0; i < N; ++i)
		frequency_samples.emplace_back(std::abs(frequency_complex.at(i)));
	return frequency_samples;
}
/**
 *	@brief	Interface for iFFT
 *	@param	frequency_samples	Array of frequency-domain sample data
 *	@return	An equally-sized array of time-domain sample data
 *	@sa		data_ifft
 *	@sa		data_fft
 *	@sa		fft
 */

std::vector<float>	ifft(const std::vector<float>& frequency_samples)
{
	uint64_t	N = floor_exp2(frequency_samples.size());
	if (!integer(log2(N))) throw std::invalid_argument("N must be a power of 2");
	std::vector<std::complex<float>>	time_complex;
	for (uint64_t i = 0; i < N; ++i)
		time_complex.emplace_back(frequency_samples.at(i));
	__fft_private::__data_ifft(time_complex.data(), N);
	std::vector<float>	time_samples;
	for (uint64_t i = 0; i < N; ++i)
		time_samples.emplace_back(std::abs(time_complex.at(i)));
	return time_samples;
}
