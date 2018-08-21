#include "EnemyState.h"
#include



EnemyState::EnemyState()
{
}

EnemyState::EnemyState(Agent * target, Agent * protect)
{
	this->m_target = target;
	this->m_protect = protect;
}


void EnemyState::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	Vector2 dist = m_protect->position - agent->position;
	float lnth = dist.magnitude();

	Vector2 distance = m_target->position - agent->position;
	float length = distance.magnitude();

	/*if (length < 200.0f)
	{
		m_curent = new se
	}*/

}


EnemyState::~EnemyState()
{
}
