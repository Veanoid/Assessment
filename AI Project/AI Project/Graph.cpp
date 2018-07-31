#include "Graph.h"
#include <Renderer2D.h>
#include <list>




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
	
	// iterate through all the nodes
	for (auto n : m_nodes)
	{
		// Set all the nodes parents to be null

		n->SetParent(nullptr);

		// set all gscores to Infinity

		n->SetGScore(INFINITY);
	}
	// set up the container (list)
	std::list<GraphNode*> p_queue;
	// push the start node into the list
	p_queue.push_front(startNode);

	// set the startnode parent to nullptr
	startNode->SetParent(nullptr);
	
	// set the startnode g-score to 0
	startNode->SetGScore(0);

	//startNode->SetVisited(true);

	//while the queue is not empty
	
	while (!p_queue.empty())
	{
		p_queue.sort(GraphNode::CompareGScore);
		// get current node off the end of the queue 
		auto currentNode = p_queue.front();
		// and remove it
		p_queue.pop_front();

		if (currentNode == endNode)
			break;

		//// mark it as travered
		currentNode->SetVisited(true);
		//go through it's edges
		for (auto connections : currentNode->GetConnections())
		{	// if tareget node is not travered
			auto target = connections->GetNode();
			if (!target->GetVisited())
			{
				//target->SetVisited(true);
				// calculate the current node's gScore with the egde cost
				if (currentNode->GetGScore() + connections->GetCost() < target->GetGScore());
				{
					// set target node's parent to the current 
					target->SetParent(currentNode);
					// set targets Gscore to current gscore plus edge cost
					target->SetGScore(currentNode->GetGScore() + connections->GetCost());
					// if target node hasn't been in the queue 
					//if (!target->GetVisited())
					//{
						// push target node into queue
						p_queue.push_back(target);
					//}
				}
			}
		}
	}

	std::vector<GraphNode*> path;
	auto currentNode = endNode;
	while (currentNode != nullptr)
	{
		path.push_back(currentNode);
		currentNode = currentNode->GetParent();
	}

	return path;
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
