#pragma once
#include "Agent.h"

class StateMachine;
class state
{
public:
	enum class StateType
	{
		PlayerState,
		Wander,
		Evade,
		PathBehavior 
	};

	virtual void update(Agent* agent, StateMachine* sm, float deltaTime) = 0;
	virtual void init(Agent* agent) = 0;
	virtual void exit(Agent* agent) = 0;

	StateType getType() const { return m_type; }
protected:
	StateType m_type;
};