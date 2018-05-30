#include "Matrix2.h"
#include "Vector2.h"


Matrix2::Matrix2()
{
}


Matrix2::~Matrix2()
{
}

Matrix2::Matrix2(float xx, float xy, float yx, float yy)
{
}

Matrix2 Matrix2::operator+(const Matrix2 & other)
{
	return Matrix2(m_00 + other.m_00, m_10 + other.m_10,
					m_01 + other.m_01, m_11 + other.m_11);
}

Matrix2 Matrix2::operator*(const Matrix2 & other)
{
	return Matrix2(m_00 * other.m_00 + m_10 * other.m_01, m_00 * other.m_10 + m_10 * other.m_11,
					m_01 * other.m_00 + m_11 * other.m_01, m_01 * other.m_10 + m_11 * other.m_11);
}





