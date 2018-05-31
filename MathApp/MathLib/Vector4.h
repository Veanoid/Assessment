#pragma once
class Vector4
{
public:
	union
	{
		struct { float m_x, m_y, m_z, m_w; };
		float data[4];
	};
	Vector4();
	Vector4(float m_x, float m_y, float m_z, float m_w);

	Vector4 operator  +(const Vector4& other);
	Vector4 operator  -(const Vector4& other);
	Vector4 operator *(float other);
	Vector4 operator = (const Vector4& other);

	float dot(const Vector4& other)const;

	friend Vector4 operator *(const float& scalar, const Vector4& a_vec);
	float operator [](int index) const;
	operator float* ();
	operator const float* () const;

	float magnitude() const;
	float distance(const Vector4& other) const;
	void normalise();
	Vector4 normalised() const;
	Vector4 cross(const Vector4& other) const;
	float angleBetween(const Vector4& other)const;

	~Vector4();
};

