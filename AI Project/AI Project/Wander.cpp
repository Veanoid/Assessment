#include "Wander.h"
#include <random>
#include <time.h>
#include "Pursuit.h"
#include "StateMachine.h"
#include <glm\ext.hpp>



Wander::Wander()
{
}

Wander::Wander(Agent * target, float distance, float radius, float amount)
{
	m_distance = distance;
	m_radius = radius;
	m_amount = amount;

	randomVec = Vector2(rand() % (int)m_amount, rand() % (int)m_amount);
	m_target = target;
}

void Wander::update(Agent * agent, StateMachine * sm, float deltaTime)
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

	// Vector2 dist = m_target->Getpostion() - agent->Getpostion();
	// float mag = dist.magnitude();
	// if (mag < 100.0f)
	// {
	// 	sm->ChangeState(agent, new Pursuit(m_target));
	// }
}

void Wander::setAngle(Vector2 vec, float value)
{
}


Wander::~Wander()
{
}
