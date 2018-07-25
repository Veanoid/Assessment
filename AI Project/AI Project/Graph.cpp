#include "Graph.h"



Graph::Graph()
{
}

void Graph::AddNode(GraphNode * node)
{
	m_nodes.push_back(node);
}

void Graph::ConnectNode(GraphNode * a, GraphNode * b, float cost)
{
	a->AddConnections(a, b, cost);
}

std::vector<GraphNode*> Graph::GetNodes()
{
	return m_nodes;
}

std::vector<GraphEdge*> Graph::DFS(GraphNode * startNode, GraphNode * endNode)
{
	return std::vector<GraphEdge*>();
}

std::vector<GraphNode*> Graph::BFS(GraphNode * startNode, GraphNode * endNode)
{
	return std::vector<GraphNode*>();
}

std::vector<GraphNode*> Graph::DjikstraSearch(GraphNode * startNode, GraphNode * endNode)
{
	return std::vector<GraphNode*>();
}

void Graph::draw(aie::Renderer2D * renderer)
{
}


Graph::~Graph()
{
}
