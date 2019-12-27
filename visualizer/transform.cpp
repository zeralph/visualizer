#include "Transform.h"
#include "Matrix2x2.h"

void Transform::Translate(Color* buffer, uint bufferWidth, uint bufferheight, int deltaX, int deltaY)
{
	int iSrc = 0;
	int jSrc = 0;
	int dest = 0;
	Color* c = &Color::black;
	for (int iDst = 0; iDst < bufferWidth; iDst++)
	{
		for (int jDst = 0; jDst < bufferheight; jDst++)
		{
			iSrc = iDst + deltaX;
			jSrc = jDst + deltaY;
			if (GetPixel(buffer, iSrc, jSrc, bufferWidth, bufferheight, c))
			{
				c = &buffer[iDst + jDst * bufferWidth];
			}
			else
			{
				c = &Color::black;
			}
			dest = iDst + jDst * bufferWidth;
			tBuffer[dest]._r = c->_r;
			tBuffer[dest]._g = c->_g;
			tBuffer[dest]._b = c->_b;
		}
	}
	memcpy(&buffer, &tBuffer, sizeof(&tBuffer));
	//buffer = tBuffer;
}

void Transform::Rotate(Color* buffer, uint bufferWidth, uint bufferheight, float angle, int xOrigin, int yOrigin)
{
	int iSrc = 0;
	int jSrc = 0;
	int dest = 0;
	Color* c = &Color::black;
	Vector2 v = Vector2();
	Matrix2x2 m = Matrix2x2();
	m.SetRotation(angle);
	for (int iDst = 0; iDst < bufferWidth; iDst++)
	{
		for (int jDst = 0; jDst < bufferheight; jDst++)
		{
			v._x = (float)iDst - (float)xOrigin;
			v._y = (float)jDst - (float)yOrigin;
			m.Mul(&v);
			iSrc = (int)(v._x + (float)xOrigin);
			jSrc = (int)(v._y + (float)yOrigin);
			if (GetPixel(buffer, iSrc, jSrc, bufferWidth, bufferheight, c))
			{
				c = &buffer[iDst + jDst * bufferWidth];
			}
			else
			{
				c = &Color::black;
			}
			dest = iDst + jDst * bufferWidth;
			tBuffer[dest]._r = c->_r;
			tBuffer[dest]._g = c->_g;
			tBuffer[dest]._b = c->_b;
		}
	}
	memcpy(&buffer, &tBuffer, sizeof(&tBuffer));
	//buffer = tBuffer;
}

void Transform::Skew(Color* buffer, uint bufferWidth, uint bufferheight, int deltaX, int deltaY)
{

}


bool Transform::GetPixel(Color* buffer, uint x, uint y, uint bufferWidth, uint bufferHeight, Color* outColor)
{
	if (x > 0 && y > 0 && x < bufferWidth && y < bufferHeight)
	{
		outColor->Set(&buffer[x + y * bufferWidth]);
		return true;
	}
	return false;
}


Color Transform::tBuffer[WIDTH * HEIGHT * sizeof(Color)];