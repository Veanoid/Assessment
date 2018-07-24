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
	void AddNode(GraphNode* node);
	void ConnectBode(GraphNode* a, GraphNode* b, float cost);
	std::vector<GraphNode*> GetNodes();
	std::vector<GraphEdge*> DFS(GraphNode* startNode, GraphNode* endNode); // Depth First Search = DFS
	std::vector<GraphNode*> BFS(GraphNode* startNode, GraphNode* endNode); // Breadth first search = BFS
	std::vector<GraphNode*> DjikstraSearch(GraphNode* startNode, GraphNode* endNode); // Djikstra
	void draw(aie::Renderer2D* renderer);


	~Graph();
private:
	std::vector<GraphNode*> m_nodes;
};

