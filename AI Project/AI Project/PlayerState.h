#pragma once
#include "State.h"
#include "Seekbehaviour.h"
#include "Pursuit.h"
#include "Wander.h"
#include "IdleBehavior.h"
#include "Evade.h"
#include "Patrole.h"
class PlayerState
{
public:
	PlayerState();
	PlayerState(Agent* target, Agent* destroy);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent) {}
	virtual void exit(Agent* agent) {}
	~PlayerState();

private:
	Agent * m_target;
	Agent * m_destroy;
};

