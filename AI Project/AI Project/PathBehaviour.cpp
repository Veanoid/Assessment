#include "PathBehaviour.h"
#include "GraphNode.h"



PathBehaviour::PathBehaviour()
{
}

PathBehaviour::PathBehaviour(std::vector<GraphNode*> path)
{
	m_path = path;
}

void PathBehaviour::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	if (!m_path.empty())
	{

		// store the end node in target node
		GraphNode* targetNode = m_path.back();


		Vector2 desiredVel = targetNode->GetPosition() - agent->Getpostion();
		Vector2 distance = desiredVel;
		desiredVel.normalise();
		desiredVel = desiredVel * 100.0f;
		Vector2 force = desiredVel - agent->velocity;
		agent->Addforce(force);

		float mag = distance.magnitude();
		if (mag < 10.0f)
		{
			m_path.pop_back();
		}
	}
}

PathBehaviour::~PathBehaviour()
{
}
