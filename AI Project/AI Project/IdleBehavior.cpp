#include "IdleBehavior.h"
#include "StateMachine.h"
#include "Pursuit.h"

IdleBehavior::IdleBehavior()
{
}

IdleBehavior::IdleBehavior(Agent * target)
{
	m_target = target;
}

void IdleBehavior::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	Vector2 distance = m_target->position - agent->position;
	float length = distance.magnitude();

	if (length < 200.0f)
	{
		sm->ChangeState(agent, new Pursuit(m_target));
	}
}

void IdleBehavior::init(Agent * agent)
{
}

void IdleBehavior::exit(Agent * agent)
{
}


IdleBehavior::~IdleBehavior()
{
}
