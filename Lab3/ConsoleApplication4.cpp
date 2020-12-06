#include <iostream>
#include "vector.h"

int main()
{
	vector a = { 4,2,1,4,5,6,7,11,8,9 };
	std::cout << a << "\n" << a.get_min() << "\n" << a.get_max() << " " << a.get_avr() << std::endl;
	a.sort();
	std::cout << a << std::endl;
	vector b;
	for (int i = 0; i < 10; i++) {
		int p;
		std::cin >> p;
		b.push_back(p);
	}
	std::cout << b << "\n" << b.dostuff();
}