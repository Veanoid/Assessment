#pragma once
#include "Agent.h"

class IBehaviour
{
public:
	virtual void update(float deltaTime, Agent* Agent) = 0;
};