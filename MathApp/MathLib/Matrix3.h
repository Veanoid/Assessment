#pragma once
#include "Vector3.h"
class Matrix3
{
public:
	Matrix3();
	Matrix3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz);
	Matrix3(const Matrix3& other);
	~Matrix3();

	union 
	{
		struct {
			Vector3 xAis;
			Vector3 yAis;
			Vector3 zAis;
		};
		Vector3 axis[3];
		float data[3][3];
	};
	static const Matrix3 identity;

	

	Vector3& operator [] (int index);
	Matrix3 operator * (const Matrix3& other) const;
	Vector3 operator * (const Vector3& v) const;
	Matrix3 transposed() const;
	Matrix3 operator = (const Matrix3& other);

	void setScaled(float x, float y, float z);
	void scale(float x, float y, float z);
	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);
	void setEuler(float pitch, float yaw, float roll);

};

