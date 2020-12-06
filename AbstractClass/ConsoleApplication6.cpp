#include <iostream>
#include "Transport.h"

int main() {
	CitizenAirplane aa(55);
	MilitaryAirplane ab(57);
	LightAuto ba(59);
	HeavyAuto bb(61);
	std::cout << aa << "\n" << ab << "\n" << ba << "\n" << bb << std::endl;
}