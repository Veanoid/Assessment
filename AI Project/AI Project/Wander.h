#pragma once
#include <Matrix2.h>
#include <Vector2.h>
class Wander
{
public:
	Wander();
	~Wander();

private:
	// move radius
	double      m_Radius;
	// move distance
	double      m_Distance;
	// move amount
	double      m_amount;
	// move target
	int			m_target;


};		       

