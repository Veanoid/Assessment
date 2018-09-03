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
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent);
	virtual void exit(Agent* agent);

private:
	Agent * target;
};

