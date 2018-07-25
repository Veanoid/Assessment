#pragma once
#include<Vector2.h>
#include<vector>
class GraphEdge;

class GraphNode
{
public:
	GraphNode();
	// value of the nodes
	void SetPosition(Vector2 position);
	Vector2 GetPosition();
	// setting it to visted
	void SetVisited(bool Visited);
	bool GetVisited();
	// adds connections together
	void AddConnections(GraphNode * node, GraphNode* target, float cost);
	std::vector<GraphEdge*> GetConnections();
	// sets a parent
	void SetParent(GraphNode* node);
	GraphNode* GetParent();
	// g score 
	void SetGScore(float gScore);
	float GetGScore();

	static bool CompareGScore(GraphNode* a, GraphNode* b);

	~GraphNode();

private:
	Vector2					m_position;
	bool					m_isVisited;
	GraphNode*				m_parent;
	float					m_gScore;
	std::vector<GraphEdge*> m_connections;
};

