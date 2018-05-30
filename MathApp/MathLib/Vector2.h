#pragma once
class Vector2
{
public:
	union 
	{
		struct { float m_x, m_y; };
		float data[2];
	};
	Vector2();
	Vector2(float m_x, float m_y);

	Vector2 operator  +(const Vector2& other);// adding two vectors together 
	Vector2 operator  -(const Vector2& other);// subtracting two vectors 
	Vector2 operator *(float other);// timings a vector with a scale 

	friend Vector2 operator *(const float scalar, const Vector2 a_vec );

	Vector2 operator = (const Vector2& other); // making a vector and another vector\

	float dot(const Vector2& other);

	Vector2 getPrependiularRH() const;
	Vector2 getPrependiularLH() const;


	float operator [] (int index) const;
	explicit operator float* ();
	explicit operator const float* () const;

	float magnitude() const;
	float distance(const Vector2& other) const;
	void normalise();

	

	~Vector2();
};

