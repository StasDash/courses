#include <iostream>
#include <vector>
#include <algorithm>
#include "Array.h"


int main()
{
	Array<int> ra(32, 32);
	std::cout << ra;
	dostuff(std::cout, ra);
}
