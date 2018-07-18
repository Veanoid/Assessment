#include "Seekbehaviour.h"
#include <Vector2.h>



Seekbehaviour::Seekbehaviour()
{
}

Seekbehaviour::Seekbehaviour(Agent * target)
{
	this->target = target;
}

Seekbehaviour::~Seekbehaviour()
{
}

void Seekbehaviour::update(float deltaTime, Agent* agent)
{
	Vector2 desiredVel = target->position - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->Addforce(force);

}

