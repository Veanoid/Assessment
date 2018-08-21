#pragma once
#include "State.h"
class PlayerState : public state
{
public:
	PlayerState();
	PlayerState(Agent* target, Agent* destroy);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent) {}
	virtual void exit(Agent* agent) {}
	~PlayerState();

private:
	Agent* m_target;
	Agent* m_destroy;
	state* m_current;
};

