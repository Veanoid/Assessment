#include "Seekbehaviour.h"
#include <Vector2.h>
#include "StateMachine.h"
#include "Evade.h"
#include "Patrole.h"



Seekbehaviour::Seekbehaviour()
{
}

Seekbehaviour::Seekbehaviour(Agent * target)
{
	this->target = target;
}

Seekbehaviour::~Seekbehaviour()
{
	delete target;
}

void Seekbehaviour::update(Agent* agent, StateMachine* sm, float deltaTime)
{
	// state actions 
	Vector2 desiredVel = target->position - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->Addforce(force);

	//state transion rule 
	Vector2 dist = target->Getpostion() - agent->Getpostion();
	float mag = dist.magnitude();
	if (mag < 100.0f)
	{
		sm->ChangeState(agent, new Evade(target));
	}
	if (mag < 100.0f)
	{
		sm->ChangeState(agent, new Patrole(target));
	}

}