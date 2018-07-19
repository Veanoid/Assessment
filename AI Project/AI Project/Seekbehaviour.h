#pragma once
#include "Agent.h"
#include <Vector2.h>
#include "IBehaviour.h"
class Seekbehaviour : public IBehaviour
{
public:
	Seekbehaviour();
	Seekbehaviour(Agent* target);
	~Seekbehaviour();
	virtual void update(float deltaTime, Agent* agent);

private:
	Agent* target;

};

