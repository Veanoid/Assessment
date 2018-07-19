#pragma once
#include "Agent.h"

class StateMachine;
class state
{
public:
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime) = 0;
	virtual void init(Agent* agent) = 0;
	virtual void exit(Agent* agent) = 0;
};