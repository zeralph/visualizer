#pragma once
#include <utility>

typedef unsigned int uint;

struct BufferData
{
	uint _width;
	uint _height;
	uint _size;
	uint* _currentBuffer;
	uint* _backBuffer;
	void swapBuffers() { std::swap(_currentBuffer, _backBuffer); }
};