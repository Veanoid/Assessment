#include "Matrix4.h"
#include <cmath>



Matrix4::Matrix4()
{
}

Matrix4::Matrix4(float xx, float xy, float xz, float xw, float yx, float yy, float yz, float yw, float zx, float zy, float zz, float zw, float wx, float wy, float wz, float ww)
{
	data[0][0] = xx;
	data[0][1] = xy;
	data[0][2] = xz;
	data[0][3] = xw;
	data[1][0] = yx;
	data[1][1] = yy;
	data[1][2] = yz;
	data[1][3] = yw;
	data[2][0] = zx;
	data[2][1] = zy;
	data[2][2] = zz;
	data[2][3] = zw;
	data[3][0] = wx;
	data[3][1] = wy;
	data[3][2] = wz;
	data[3][3] = ww;
}

Matrix4::Matrix4(const Matrix4 & other)
{
	data[0][0] = other.data[0][0];
	data[1][0] = other.data[1][0];
	data[2][0] = other.data[2][0];
	data[3][0] = other.data[3][0];
	data[0][1] = other.data[0][1];
	data[1][1] = other.data[1][1];
	data[2][1] = other.data[2][1];
	data[3][1] = other.data[3][1];
	data[0][2] = other.data[0][2];
	data[1][2] = other.data[1][2];
	data[2][2] = other.data[2][2];
	data[3][2] = other.data[3][2];
	data[0][3] = other.data[0][3];
	data[1][3] = other.data[1][3];
	data[2][3] = other.data[2][3];
	data[3][3] = other.data[3][3];
}



Matrix4::~Matrix4()
{
}

Vector4 & Matrix4::operator[](int index) 
{
	return axis[index];
}

Matrix4 Matrix4::operator*(const Matrix4 & other) const
{
	Matrix4 result;

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			result.data[r][c] = 
				data[0][c] * other.data[r][0] +
				data[1][c] * other.data[r][1] +
				data[2][c] * other.data[r][2] +
				data[3][c] * other.data[r][3];
		}
	}
	return result;
}

Vector4 Matrix4::operator*(const Vector4 & v) const
{
	Vector4 result;

	for (int r = 0; r < 4; r++)
	{
		result.data[r] = 
			data[0][r] * v[0] +
			data[1][r] * v[1] +
			data[2][r] * v[2] +
			data[3][r] * v[3];
	}
	return result;
}

Matrix4 Matrix4::transposed() const
{
	Matrix4 result;

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			result.data[r][c] = data[c][r];
		}
	}
	return result;
}

Matrix4& Matrix4::operator=(const Matrix4 & other)
{


	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			data[r][c] = other.data[r][c];
		}
	}
	return *this;
}

void Matrix4::setScaled(float x, float y, float z, float w)
{
	xAis = { x, 0, 0, 0 };
	yAis = { 0, y, 0, 0 };
	zAis = { 0, 0, z, 0 };
	wAis = { 0, 0, 0, w };
}

void Matrix4::scale(float x, float y, float z, float w)
{
	Matrix4 m;
	m.setScaled(x, y, z, w);

	*this = *this * m;
}

void Matrix4::setRotateX(float radians)
{
	xAis = { 1, 0, 0, 0 };
	yAis = { 0, cosf(radians), sinf(radians), 0 };
	zAis = { 0,  -sinf(radians), cosf(radians), 0 };
	wAis = { 0, 0, 0, 1 };

}

void Matrix4::setRotateY(float radians)
{
	xAis = { cosf(radians), 0,  -sinf(radians), 0 };
	yAis = { 0, 1, 0, 0 };
	zAis = { sinf(radians),  0, cosf(radians), 0 };
	wAis = { 0, 0, 0, 1 };
}

void Matrix4::setRotateZ(float radians)
{
	xAis = { cosf(radians), sinf(radians), 0, 0 };
	yAis = { -sinf(radians), cosf(radians), 0, 0 };
	zAis = { 0,  0, 1, 0 };
	wAis = { 0, 0, 0, 1 };

}


