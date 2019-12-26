#pragma once
#include "Types.h"

class Color
{
public:
	Color() :
		_r(0),
		_g(0),
		_b(0),
		_intValue(0)
	{};
	Color(uint r, uint g, uint b) :
		_r(r),
		_g(g),
		_b(b)
	{
		_intValue = (((uint)r) << 16) | (((uint)g) << 8) | ((uint)b);
	};
	~Color() {};
public:
	uint _r;
	uint _g;
	uint _b;
	uint _intValue;

public:
	static Color black;
};