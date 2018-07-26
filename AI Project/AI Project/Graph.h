#pragma once
#include "GraphEdge.h"
#include "GraphNode.h"

namespace aie{
	class Renderer2D;
}

class Graph
{
public:
	Graph();
	void AddNode(GraphNode* node);// add nodes into the graph
	void ConnectNode(GraphNode* a, GraphNode* b, float cost); // connects the nodes
	std::vector<GraphNode*> GetNodes();// gets the node
	std::vector<GraphEdge*> DFS(GraphNode* startNode, GraphNode* endNode); // Depth First Search = DFS
	std::vector<GraphNode*> BFS(GraphNode* startNode, GraphNode* endNode); // Breadth first search = BFS
	std::vector<GraphNode*> DjikstraSearch(GraphNode* startNode, GraphNode* endNode); // Djikstra
	void draw(aie::Renderer2D* renderer);// draws the node
	~Graph();
private:
	std::vector<GraphNode*> m_nodes;
};

