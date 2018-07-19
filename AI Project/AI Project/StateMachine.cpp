#include "StateMachine.h"



StateMachine::StateMachine()
{
	prevSate = nullptr;
	currentState = nullptr;
}

void StateMachine::update(Agent * agent, float deltaTime)
{
	if (currentState != nullptr)
		currentState->update(agent, this, deltaTime);
}

void StateMachine::ChangeState(Agent * agent, state * newState)
{
	//if (currentState != nullptr)
	//	currentState->exit(agent);

	//if (newState != nullptr)
	//	newState->init(agent);

	prevSate = currentState;

	currentState = newState;
}

state * StateMachine::getCurrentState()
{
	return currentState;
}

state * StateMachine::getPrevState()
{
	return prevSate;
}


StateMachine::~StateMachine()
{
	delete currentState;
	delete prevSate;
}
