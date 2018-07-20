#pragma once
#include "Agent.h"
#include <Vector2.h>
#include "State.h"
class Evade : public state
{
public:
	Evade();
	Evade(Agent* target);
	~Evade();
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent);
	virtual void exit(Agent* agent);

private:

	Agent * target;
};

