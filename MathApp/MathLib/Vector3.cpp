#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
{
}

Vector3::Vector3(float m_x, float m_y, float m_z) : m_x(m_x), m_y(m_y), m_z(m_z)
{
}

Vector3 Vector3::operator+(const Vector3 & other)
{
	return Vector3(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
}

Vector3 Vector3::operator-(const Vector3 & other)
{
	return Vector3(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
}

Vector3 Vector3::operator*(float other)
{
	return Vector3(m_x * other, m_y * other, m_z * other);
}

Vector3 Vector3::operator=(const Vector3 & other)
{
	return Vector3(m_x = other.m_x, m_y = other.m_y, m_z = other.m_z);
}

float Vector3::dot(const Vector3 & other) const
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}
Vector3 operator*(const float & scalar, const Vector3 & a_vec)
{
	return Vector3(scalar * a_vec.m_x, scalar * a_vec.m_y, scalar * a_vec.m_z);
}

float Vector3::operator[](int index) const
{
	return data[index];
}

Vector3::operator float*() { return &m_x;}

Vector3::operator const float*() const { return &m_x; }

float Vector3::magnitude() const
{
	return sqrtf(m_x * m_x + m_y * m_y + m_z * m_z);
}

float Vector3::distance(const Vector3 & other) const
{
	 float diffX = m_x - other.m_x;
	 float diffY = m_y - other.m_y;
	 float diffZ = m_z - other.m_z;
	 return sqrtf(diffX * diffX + diffY * diffY + diffZ * diffZ);

}

void Vector3::normalise()
{
	float mag = magnitude(); 
	m_x /= mag;
	m_y	/= mag;
	m_z	/= mag;
}

Vector3 Vector3::normalised() const
{
	float mag = sqrtf(m_x * m_x + m_y * m_y + m_z * m_z);
	return { m_x / mag, m_y / mag, m_z / mag };
}

Vector3 Vector3::cross(const Vector3 & other) const
{
	return { m_y * other.m_z - m_z * other.m_y,
			m_z * other.m_x - m_x * other.m_z,
			m_x * other.m_y - m_y * other.m_x };
}

float Vector3::angleBetween(const Vector3 & other) const
{
	Vector3 a = normalised();
	Vector3 b = other.normalised();

	float d = a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;

	return acos(d);
}


Vector3::~Vector3()
{
}

