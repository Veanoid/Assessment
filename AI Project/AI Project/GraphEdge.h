#pragma once
class GraphNode;

class GraphEdge
{
public:
	GraphEdge();
	void SetNode(GraphNode* node);
	GraphNode* GetNode();

	void SetCost(float cost);
	float GetCost;
	~GraphEdge();
private:
	GraphNode * target;
	float cost; 

};

