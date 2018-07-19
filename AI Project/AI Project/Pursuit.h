#pragma once
#include "Agent.h"
#include <Vector2.h>
#include "State.h"
class Pursuit : public state
{
public:
	Pursuit();
	Pursuit(Agent* target);
	~Pursuit();
	virtual void update(float deltaTime, Agent* Agent);

private:
	Agent * target;
};

