#include <iostream>
#include "Money.h"

int main()
{
	setlocale(LC_ALL, "");
	Money m(5000.0);
	Money b(500000000000.0);
	std::cout << m + b << std::endl << m - b;
}