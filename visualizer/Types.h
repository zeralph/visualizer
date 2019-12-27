#pragma once
#include <utility>
#include <algorithm>

#define WIDTH      480
#define HEIGHT     320
#define M_PI       3.14159265358979323846

typedef unsigned int uint;

template <typename T> T CLAMP(const T& value, const T& low, const T& high)
{
	return value < low ? low : (value > high ? high : value);
}

class Color;

struct BufferData
{
	uint _width;
	uint _height;
	uint _size;
	Color* _currentBuffer;
	Color* _backBuffer;
	uint* _finalBuffer;
	void swapBuffers() { std::swap(_currentBuffer, _backBuffer); }

};

