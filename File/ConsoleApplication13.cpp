#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Human.h"


int main()
{
	setlocale(LC_ALL, "");
	std::vector<Human> humans;
	int n;
	std::cin >> n;
	while (n != 0) {
		if (n == 1) {
			std::ifstream db("db.txt", std::ios::in);
			int j;
			db >> j;
			humans.resize(j);
			for (Human &hum: humans)
				db >> hum;
		}
		else if (n == 2) {
			for (Human& hum : humans) {
				std::cout << hum;
			}
		}
		else if (n == 3) {
			std::cout << "Enter data: ";
			Human h;
			std::cin >> h;
			humans.push_back(h);
		}
		else if (n == 4) {
			std::sort(humans.begin(), humans.end(), [](const Human& a, const Human& b) {
				const std::string& first = a.get_lastname();
				const std::string& sec = b.get_lastname();
				return first < sec;
				});
		}
		if (n == 5) {
			std::sort(humans.begin(), humans.end(), Human::byAge);
		}
		else if (n == 6) {
			int month;
			std::cin >> month;
			for (const Human& hum : humans) {
				if (hum.get_month() == month)
					std::cout << hum;
			}
		}
		else if (n == 7) {
			int age = INT32_MAX;
			std::string last_name = "";
			for (const Human& hum : humans) {
				if (hum.get_sex() == "F")
					continue;

				if (age > hum.get_age()) {
					age = hum.get_age();
					last_name = hum.get_lastname();
				}
			}
			std::cout << last_name << std::endl;
		}
		else if (n == 8) {
			char sym;
			std::cin >> sym;
			for (const Human& hum : humans) {
				if (hum.get_lastname()[0] == sym)
					std::cout << hum.get_lastname()<<std::endl;
			}
		}
		std::cin >> n;
	}

	std::ofstream db("db.txt", std::ios::out);
	db << humans.size() << std::endl;
	for (Human& hum : humans)
		db << hum;
}
