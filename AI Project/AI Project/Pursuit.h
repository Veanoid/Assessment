#pragma once
#include "Agent.h"
#include <Vector2.h>
class Pursuit
{
public:
	Pursuit();
	Pursuit(Agent* target);
	~Pursuit();
	void update(float deltaTime, Agent* Agent);

private:
	Agent * target;
};

