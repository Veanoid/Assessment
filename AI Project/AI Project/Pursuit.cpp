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

void Pursuit::update(float deltaTime, Agent * Agent)
{
	Vector2 desiredVe = target->position + target->velocity - Agent->position;
	desiredVe.normalise();
	desiredVe = desiredVe * 100.0f;
	Vector2 force = desiredVe - Agent->velocity;
	Agent->Addforce(force);
}
