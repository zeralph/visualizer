// visualizer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <windows.h>
#include <iostream>
#include "miniFB\include\MiniFB.h"
#include "Types.h"
#include "Line.h"
#include "Point.h"
#include "Color.h"
#include "Filter.h"
#include "Transform.h" 

#define RGB_TO_UINT(r, g, b)    (((uint32_t) r) << 16) | (((uint32_t) g) << 8) | ((uint32_t) b)

#define FADE 0.99;


static Color g_buffer0[WIDTH * HEIGHT * sizeof(Color)];
static Color g_buffer1[WIDTH * HEIGHT * sizeof(Color)];
static uint g_finalBuffer[WIDTH * HEIGHT];
static Color LineColor[100];
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
	int noise, carry, seed = 0xbeef;
	Point p1, p2;
	int data[100];

	BufferData _bufferData;
	_bufferData._currentBuffer = g_buffer0;
	_bufferData._backBuffer = g_buffer1;
	_bufferData._finalBuffer = g_finalBuffer;
	_bufferData._height = HEIGHT;
	_bufferData._width = WIDTH;
	_bufferData._size = WIDTH * HEIGHT;

	struct Window *window = mfb_open_ex("Noise Test", WIDTH, HEIGHT, WF_RESIZABLE);
	if (!window)
		return 0;

	for (int i = 0; i < 100; i++)
	{
		LineColor[i].Rand();
	}

	for (;;)
	{
		int         i;
		UpdateState state;

		_bufferData.swapBuffers();

		for (i = 0; i < _bufferData._size; i++)
		{
			_bufferData._currentBuffer[i] = Color::black;
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
			p1._c = LineColor[i];
			p2._x = step * (i+1);
			p2._y = data[i + 1];
			p2._c = LineColor[i+1];
			Line::Draw(&p1, &p2, &_bufferData);
		}
		//Sleep(1000);

		//merge buffers
		//Filter::ApplyNothing(_bufferData._backBuffer, _bufferData._width, _bufferData._height);
		//Transform::Translate(_bufferData._backBuffer, _bufferData._width, _bufferData._height, 10, 10);
		Transform::Rotate(_bufferData._backBuffer, _bufferData._width, _bufferData._height, -5.0f, WIDTH/2, HEIGHT/2);
//		Filter::ApplyGaussianBlur(_bufferData._backBuffer, _bufferData._width, _bufferData._height);
		Color c;
		for (i = 0; i < _bufferData._size; i++)
		{
			_bufferData._currentBuffer[i].Add(_bufferData._backBuffer[i], 0.9f);
			_bufferData._finalBuffer[i] = _bufferData._currentBuffer[i].toUint();
		}

		state = mfb_update(window, _bufferData._finalBuffer);
		if (state != STATE_OK) {
			window = 0x0;
			break;
		}
	}

	return 0;
}

