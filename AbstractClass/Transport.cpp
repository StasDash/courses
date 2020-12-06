#include "Transport.h"


int Airplanes::cost_type() const {
	std::cout << "All cost is: ";
	return 0;
}

int Airplanes::get_cost() const
{
	return cost;
}

std::string Airplanes::type() const
{
	return "Airplane";
}


std::string CitizenAirplane::type() const {
	return "Citizen " + Airplanes::type();
}

std::string MilitaryAirplane::type() const {
	return "Military " + Airplanes::type();
}

int Auto::cost_type() const {
	std::cout << "Cost for 1km: ";
	return 1;
}

int Auto::get_cost() const
{
	return cost;
}

std::string Auto::type() const
{
	return "Auto";
}

std::string HeavyAuto::type() const {
	return "Heavy " + Auto::type();
}

std::string LightAuto::type() const {
	return "Light " + Auto::type();
}
