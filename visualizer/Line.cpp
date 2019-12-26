#include "Line.h"
#include <utility>

void Line::Draw(Point* p1, Point* p2, BufferData* bufferData)
{
	float x1 = p1->_x;
	float y1 = p1->_y;
	float x2 = p2->_x;
	float y2 = p2->_y;
	Color color = Color(255, 255, 255);
	Color* buffer = bufferData->_currentBuffer;
	const bool steep = abs(y2 - y1) > abs(x2 - x1);
	if (steep)
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
	}

	if (x1 > x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const float dx = x2 - x1;
	const float dy = abs(y2 - y1);
	float scaleX = 1.0;
	float scaleY = 1.0;
	float error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y = (int)y1;

	const int maxX = (int)x2;
	for (int x = (int)x1; x < maxX; x++)
	{
		//if (x >= 0 && x < bufferData->width && y >= 0 && y < bufferData->height)
		{
			if (steep)
			{
				uint k = x * bufferData->_width + y;
				if (k < bufferData->_size)
				{
					buffer[k] = color;
				}
			}
			else
			{
				uint k = y * bufferData->_width + x;
				if (k < bufferData->_size)
				{
					buffer[k] = color;
				}
			}
		}
		error -= dy;
		if (error < 0)
		{
			y += ystep;
			error += dx;
		}
	}
}