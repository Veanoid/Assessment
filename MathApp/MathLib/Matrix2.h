#pragma once
#include "Vector2.h"
class Matrix2
{
public:
	Matrix2();
	Matrix2(float xx, float xy, float yx, float yy);
	Matrix2(const Matrix2& other);
	~Matrix2();
	

	union 
	{
		struct {
			Vector2 xAis;
			Vector2 yAis;
		};
		Vector2 axis[2];
		float data[2][2];
	};
	static const Matrix2 identity;

	

	const Vector2& operator [] (int index) const;
	Matrix2 operator * (const Matrix2& other) const;
	Vector2 operator * (const Vector2& v) const;
	Matrix2 transposed() const;
	Matrix2 operator = (const Matrix2& other);

	void setScaled(float x, float y);
	void scale(float x, float y);
	void setRotate(float radians);

};

