#include "FeelBehavior.h"
#include <glm\ext.hpp>




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
	glm::vec2 desiredVel =  agent->position - target->position;
	desiredVel = glm::normalize(desiredVel) * 100.0f;
	glm::vec2 force = desiredVel - agent->velocity;
	agent->Addforce(force);
}
