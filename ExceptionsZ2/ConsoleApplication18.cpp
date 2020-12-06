#include <iostream>
#include "queue.h"

int main()
{
	queue<int> queue(4);
	queue.push_back(5);
	queue.push_back(6);
	queue.push_back(7);
	queue.push_back(8);
	try {
		queue.push_back(9);
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		queue.get();
		queue.push_back(9);
	}
	queue.get();
	queue.get();
	queue.get();
	queue.get();
	try {
		queue.get();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	queue.push_back(5);
	queue.push_back(6);
	queue.push_back(7);
	queue.push_back(8);
	std::cout << queue;
}
