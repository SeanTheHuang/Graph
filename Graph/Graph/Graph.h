#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <iostream>
#include <stack>
#include <queue>

struct Node
{
	int _val;
	bool _checked;
	std::vector<Node*> _pointsToList;

};

class Graph
{
public:
	Graph(int numNodes = 5);
	~Graph();

	void addConnections(int, int);
	void printDFS();
	void printBFS();

private:
	const int _numNodes;

	int _nodeConnectionMatrix[100][100];
	std::vector<Node*> _nodeConnectionList;

	void setIfNodeChecked(bool);
	void processNode(Node*);
};

#endif

