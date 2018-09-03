#include "Wander.h"
#include <random>
#include <time.h>
#include "Seekbehaviour.h"
#include "StateMachine.h"
#include <glm\ext.hpp>
#include "Evade.h"
#include <Vector2.h>



Wander::Wander()
{
	m_type = StateType::Wander;
}

Wander::Wander(Agent * target, float distance, float radius, float amount)
{
	m_distance = distance;
	m_radius = radius;
	m_amount = amount;

	randomVec = Vector2(rand() % (int)m_amount, rand() % (int)m_amount);
	m_target = target;
	m_type = StateType::Wander;

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

	 
}

void Wander::setAngle(Vector2 vec, float value)
{
}


Wander::~Wander()
{
}
