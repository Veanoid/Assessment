#include "Matrix3.h"
#include <cmath>



Matrix3::Matrix3()
{
}

Matrix3::Matrix3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz)
{
	 data[0][0] = xx;
	 data[0][1] = xy;
	 data[0][2] = xz;
	 data[1][0] = yx;
	 data[1][1] = yy;
	 data[1][2] = yz;
	 data[2][0] = zx;
	 data[2][1] = zy;
	 data[2][2] = zz;
}

Matrix3::Matrix3(const Matrix3 & other)
{
	data[0][0] = other.data[0][0];
	data[1][0] = other.data[1][0];
	data[2][0] = other.data[2][0];
	data[0][1] = other.data[0][1];
	data[1][1] = other.data[1][1];
	data[2][1] = other.data[2][1];
	data[0][2] = other.data[0][2];
	data[1][2] = other.data[1][2];
	data[2][2] = other.data[2][2];
}


Matrix3::~Matrix3()
{
}

Vector3 & Matrix3::operator[](int index)
{
	return axis[index];
}

Matrix3 Matrix3::operator*(const Matrix3 & other) const
{
	Matrix3 result;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			result.data[r][c] = 
				data[0][c] * other.data[r][0] +
				data[1][c] * other.data[r][1] +
				data[2][c] * other.data[r][2];
		}
	}
	return result;
}

Vector3 Matrix3::operator*(const Vector3 & v) const
{
	Vector3 result;

	for (int r = 0; r < 3; r++)
	{
		result.data[r] = data[0][r] * v[0] +
			data[1][r] * v[1] +
			data[2][r] * v[2];
	}
	return result;
}

Matrix3 Matrix3::transposed() const
{
	Matrix3 result;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			result.data[r][c] = data[c][r];
		}
	}
	return result;
}

Matrix3& Matrix3::operator=(const Matrix3 & other)
{
	
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			data[r][c] = other.data[r][c];
		}
	}

	return *this;

}

void Matrix3::setScaled(float x, float y, float z)
{
	xAis = { x, 0, 0 };
	yAis = { 0, y, 0 };
	zAis = { 0, 0, z };
}

void Matrix3::scale(float x, float y, float z)
{
	Matrix3 m;
	m.setScaled(x, y, z);

	*this = *this * m;
}



void Matrix3::setRotateX(float radians)
{
	xAis = { 1, 0, 0 };
	yAis = { 0, cosf(radians), sinf(radians) };
	zAis = { 0,  -sinf(radians), cosf(radians) };

}

void Matrix3::setRotateY(float radians)
{
	xAis = { cosf(radians), 0,  -sinf(radians) };
	yAis = { 0, 1, 0 };
	zAis = { sinf(radians),  0, cosf(radians) };

}

void Matrix3::setRotateZ(float radians)
{
	xAis = { cosf(radians), sinf(radians), 0 };
	yAis = { -sinf(radians), cosf(radians), 0 };
	zAis = { 0,  0, 1 };

}

void Matrix3::setEuler(float pitch, float yaw, float roll)
{
	Matrix3 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);

	*this = z * y * x;
}
