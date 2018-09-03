#pragma once
#include "Agent.h"
#include <Vector2.h>
#include "State.h"
class Seekbehaviour : public state
{
public:
	Seekbehaviour();
	Seekbehaviour(Agent* target);
	~Seekbehaviour();
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent) {}
	virtual void exit(Agent* agent) {}

private:
	Agent* target;

};

