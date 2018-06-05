#pragma once
#include "Vector4.h"
class Matrix4
{
public:
	Matrix4();
	Matrix4(float xx, float xy, float xz, float xw, float yx, float yy, float yz, float yw, float zx, float zy, float zz, float zw, float wx, float wy, float wz, float ww);
	Matrix4(const Matrix4& other);
	~Matrix4();

	union
	{
		struct {
			Vector4 xAis;
			Vector4 yAis;
			Vector4 zAis;
			Vector4 wAis;
		};
		Vector4 axis[4];
		float data[4][4];
	};
	static const Matrix4 identity;



	Vector4& operator [] (int index);
	Matrix4 operator * (const Matrix4& other) const;
	Vector4 operator * (const Vector4& v) const;
	Matrix4 transposed() const;
	Matrix4& operator = (const Matrix4& other);

	void setScaled(float x, float y, float z, float w);
	void scale(float x, float y, float z, float w);
	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);
};

