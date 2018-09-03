#include "Pursuit.h"
#include "StateMachine.h"
#include <Vector2.h>
#include "IdleBehavior.h"



Pursuit::Pursuit()
{
}

Pursuit::Pursuit(Agent * target)
{
	this->target = target;
}


Pursuit::~Pursuit()
{
}

void Pursuit::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	Vector2 desiredVe = target->position + target->velocity - agent->position;
	desiredVe.normalise();
	desiredVe = desiredVe * 100.0f;
	Vector2 force = desiredVe - agent->velocity;
	agent->Addforce(force);

	

	Vector2 dist = target->Getpostion() - agent->Getpostion();
	float mag = dist.magnitude();
	if (mag > 100.0f)
	{
		sm->ChangeState(agent, new IdleBehavior(target));
	}
	
}

void Pursuit::init(Agent * agent)
{
}

void Pursuit::exit(Agent * agent)
{
}


