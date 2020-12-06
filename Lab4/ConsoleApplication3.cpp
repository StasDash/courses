#include <iostream>
#include <string>
#include <vector>
#include "Motorcycle.h"
#include "Auto.h"
#include "Bicycle.h"

int main()
{
	Motorcycle m;
	Auto a;
	Bicycle b;

	std::cout << m << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << m.fuel() << " " << a.fuel() << " " << b.fuel() << std::endl;
	std::cout << m.rings() << " " << a.rings() << " " << b.rings() << " " << std::endl;
}