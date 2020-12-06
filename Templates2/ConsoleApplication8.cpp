#include <iostream>
#include "Array.h"


int main()
{
	Array<float> obj({ 5.4f,4.3f,0.3f });
	Array<int> obj1({ 5,4,9 });
	std::cout << obj.sum() << std::endl;
	obj1.push_back(1);
	std::cout << obj1.sum() << std::endl;
}
