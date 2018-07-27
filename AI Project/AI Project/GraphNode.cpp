#include "GraphNode.h"
#include "GraphEdge.h"


GraphNode::GraphNode()
{
	m_position = Vector2 (0,0);
	m_gScore = 0.0f; 
	m_isVisited = false; 
	m_parent = nullptr; 
}

void GraphNode::SetPosition(Vector2 position)
{
	m_position = position; 
}

Vector2 GraphNode::GetPosition()
{
	return m_position; 
}

void GraphNode::SetVisited(bool Visited)
{
	m_isVisited = Visited;
}

bool GraphNode::GetVisited()
{
	return m_isVisited;
}

void GraphNode::AddConnections(GraphNode * node, GraphNode * target, float cost)
{
	GraphEdge* newEdge = new GraphEdge; // creates a edge 
	newEdge->SetNode(target); // sets the edge to point at a node
	newEdge->SetCost(cost); // gives the edge a value
	node->m_connections.push_back(newEdge); // sets the edge to a node 
}

std::vector<GraphEdge*> GraphNode::GetConnections()
{
	return m_connections;
}

void GraphNode::SetParent(GraphNode * node)
{
	m_parent = node; 
}

GraphNode * GraphNode::GetParent()
{
	
	return m_parent;
}

void GraphNode::SetGScore(float gScore)
{
	m_gScore = gScore;
}

float GraphNode::GetGScore()
{
	return m_gScore;
}

bool GraphNode::CompareGScore(GraphNode * a, GraphNode * b)
{
	if (a >  b )
	{
		return true;
	}
	else
	{
		return false;
	}
}


GraphNode::~GraphNode()
{
}
