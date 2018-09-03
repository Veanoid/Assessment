#pragma once
#include "Agent.h"

class IBehaviour
{
public:
	virtual void update(Agent* agent, float deltaTime) = 0;
};