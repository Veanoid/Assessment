#pragma once
class GraphNode;

class GraphEdge
{
public:
	GraphEdge();
	//target node
	void SetNode(GraphNode* node);
	GraphNode* GetNode();
	//cost of the edge
	void SetCost(float cost);
	float GetCost();
	~GraphEdge();
private:
	GraphNode * target;
	float m_cost; 

};

