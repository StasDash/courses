#include <vector>
#include <iostream>
#include <string>
#include "Bus.h"
#include "Park.h"


int main() {
	Park park;
	park.addPark(Bus("Vodila1", 4, 3));
	park.addPark(Bus("Vodila2", 5, 4));
	park.addPark(Bus("Vodila3", 6, 5));
	park.addPark(Bus("Vodila4", 7, 6));
	park.addPark(Bus("Vodila5", 8, 7),3);
	park.addPark(Bus("Vodila6", 9, 8));
	park.fromPark(9);
	park.fromPark(3);
	park.fromPark(5);
	park.printPark();
	std::cout << std::endl;
	park.printWay();
}