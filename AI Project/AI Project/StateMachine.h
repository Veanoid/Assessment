#pragma once
#include "State.h"
class StateMachine
{
public:
	StateMachine();
	void update(Agent* agent, float deltaTime);
	void ChangeState(Agent* agent, state* newState);
	state* getCurrentState();
	state* getPrevState();
	~StateMachine();
private:

	state * currentState;
	state * prevSate;
};

