#pragma once
#include "State.h"
class Patrole : public state
{
public:
	Patrole();
	Patrole(Agent* target, Agent* protect, float distance, float radius, float amount); // setting target and protect
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent) {}
	virtual void exit(Agent* agent) {}
	~Patrole();

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
	//Agent* m_target;
	Agent* m_protect;
};

