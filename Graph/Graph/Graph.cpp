#include "Graph.h"

Graph::Graph(int numNodes)
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
	for (int i = 0;  i < numNodes;  i++)
	{
		Node* newNode = new Node();
		newNode->_checked = false;
		newNode->_val = i;
		_nodeConnectionList.push_back(newNode);
	}
}


Graph::~Graph()
{
	for (int i = 0; i < _numNodes; i++) {
		delete _nodeConnectionList[i];
	}
}

void Graph::addConnections(int val_1, int val_2)
{

	//Edge cases
	if (val_1 < 0 || val_1 > _numNodes - 1) {
		return;
	}

	if (val_2 < 0 || val_2 > _numNodes - 1) {
		return;
	}

	//Add connection to connection matrix
	_nodeConnectionMatrix[val_1][val_2] = 1;

	//Add connection to connection list
	_nodeConnectionList[val_1]->_pointsToList.push_back(_nodeConnectionList[val_2]);

}

void Graph::setIfNodeChecked(bool state)
{
	for (int i = 0; i < _numNodes; i++)
	{
		_nodeConnectionList[i]->_checked = state;
	}
}

void Graph::processNode(Node* target)
{
	target->_checked = true;
	std::cout << "[" << target->_val << "] ";
}

void Graph::printDFS()
{
	setIfNodeChecked(false);//Reset nodes just in case

	if (_nodeConnectionList.size() < 1) {
		std::cout << "Error: There are no nodes in the graph!" 
			<< std::endl << "Ending search" << std::endl ;
	}

	std::cout << "=== Printing Graph in DFS order ===" << std::endl;

	//Assign first node as starting point
	std::stack<Node*> nodeStack;
	nodeStack.push(_nodeConnectionList[0]);

	while (!nodeStack.empty()) {	//Loop until no more connecting, unchecked nodes

		Node* currentNode = nodeStack.top(); //Get top node
		nodeStack.pop();

		//Add connecting nodes to stack (if unchecked)
		for (int i = 0; i < currentNode->_pointsToList.size(); i++)
		{
			if (currentNode->_pointsToList[i]->_checked == false) {
				//Push unchecked connecting node onto stack
				nodeStack.push(currentNode->_pointsToList[i]);
			}
		}

		//Process current node
		processNode(currentNode);
	}

	setIfNodeChecked(false);//Reset nodes once done
}

void Graph::printBFS()
{
	setIfNodeChecked(false);//Reset nodes just in case

	if (_nodeConnectionList.size() < 1) {
		std::cout << "Error: There are no nodes in the graph!"
			<< std::endl << "Ending search" << std::endl;
	}

	std::cout << "=== Printing Graph in BFS order ===" << std::endl;

	//Assign first node as starting point
	std::queue<Node*> nodeQueue;
	nodeQueue.push(_nodeConnectionList[0]);

	while (!nodeQueue.empty()) {	//Loop until no more connecting, unchecked nodes

		Node* currentNode = nodeQueue.front(); //Get front node
		nodeQueue.pop();

		//Add connecting nodes to stack (if unchecked)
		for (int i = 0; i < currentNode->_pointsToList.size(); i++)
		{
			if (currentNode->_pointsToList[i]->_checked == false) {
				//Push unchecked connecting node onto stack
				nodeQueue.push(currentNode->_pointsToList[i]);
			}
		}

		//Process current node
		processNode(currentNode);
	}

	setIfNodeChecked(false);//Reset nodes once done
}