#pragma once
#include "IBehaviour.h"
#include "State.h"
class StateMachine : public IBehaviour
{
public:
	StateMachine();
	virtual void update(Agent* agent, float deltaTime);
	void ChangeState(Agent* agent, state* newState);
	state* getCurrentState();
	state* getPrevState();
	~StateMachine();
private:

	state * currentState;
	state * prevSate;
};

