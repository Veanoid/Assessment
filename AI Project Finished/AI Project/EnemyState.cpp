#include "EnemyState.h"
#include "StateMachine.h"
#include "IdleBehavior.h"
#include "Wander.h"
#include "Seekbehaviour.h"




EnemyState::EnemyState()
{
}

EnemyState::EnemyState(Agent * target, Agent * protect)
{
	this->m_target = target;
	this->m_protect = protect;
	m_current = new IdleBehavior(m_target);
}


void EnemyState::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	// getting the distant from the agent and the stone 
	Vector2 dist = m_protect->position - agent->position;
	float lnth = dist.magnitude();
	// getting the distants from the player and agent
	Vector2 distance = m_target->position - agent->position;
	float length = distance.magnitude();

	if (length > 200.0f && lnth < 200.0f)
	{
		// set the current state to Patrole
		delete m_current;
		m_current = new Wander(m_target, 50, 1, 1);
	}
	if (length < 200.0f && lnth < 200.0f)
	{
		// set the current state to Seeking the target
		delete m_current;
		m_current = new Seekbehaviour(m_target);
	}
	if (lnth > 200.0f)
	{
		// set the current state to Seeking the stone
		delete m_current;
		m_current = new Seekbehaviour(m_protect);
	}
	m_current->update(agent, sm, deltaTime);
}


EnemyState::~EnemyState()
{
}
