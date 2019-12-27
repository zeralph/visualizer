#pragma once
#include "Types.h"
#include "Color.h"

class ConvolutionMatrix
{
	
public:
	ConvolutionMatrix(uint w, uint h, float* m, float d):
	_width(w),
	_height(h),
	_matrix(m),
	_divider(d)
	{

	}
	~ConvolutionMatrix()
	{
	}
public:
	uint _width;
	uint _height;
	float* _matrix;
	float _divider;
};

class Filter
{
public :
	static void ApplyNothing(Color* buffer, uint bufferWidth, uint bufferHeight);
	static void ApplyBlur(Color* buffer, uint bufferWidth, uint bufferHeight);
	static void ApplyGaussianBlur(Color* buffer, uint bufferWidth, uint bufferHeight);

private:
	inline static void ApplyConvolutionMatrixOnPixel(const ConvolutionMatrix* matrix, Color* buffer, uint x, uint y, uint bufferWidth, uint bufferHeight);
	inline static bool GetPixel(Color* buffer, uint x, uint y, uint bufferWidth, uint bufferHeight, Color* outColor);

};