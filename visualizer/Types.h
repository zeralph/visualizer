#pragma once
#include <utility>

typedef unsigned int uint;

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