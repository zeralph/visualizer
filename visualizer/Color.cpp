#include "Color.h"

void Color::Merge(const Color c, float factor)
{
	_r = _r * factor + c._r * (1.0f - factor);
	_g = _g * factor + c._g * (1.0f - factor);
	_b = _b * factor + c._b * (1.0f - factor);
}

void Color::Add(const Color c, float factor)
{
	_r = CLAMP((uint)((float)_r + (float)c._r * factor), (uint)0, (uint)255);
	_g = CLAMP((uint)((float)_g + (float)c._g * factor), (uint)0, (uint)255);
	_b = CLAMP((uint)((float)_b + (float)c._b * factor), (uint)0, (uint)255);
}

/******************************/
Color Color::black = Color(0, 0, 0);