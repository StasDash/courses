#pragma once
#include <iostream>

class Transport {
public:
	virtual int get_cost() const = 0;
	virtual std::string type() const = 0;
	virtual int cost_type() const = 0;
	friend std::ostream& operator<<(std::ostream& cout, Transport& trs) {
		cout << trs.get_cost() << " (" << trs.cost_type() << ") " << trs.type();
		return cout;
	}
};

class Airplanes : public Transport {
	int cost;
public:
	Airplanes(int cost) : cost(cost) {}
	int cost_type() const;

	virtual int get_cost() const override;
	virtual std::string type() const override;
};

class CitizenAirplane : public Airplanes {
public:
	CitizenAirplane(int cost) : Airplanes(cost) {}
	std::string type() const;
};

class MilitaryAirplane : public Airplanes {
public:
	MilitaryAirplane(int cost) : Airplanes(cost) {}
	std::string type() const;
};

class Auto : public Transport {
	int cost;
public:
	Auto(int cost) : cost(cost) {}
	int cost_type() const;

	virtual int get_cost() const override;
	virtual std::string type() const override;
};


class HeavyAuto : public Auto {
public:
	HeavyAuto(int cost) : Auto(cost) {}
	std::string type() const;
};

class LightAuto : public Auto {
public:
	LightAuto(int cost) : Auto(cost) {}
	std::string type() const;
};