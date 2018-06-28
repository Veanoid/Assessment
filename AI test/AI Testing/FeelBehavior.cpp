#include "FeelBehavior.h"
#include <Vector2.h>




FeelBehavior::FeelBehavior()
{
}

FeelBehavior::FeelBehavior(GameObject * target)
{
	this->target = target;
}


FeelBehavior::~FeelBehavior()
{
}

void FeelBehavior::update(float deltaTiem, GameObject * agent)
{
	Vector2 desiredVel =  agent->position + target->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->Addforce(force);
}
