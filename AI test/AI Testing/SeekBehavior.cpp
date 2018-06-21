#include "SeekBehavior.h"
#include <glm\ext.hpp>


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
	glm::vec2 desiredVel = target->position - agent->position;
	desiredVel = glm::normalize(desiredVel) * 100.0f;
	glm::vec2 force = desiredVel - agent->velocity;
	agent->Addforce(force);
}

