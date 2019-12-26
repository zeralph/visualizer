#pragma once
#include"Point.h"

class Line
{
public:
	Line(){}
	~Line(){}
public:
	static void Draw(Point* p1, Point* p2, BufferData* bufferData);
};