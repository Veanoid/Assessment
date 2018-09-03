#pragma once
#include <Matrix2.h>
#include <Vector2.h>
#include "State.h"
class Wander : public state
{
public:
	Wander();
	Wander(Agent* target, float distance, float radius, float amount);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent) {}
	virtual void exit(Agent* agent){}
	void setAngle(Vector2 vec, float value);
	~Wander();

private:
	// move radius
	double      m_radius;
	// move distance
	double      m_distance;
	// move amount
	double      m_amount;
	// move angle
	int			m_angle;

	Vector2 randomVec;
	Agent * m_target;


};		       

