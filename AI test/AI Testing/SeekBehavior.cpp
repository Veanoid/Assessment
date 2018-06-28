#include "SeekBehavior.h"
#include <Vector2.h>


SeekBehavior::SeekBehavior()
{
}

SeekBehavior::SeekBehavior(GameObject * target)
{
	 this->target = target;
}


SeekBehavior::~SeekBehavior()
{
}

void SeekBehavior::update(float deltaTiem, GameObject * agent)
{
	Vector2 desiredVel = target->position - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->Addforce(force);
}

