#pragma once

class Vector2
{
public:
	Vector2():
	_x(0),
	_y(0)
	{

	};
	Vector2(float x, float y):
	_x(x),
	_y(y)
	{

	};

public:
	float _x;
	float _y;
};