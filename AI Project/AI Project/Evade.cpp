#include "Evade.h"



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

void Evade::update(float deltaTime, Agent * Agent)
{
	Vector2 desiredVel = target->position + target->velocity + Agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - Agent->velocity;
	Agent->Addforce(force);
}
