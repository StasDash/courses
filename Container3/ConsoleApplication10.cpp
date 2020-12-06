// ConsoleApplication10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>


int main()
{	
	std::vector<int> cards;
	int i = 0;
	for (i = 0; i < 52; i++) {
		cards.push_back(i);
	}
	for (i = 0; i < 52 * 4; i++) {
		int j = std::rand() % 52;
		std::swap(cards[i % 52], cards[j]);
	}
	for (i = 0; i < 52; i++) {
		if ((i + 1) % 13 == 0)
			std::cout << std::endl;
		std::cout << cards[i] << " ";
	}\
}
