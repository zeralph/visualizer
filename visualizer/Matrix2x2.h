#pragma once
#include "Types.h"
#include "Vector2.h"

class Matrix2x2
{
public:
	Matrix2x2();
	Matrix2x2(const Matrix2x2* m);
	~Matrix2x2();

	void Identity();
	void CopyFrom(const Matrix2x2* m);
	void Mul(Vector2 * v) const;
	void SetScale(const float x, const float y);
	void SetRotation(const float degrees);
	void SetShear(const float x, const float y);

private:
	float m_data[2][2];
};

