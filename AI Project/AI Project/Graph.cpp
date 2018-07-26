#include "Graph.h"
#include <Renderer2D.h>




Graph::Graph()
{
}

void Graph::AddNode(GraphNode * node)
{
	m_nodes.push_back(node); // pushes a node into the vector 
}

void Graph::ConnectNode(GraphNode * a, GraphNode * b, float cost)
{
	a->AddConnections(a, b, cost);// connects two nodes together and gives it a value 
}

std::vector<GraphNode*> Graph::GetNodes()
{
	return m_nodes; // returns a node 
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
	for (auto n : m_nodes)
	{
		// draw circle on node's poition
		renderer->drawCircle(n->GetPosition().m_x, n->GetPosition().m_y, 2.0f);

		for ( auto e : n->GetConnections())
		{
 			renderer->drawLine(n->GetPosition().m_x, n->GetPosition().m_y, e->GetNode()->GetPosition().m_x, e->GetNode()->GetPosition().m_y);
		}
	}
}


Graph::~Graph()
{
}
