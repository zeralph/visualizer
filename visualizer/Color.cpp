#include "Color.h"

void Color::Merge(const Color c, float factor)
{
	_r = _r * factor + c._r * (1.0f - factor);
	_g = _g * factor + c._g * (1.0f - factor);
	_b = _b * factor + c._b * (1.0f - factor);
}

void Color::Add(const Color c, float factor)
{
	_r += c._r * factor;
	_g += c._g * factor;
	_b += c._b * factor;
}

/******************************/
Color Color::black = Color(0, 0, 0);