#pragma once
#include "State.h"
class GraphNode;
class PathBehaviour : public state
{
public:
	PathBehaviour();
	PathBehaviour(std::vector<GraphNode*> path);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent)	{}
	virtual void exit(Agent* agent) {}
	~PathBehaviour();

private:
	std::vector<GraphNode*>		m_path;
	
};

