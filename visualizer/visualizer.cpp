// visualizer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <windows.h>
#include <iostream>
#include "miniFB\include\MiniFB.h"
#include "Types.h"
#include "Line.h"
#include "Point.h"

#define RGB_TO_UINT(r, g, b)    (((uint32_t) r) << 16) | (((uint32_t) g) << 8) | ((uint32_t) b)

#define FADE 0.99;
#define WIDTH      800
#define HEIGHT     600
static unsigned int g_buffer0[WIDTH * HEIGHT];
static unsigned int g_buffer1[WIDTH * HEIGHT];

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void uintToRgb(uint c, uint &r, uint &g, uint &b)
{
	r = (c & 0xFF0000) >> 16;
	g = (c & 0x00FF00) >> 8;
	b = (c & 0x0000FF);
}

int main()
{
	int noise, carry, seed = 0xbeef;
	Point p1, p2;
	int data[100];

	BufferData _bufferData;
	_bufferData._currentBuffer = g_buffer0;
	_bufferData._backBuffer = g_buffer1;
	_bufferData._height = HEIGHT;
	_bufferData._width = WIDTH;
	_bufferData._size = WIDTH * HEIGHT;

	struct Window *window = mfb_open_ex("Noise Test", WIDTH, HEIGHT, WF_RESIZABLE);
	if (!window)
		return 0;

	for (;;)
	{
		int         i;
		UpdateState state;

		_bufferData.swapBuffers();

		for (i = 0; i < _bufferData._size; i++)
		{
			_bufferData._currentBuffer[i] = 0;
		}

		for (i = 0; i < 100; ++i)
		{
			data[i] = rand() % 100 + 1 - 50 + HEIGHT / 2;
			//data[i] = i % 2 * 100;
		}
		int step = (int)((double)WIDTH / 100.0);
		for (i = 0; i < 99; ++i)
		{
			p1._x = step * i;
			p1._y = data[i];
			p2._x = step * (i+1);
			p2._y = data[i + 1];
			Line::Draw(&p1, &p2, &_bufferData);
		}
		//Sleep(33);

		//merge buffers
		for (i = 0; i < _bufferData._size - WIDTH; i++)
		{
			uint r, g, b;
			uintToRgb(_bufferData._backBuffer[i+WIDTH], r, g, b);
			r *= FADE;
			g *= FADE;
			b *= FADE;

			_bufferData._currentBuffer[i] += RGB_TO_UINT(r, g, b);
		}

		state = mfb_update(window, _bufferData._currentBuffer);
		if (state != STATE_OK) {
			window = 0x0;
			break;
		}
	}

	return 0;
}

