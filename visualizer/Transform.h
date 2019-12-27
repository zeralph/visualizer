#pragma once
#include "Types.h"
#include "Color.h"

class Transform
{
public:

	static void Translate(Color* buffer, uint bufferWidth, uint bufferheight, int deltaX, int deltaY);
	static void Rotate(Color* buffer, uint bufferWidth, uint bufferheight, float angle, int xOrigin, int yOrigin);
	static void Skew(Color* buffer, uint bufferWidth, uint bufferheight, int deltaX, int deltaY);
private :
	inline static bool GetPixel(Color* buffer, uint x, uint y, uint bufferWidth, uint bufferHeight, Color* outColor);
private:
	static Color tBuffer[];
};