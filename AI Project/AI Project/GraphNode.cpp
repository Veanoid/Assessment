#include "GraphNode.h"
#include "GraphEdge.h"


GraphNode::GraphNode()
{
}

void GraphNode::SetPosition(Vector2 position)
{
}

Vector2 GraphNode::GetPosition()
{
	return Vector2();
}

void GraphNode::SetVisited(bool Visited)
{
}

bool GraphNode::GetVisited()
{
	return false;
}

void GraphNode::AddConnections(GraphNode * node, GraphNode * target, float cost)
{
	GraphEdge* newEdge = new GraphEdge;
	newEdge->SetNode(target);
	newEdge->SetCost(cost);
	node->m_connections.push_back(newEdge);
}

std::vector<GraphEdge*> GraphNode::GetConnections()
{
	return std::vector<GraphEdge*>();
}

void GraphNode::SetParent(GraphNode * node)
{
}

GraphNode * GraphNode::GetParent()
{
	
	return nullptr;
}

void GraphNode::SetGScore(float gScore)
{
}

float GraphNode::GetGScore()
{
	return 0.0f;
}

bool GraphNode::CompareGScore(GraphNode * a, GraphNode * b)
{
	return false;
}


GraphNode::~GraphNode()
{
}
