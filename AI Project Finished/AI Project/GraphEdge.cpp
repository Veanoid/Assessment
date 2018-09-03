#include "GraphEdge.h"



GraphEdge::GraphEdge()
{
}

void GraphEdge::SetNode(GraphNode * node)
{
	target = node;
}

GraphNode * GraphEdge::GetNode()
{
	return target;
}

void GraphEdge::SetCost(float cost)
{
	m_cost = cost;
}

float GraphEdge::GetCost()
{
	return m_cost;
}


GraphEdge::~GraphEdge()
{
}
