#include "Matrix2x2.h"
#include <math.h>
#include <stdio.h>
#include <string.h>


static float identityArray[4] = {1.0f, 0.0f, 0.0f, 1.0f};
Matrix2x2::Matrix2x2()
{
	Identity();
}

Matrix2x2::Matrix2x2(const Matrix2x2* m)
{
	CopyFrom(m);
}

Matrix2x2::~Matrix2x2()
{
}
void Matrix2x2::Identity()
{
	memcpy(&m_data, &identityArray, sizeof(identityArray));
}

void Matrix2x2::CopyFrom(const Matrix2x2* m)
{
	memcpy(&m_data, &m->m_data, sizeof(m_data));
}

void Matrix2x2::SetShear(const float x, const float y)
{
	Identity();
	m_data[0][1] = y;
	m_data[1][0] = x;
}

void Matrix2x2::SetScale(const float x, const float y)
{
	Identity();
	m_data[0][0] = x;
	m_data[1][1] = y;
}

void Matrix2x2::SetRotation(const float degrees)
{
	Identity();
	float r = degrees * M_PI / 180.0;
	m_data[0][0] = cos(r);
	m_data[0][1] = -sin(r);
	m_data[1][0] = sin(r);
	m_data[1][1] = cos(r);
}

void Matrix2x2::Mul(Vector2 * v) const
{
	float fx = m_data[0][0] * v->_x + m_data[0][1] * v->_y;
	float fy = m_data[1][0] * v->_x + m_data[1][1] * v->_y;
	
	v->_x = fx;
	v->_y = fy;
}