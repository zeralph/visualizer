#include "Filter.h"

void Filter::ApplyBlur(Color* buffer, uint bufferWidth, uint bufferHeight)
{
	float matrix[9] = { 0, 1, 0, 1, 1, 1, 0, 1, 0 };
	ConvolutionMatrix BlurFilter = ConvolutionMatrix(3, 3, (float*)matrix, (1.0f / 9.0f));
	for (int i = 0; i < bufferWidth; i++)
	{
		for (int j = 0; j < bufferHeight; j++)
		{
			ApplyConvolutionMatrixOnPixel(&BlurFilter, buffer, i, j, bufferWidth, bufferHeight);
		}
	}
}

void Filter::ApplyGaussianBlur(Color* buffer, uint bufferWidth, uint bufferHeight)
{
	float matrix[9] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
	ConvolutionMatrix BlurFilter = ConvolutionMatrix(3, 3, (float*)matrix, (1.0f / 16.0f));
	for (int i = 0; i < bufferWidth; i++)
	{
		for (int j = 0; j < bufferHeight; j++)
		{
			ApplyConvolutionMatrixOnPixel(&BlurFilter, buffer, i, j, bufferWidth, bufferHeight);
		}
	}
}

void Filter::ApplyNothing(Color* buffer, uint bufferWidth, uint bufferHeight)
{
	float matrix[9] = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };
	ConvolutionMatrix BlurFilter = ConvolutionMatrix(3, 3, (float*)matrix, 1.0f);
	for (int i = 0; i < bufferWidth; i++)
	{
		for (int j = 0; j < bufferHeight; j++)
		{
			ApplyConvolutionMatrixOnPixel(&BlurFilter, buffer, i, j, bufferWidth, bufferHeight);
		}
	}
}

void Filter::ApplyConvolutionMatrixOnPixel(const ConvolutionMatrix* matrix, Color* buffer, uint x, uint y, uint bufferWidth, uint bufferHeight)
{
	uint stepX = matrix->_width / 2;
	uint stepY = matrix->_height / 2;
	Color t;
	float r = 0;
	float g = 0;
	float b = 0;
	int dest = 0;
	for (int i = 0; i < matrix->_width; i++)
	{
		for (int j = 0; j < matrix->_height; j++)
		{
			uint kx = x - stepX + i;
			uint ky = y - stepY + j;
			if (GetPixel(buffer, kx, ky, bufferWidth, bufferHeight, &t))
			{
				r += (float)t._r * matrix->_matrix[i + j * matrix->_width];
				g += (float)t._g * matrix->_matrix[i + j * matrix->_width];
				b += (float)t._b * matrix->_matrix[i + j * matrix->_width];
			}
		}
	}
	r = r * matrix->_divider;
	g = g * matrix->_divider;
	b = b * matrix->_divider;
	dest = x + y * bufferWidth;
	buffer[dest]._r = (uint)r;
	buffer[dest]._g = (uint)g;
	buffer[dest]._b = (uint)b;
}

bool Filter::GetPixel(Color* buffer, uint x, uint y, uint bufferWidth, uint bufferHeight, Color* outColor)
{
	if (x > 0 && y > 0 && x < bufferWidth && y < bufferHeight)
	{
		outColor->Set(&buffer[x + y * bufferWidth]);
		return true;
	}
	return false;
}

