#include "EnemyState.h"



EnemyState::EnemyState()
{
}

EnemyState::EnemyState(Agent * target, Agent * protect, Agent* self)
{
	this->m_target = target;
	this->m_protect = protect;
	this->m_Agent = self;
}


void EnemyState::update(Agent * agent, StateMachine * sm, float deltaTime)
{
}


EnemyState::~EnemyState()
{
}
