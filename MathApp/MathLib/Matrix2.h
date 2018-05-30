#pragma once
#include "Vector2.h"
class Matrix2
{
public:
	Matrix2();
	~Matrix2();

	union 
	{
		struct {
			float m_00, m_01, m_10, m_11;
		};
		float m[2][2];
	};
	Matrix2(float xx, float xy, float yx, float yy);

	Matrix2 operator +(const Matrix2& other);
	Matrix2 operator *(const Matrix2& other);
	
};

