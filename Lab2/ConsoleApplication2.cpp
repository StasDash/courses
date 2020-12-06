#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "zastringo.h"
#include "vzastringo.h"


int main()
{
	zastringo str;
	std::cin >> str;
	int times{ str.dostuff() };
	std::cout << "Stuff done: " << str << " " << times << "\n";

	vzastringo vstr{"HAHAHA ,, ,, ,,"};
	times = vstr.dostuff();
	std::cout << "Stuff done: " << vstr << " " << times << "\n";
}
