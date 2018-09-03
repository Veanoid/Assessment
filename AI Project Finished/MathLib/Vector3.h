#pragma once
class Vector3
{
public:
	union
	{
		struct { float m_x, m_y, m_z; };
		float data[3];
	};
	Vector3();
	Vector3(float m_x, float m_y, float m_z);

	Vector3 operator  +(const Vector3& other);
	Vector3 operator  -(const Vector3& other);
	Vector3 operator *(float other);
	Vector3& operator = (const Vector3& other);

	float dot(const Vector3& other)const;

	friend Vector3 operator *(const float& scalar, const Vector3& a_vec);
	float operator [](int index) const;
	operator float* ();
	operator const float* () const;

	float magnitude() const;
	float distance(const Vector3& other) const;
	void normalise();
	Vector3 normalised() const;
	Vector3 cross(const Vector3& other) const;
	float angleBetween(const Vector3& other)const;

	~Vector3();
};

