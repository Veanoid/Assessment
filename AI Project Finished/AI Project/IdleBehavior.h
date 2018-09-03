#pragma once
#include "State.h"
class IdleBehavior : public state
{
public:
	IdleBehavior();
	IdleBehavior(Agent* target);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent);
	virtual void exit(Agent* agent);
	~IdleBehavior();

private:
	Agent * m_target;
};

