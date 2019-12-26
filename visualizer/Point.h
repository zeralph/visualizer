#pragma once
#include "Types.h"

class Point
{
public:
	Point() { _x = 0; _y = 0; _c = 0; };

	Point(int x, int y, uint color):
	_x(x),
	_y(y),
	_c(color)
	{
	};
	~Point() {};
public:
	int _x;
	int _y;
	uint _c;
};