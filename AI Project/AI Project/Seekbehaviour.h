#pragma once
#include "Agent.h"
#include <Vector2.h>
class Seekbehaviour
{
public:
	Seekbehaviour();
	Seekbehaviour(Agent* target);
	~Seekbehaviour();
	Vector2 update(float deltaTime, Agent* agent);

private:
	Agent* target;

};

