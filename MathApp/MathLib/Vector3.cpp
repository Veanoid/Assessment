#include "Vector3.h"

Vector3::Vector3()
{
}

Vector3::Vector3(float m_x, float m_y, float m_z)
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

float Vector3::operator[](int index) const
{
	return 0.0f;
}

Vector3::operator float*()
{
}

Vector3::operator const float*() const
{
}

float Vector3::magnitude() const
{
	return 0.0f;
}

float Vector3::distance(const Vector3 & other) const
{
	return 0.0f;
}

void Vector3::normalise()
{
}

Vector3 Vector3::cross(const Vector3 & other) const
{
	return Vector3();
}

float Vector3::angleBetween(const Vector3 & other) const
{
	return 0.0f;
}


Vector3::~Vector3()
{
}

Vector3 operator*(const float & scalar, const Vector3 & a_vec)
{
	return Vector3();

	Vector3 operator*(const float & scalar, const Vector3 & a_vec)
	{
		return Vector3();
	}
