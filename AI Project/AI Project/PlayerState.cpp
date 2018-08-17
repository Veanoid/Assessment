#include "PlayerState.h"
#include "StateMachine.h"


PlayerState::PlayerState()
{
}

PlayerState::PlayerState(Agent * target, Agent * destroy, Agent* self)
{
	this->m_target = target;
	this->m_destroy = destroy;
	this->m_Agent = self;
}


void PlayerState::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	Vector2 dist = m_destroy->position - agent->position;
	float lnth = dist.magnitude();

	Vector2 distance = m_target->position - agent->position;
	float length = distance.magnitude();

	if (length < 200.0f)
	{
		sm->ChangeState(agent, new Pursuit(m_target));
	}
}


PlayerState::~PlayerState()
{
}
