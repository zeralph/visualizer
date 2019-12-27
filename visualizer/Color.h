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
	inline uint toUint() { _intValue = (((uint)_r) << 16) | (((uint)_g) << 8) | ((uint)_b); return _intValue; }
	void Merge(const Color c, float factor);
	void Add(const Color c, float factor);
	inline void Set(const Color* c) { _r = c->_r; _g = c->_g; _b = c->_b; }
	void Rand() {_r = rand() % 255 + 1; _g = rand() % 255 + 1; _b = rand() % 255 + 1;}
public:
	uint _r;
	uint _g;
	uint _b;
	uint _intValue;

public:
	static Color black;
};