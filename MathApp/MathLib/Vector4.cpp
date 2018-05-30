#include "Vector4.h"



Vector4::Vector4()
{
}

Vector4::Vector4(float m_x, float m_y, float m_z, float m_w)
{
}

Vector4 Vector4::operator+(const Vector4 & other)
{
	return Vector4();
}

Vector4 Vector4::operator-(const Vector4 & other)
{
	return Vector4();
}

Vector4 Vector4::operator*(float other)
{
	return Vector4();
}

Vector4 Vector4::operator=(const Vector4 & other)
{
	return Vector4();
}

float Vector4::dot(const Vector4 & other) const
{
	return 0.0f;
}

float Vector4::operator[](int index) const
{
	return 0.0f;
}

Vector4::operator float*()
{
}

Vector4::operator const float*() const
{
}

float Vector4::magnitude() const
{
	return 0.0f;
}

float Vector4::distance(const Vector4 & other) const
{
	return 0.0f;
}

void Vector4::normalise()
{
}

Vector4 Vector4::normalised() const
{
	return Vector4();
}

Vector4 Vector4::cross(const Vector4 & other) const
{
	return Vector4();
}

float Vector4::angleBetween(const Vector4 & other) const
{
	return 0.0f;
}


Vector4::~Vector4()
{
}

Vector4 operator*(const float & scalar, const Vector4 & a_vec)
{
	return Vector4();
}