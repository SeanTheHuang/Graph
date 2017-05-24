#include "Graph.h"
#include <conio.h>

int main()
{
	Graph test(10);

	std::cout << "=== Testing graph ===" << std::endl << std::endl;
	std::cout << "Nodes 0-9, each connecting to the next i.e. 0->1, 1->2, etc.." << std::endl;
	std::cout << "Node 0 also has an extra connection to node 3 i.e 0->3" << std::endl << std::endl;

	for (int i = 0; i < 10; i++) {
		test.addConnections(i, (i+1) % 10);
	}

	test.addConnections(0, 3);

	test.printDFS();

	std::cout << std::endl;

	test.printBFS();

	std::cout << std::endl << std::endl;

	_getch();

	return 0;
}