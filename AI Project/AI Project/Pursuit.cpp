#include "Pursuit.h"



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
}

void Pursuit::init(Agent * agent)
{
}

void Pursuit::exit(Agent * agent)
{
}


