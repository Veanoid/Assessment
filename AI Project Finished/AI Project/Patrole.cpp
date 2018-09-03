#include "Patrole.h"
#include <random>
#include <time.h>
#include "Seekbehaviour.h"
#include "StateMachine.h"
#include <glm\ext.hpp>
#include "Seekbehaviour.h"
#include <Vector2.h>
#include "Pursuit.h"



Patrole::Patrole()
{
}

Patrole::Patrole(Agent * target, Agent * protect, float distance, float radius, float amount)
{
	// setting the targtet and protect to the agent 
	this->m_target = target;
	this->m_protect = protect;
	m_distance = distance;
	m_radius = radius;
	m_amount = amount;

	randomVec = Vector2(rand() % (int)m_amount, rand() % (int)m_amount);
	m_target = target;
}

void Patrole::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	glm::vec2 circle = glm::circularRand(m_radius);

	Vector2 newTarget = Vector2(randomVec.m_x + circle.x, randomVec.m_y + circle.y);

	newTarget.normalise();
	Vector2 normalisedTarget = newTarget;

	Vector2 targetOnSphere = normalisedTarget * m_radius;

	targetOnSphere.normalise();
	Vector2 force = targetOnSphere;
	force = force * 50.0f;

	agent->Addforce(force);
	Vector2 dist = m_target->Getpostion() - agent->Getpostion();
	Vector2 distn = m_protect->Getpostion() - agent->Getpostion();
	float mag = dist.magnitude();
	float magg = distn.magnitude();
	if (magg > 200.0f)
	{
		sm->ChangeState(agent, new Seekbehaviour(m_protect));
	}
	if (mag < 100.0f)
	{
		sm->ChangeState(agent, new Pursuit (m_target));
	}

}


Patrole::~Patrole()
{
}
