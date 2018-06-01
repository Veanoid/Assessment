#include "Vector4.h"
#include <math.h>



Vector4::Vector4()
{
}

Vector4::Vector4(float m_x, float m_y, float m_z, float m_w) : m_x(m_x), m_y(m_y), m_z(m_z), m_w(m_w)
{
}

Vector4 Vector4::operator+(const Vector4 & other)
{
	return Vector4(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z, m_w + other.m_w);
}

Vector4 Vector4::operator-(const Vector4 & other)
{
	return Vector4(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z, m_w - other.m_w);
}

Vector4 Vector4::operator*(float other)
{
	return Vector4(m_x * other, m_y * other, m_z * other, m_w * other);
}

Vector4& Vector4::operator=(const Vector4 & other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
	m_w = other.m_w;

	return *this;
}

float Vector4::dot(const Vector4 & other) const
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z + m_w * other.m_w;
}

Vector4 operator*(const float & scalar, const Vector4 & a_vec)
{
	return Vector4(scalar * a_vec.m_x, scalar * a_vec.m_y, scalar * a_vec.m_z, scalar * a_vec.m_w);
}

float Vector4::operator[](int index) const
{
	return data[index];
}

Vector4::operator float*() { return &m_x; }


Vector4::operator const float*() const { return &m_x; }


float Vector4::magnitude() const
{
	return sqrtf(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
}

float Vector4::distance(const Vector4 & other) const
{
	float diffX = m_x - other.m_x;
	float diffY = m_y - other.m_y;
	float diffZ = m_z - other.m_z;
	float diffW = m_w - other.m_w;
	return sqrtf(diffX * diffX + diffY * diffY + diffZ * diffZ + diffW * diffW);
}

void Vector4::normalise()
{
	float mag = magnitude();
	m_x /= mag;
	m_y /= mag;
	m_z /= mag;
	m_w /= mag;
}

Vector4 Vector4::normalised() const
{
	float mag = sqrtf(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
	return { m_x / mag, m_y / mag, m_z / mag, m_w / mag };
}

Vector4 Vector4::cross(const Vector4 & other) const
{
	return { m_y * other.m_z - m_z * other.m_y,
			m_z * other.m_x - m_x * other.m_z,
			m_x * other.m_y - m_y * other.m_x,
			0};
}

float Vector4::angleBetween(const Vector4 & other) const
{
	Vector4 a = normalised();
	Vector4 b = other.normalised();

	float d = a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;

	return acosf(d);
}


Vector4::~Vector4()
{
}
