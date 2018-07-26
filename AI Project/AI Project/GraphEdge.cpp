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
}


GraphEdge::~GraphEdge()
{
}
