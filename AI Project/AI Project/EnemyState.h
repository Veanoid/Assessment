#pragma once
#include "State.h"
class EnemyState : public state
{
public:
	EnemyState();
	EnemyState(Agent* target, Agent* protect);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent) {}
	virtual void exit(Agent* agent) {}
	~EnemyState();

private:

	Agent* m_target;
	Agent* m_protect;
	state* m_curent;
};

