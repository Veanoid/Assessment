#include "Evade.h"
#include "Wander.h"
#include "StateMachine.h"



Evade::Evade()
{
	m_type = StateType::Evade;
}

Evade::Evade(Agent * target)
{
	this->target = target;
	m_type = StateType::Evade;
}


Evade::~Evade()
{
}

void Evade::update(Agent * agent, StateMachine* sm, float deltaTime)
{
	Vector2 desiredVel = target->position + target->velocity + agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 150.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->Addforce(force);

	
}

void Evade::init(Agent * agent)
{
}

void Evade::exit(Agent * agent)
{
}


