#include "Evade.h"
#include "Wander.h"
#include "StateMachine.h"



Evade::Evade()
{
}

Evade::Evade(Agent * target)
{
	this->target = target;
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

	Vector2 dist = target->Getpostion() - agent->Getpostion();
	float mag = dist.magnitude();
	if (mag > 100.0f)
	{
		sm->ChangeState(agent, new Wander(target, 200, 100, 1));
	}
}

void Evade::init(Agent * agent)
{
}

void Evade::exit(Agent * agent)
{
}


