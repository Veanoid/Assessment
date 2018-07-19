#pragma once
#include "Agent.h"
#include <Vector2.h>
#include "IBehaviour.h"
class Evade : public IBehaviour
{
public:
	Evade();
	Evade(Agent* target);
	~Evade();
	virtual void update(float deltaTime, Agent* Agent);

private:

	Agent * target;
};

