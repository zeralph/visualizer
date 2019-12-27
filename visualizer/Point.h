#pragma once
#include "Types.h"
#include "Color.h"

class Point
{
public:
	Point() { _x = 0; _y = 0; _c = Color(); };

	Point(int x, int y, Color color):
	_x(x),
	_y(y),
	_c(color)
	{
	};
	~Point() {};
public:
	int _x;
	int _y;
	Color _c;
};