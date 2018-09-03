#include "PathBehaviour.h"
#include "GraphNode.h"



PathBehaviour::PathBehaviour()
{
	m_type = StateType::PathBehavior;
}

PathBehaviour::PathBehaviour(std::vector<GraphNode*> path)
{
	m_path = path;
	m_type = StateType::PathBehavior;
}

void PathBehaviour::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	if (!m_path.empty())
	{

		// store the end node in target node
		GraphNode* targetNode = m_path.back();

		//getting the distant from agent to target
		Vector2 desiredVel = targetNode->GetPosition() - agent->Getpostion();
		Vector2 distance = desiredVel;
		desiredVel.normalise();
		desiredVel = desiredVel * 100.0f;
		Vector2 force = desiredVel - agent->velocity;
		agent->Addforce(force);

		// popping the back of the list until it gets to it's target
		float mag = distance.magnitude();
		if (mag < 20.0f)
		{
			m_path.pop_back();
		}
	}
}

PathBehaviour::~PathBehaviour()
{
}
