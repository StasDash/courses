#include <iostream>
#include "vzastringo.h"

int main()
{
    vzastringo str("zawarudo");
	str = "kurazzidiamondo";
	vzastringo str1(str);
	std::cout << str<<std::endl;
	vzastringo str2(std::move(str));
	str1 = str2;
	str2 = std::move(str1);
}