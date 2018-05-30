#include "Vector2.h"
#include <math.h>



Vector2::Vector2(): m_x(0), m_y(0)
{
}

Vector2::Vector2(float x, float y) : m_x(x), m_y(y)
{
}


Vector2 Vector2::operator+(const Vector2 & other)
{
	return Vector2(m_x + other.m_x, m_y + other.m_y);
}

Vector2 Vector2::operator-(const Vector2 & other)
{
	return Vector2(m_x - other.m_x, m_y - other.m_y);
}

Vector2 Vector2::operator*(float other)
{
	return Vector2(m_x * other, m_y * other);
}

Vector2 Vector2::operator=(const Vector2 & other)
{
	return Vector2(m_x = other.m_x, m_y = other.m_y);
}

float Vector2::dot(const Vector2 & other)
{
	return m_x * other.m_x + m_y * other.m_y;
}

Vector2 Vector2::getPrependiularRH() const
{
	return { -m_y, m_x };
}

Vector2 Vector2::getPrependiularLH() const
{
	return { m_y, -m_x};
}

float Vector2::operator[](int index) const
{
	return data[index];
}

Vector2::operator float*() { return &m_x; }

Vector2::operator const float*() const { return &m_x; }

float Vector2::magnitude() const
{
	return sqrt(m_x *m_x + m_y * m_y);
}

float Vector2::distance(const Vector2 & other) const
{
	float diffX = m_x - other.m_x;
	float diffY = m_y - other.m_y;
	return sqrt(diffX * diffX + diffY * diffY);
}

void Vector2::normalise()
{
	float mag = sqrt(m_x * m_x + m_y * m_y);
	m_x /= mag;
	m_y /= mag;
}

Vector2::~Vector2()
{
}

Vector2  operator*(const float scalar, const Vector2 a_vec)
{
	return Vector2(scalar * a_vec.m_x, scalar *  a_vec.m_y);
}
