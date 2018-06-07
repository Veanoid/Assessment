#include "Matrix2.h"
#include <cmath>


Matrix2::Matrix2()
{
}

Matrix2::Matrix2(float xx, float xy, float yx, float yy)
{
	data[0][0] = xx;
	data[1][0] = xy;
	data[0][1] = yx;
	data[1][1] = yy;
}


Matrix2::Matrix2(const Matrix2 & other)
{
	data[0][0] = other.data[0][0];
	data[1][0] = other.data[1][0];
	data[0][1] = other.data[0][1];
	data[1][1] = other.data[1][1];
}
Matrix2::~Matrix2()
{
}





const Matrix2 Matrix2::identity = Matrix2(1, 0, 0, 1);



const Vector2 & Matrix2::operator[](int index) const
{
	return axis[index];
}

Matrix2 Matrix2::operator*(const Matrix2 & other) const
{
	Matrix2 result;

	for (int r = 0; r < 2; r++)
	{
		for  (int c = 0; c < 2;  c++)
		{
			result.data[c][r] = data[c][0] * other.data[0][r] +
								data[c][1] * other.data[1][r];
		}
	}
	return result;
}

Vector2 Matrix2::operator*(const Vector2 & v) const
{
	Vector2 result;

	for (int r = 0; r < 2; r++)
	{
		result.data[r] = data[r][0] * v[0] +
						data[r][1] * v[1];
	}
	return result;
}

Matrix2 Matrix2::transposed() const
{
	Matrix2 result;

	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			result.data[r][c] = data[c][r];
		}
	}
	return result;
}

Matrix2& Matrix2::operator=(const Matrix2 & other)
{
	data[0][0] = other.data[0][0];
	data[1][0] = other.data[1][0];
	data[0][1] = other.data[0][1];
	data[1][1] = other.data[1][1];
	return *this;
};

void Matrix2::setScaled(float x, float y)
{
	xAis = { x, 0 };
	yAis = { 0, y };
}

void Matrix2::scale(float x, float y)
{
	Matrix2 m;
	m.setScaled(x, y);

	*this = *this * m;
}

void Matrix2::setRotate(float radians)
{
	xAis = { cosf(radians), -sinf(radians) };
	yAis = { sinf(radians), cosf(radians) };
	
}






