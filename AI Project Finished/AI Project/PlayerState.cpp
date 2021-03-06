#include "PlayerState.h"
#include "StateMachine.h"
#include "Wander.h"
#include "Evade.h"
#include "Seekbehaviour.h"
#include "IdleBehavior.h"
#include "PathBehaviour.h"
#include "Graph.h"




PlayerState::PlayerState()
{
}

PlayerState::PlayerState(Agent * target, Agent * destroy, Graph* graph, Agent* self)
{
	this->m_target = target;
	this->m_destroy = destroy;
	m_current = new IdleBehavior(m_target);
	this->m_playerGraph = graph;
	this->m_self = self;
}


void PlayerState::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	// call current state update function
	// getting the distants from the stone and the agent 
	Vector2 dist = m_destroy->position - agent->position;
	float lnth = dist.magnitude();
	// getting the distants from the agent and the enemy 
	Vector2 distance = m_target->position - agent->position;
	float length = distance.magnitude();

	if (length > 200.0f && lnth > 200.0f && m_current->getType() != state::StateType::Wander)
	{
		// set the current state to wander
		delete m_current;
		m_current = new Wander(m_target, 50, 1 ,1);
	}
	if (length < 200.0f && m_current->getType() != state::StateType::Evade)
	{
		// set the current state to Evade
		delete m_current;
		m_current = new Evade(m_target);
	}
	if (lnth < 200.0f && length > 200.0 && m_current->getType() != state::StateType::PathBehavior)
	{
		// set the current state to Seek
		delete m_current;
		auto startNode = m_playerGraph->FindNode(m_self);
		auto endNode = m_playerGraph->FindNode(m_destroy);
		std::vector<GraphNode*> path = m_playerGraph->DjikstraSearch(startNode, endNode);


		m_current = new PathBehaviour(path);

	}
	m_current->update(agent, sm, deltaTime);
}


PlayerState::~PlayerState()
{
}
