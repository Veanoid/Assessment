#pragma once
#include "Agent.h"
#include <Vector2.h>
#include "State.h"
class Seekbehaviour : public state
{
public:
	Seekbehaviour();
	Seekbehaviour(Agent* target);
	~Seekbehaviour();
	virtual void update(float deltaTime, Agent* agent);

private:
	Agent* target;

};

