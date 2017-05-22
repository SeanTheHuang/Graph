#include "Graph.h"

Graph::Graph(int numNodes = 5)
	:_numNodes(numNodes)
{
	//Create Node connection matrix
	for (int i = 0; i < numNodes; i++) {
		for (int j = 0; j < numNodes; j++)
		{
			_nodeConnectionMatrix[i][j] = 0;
		}
	}

	//Initialise connection list
	for (int j = 0;  j < numNodes;  j++)
	{
		_nodeConnectionList[j]._val = j;
		_nodeConnectionList[j]._checked = false;
	}
}


Graph::~Graph()
{
}

void Graph::addConnections(Node startNode, Node endNode)
{

	//Edge cases
	if (startNode._val < 0 || startNode._val > _numNodes - 1) {
		return;
	}

	if (endNode._val < 0 || endNode._val > _numNodes - 1) {
		return;
	}

	//Add connection to connection matrix
	_nodeConnectionMatrix[startNode._val][endNode._val] = 1;

	//Add connection to connection list
	_nodeConnectionList[startNode._val]._pointsToList.push_back(endNode);

}

void Graph::setIfNodeChecked(bool state)
{
	for (int i = 0; i < _numNodes; i++)
	{
		_nodeConnectionList[i]._checked = state;
	}
}

