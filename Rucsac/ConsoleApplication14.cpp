#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <vector>

int main()
{
	std::mt19937 gen(time(0));
	int n, m;
	std::cin >> n >> m;
	std::vector <std::pair<int, int> > things(n);
	std::uniform_int_distribution<int> dist(1, m);
	for (int i = 0; i < n; i++) {
		things[i].first = dist(gen);
		things[i].second = dist(gen);
	}
	for (const auto& v : things) {
		std::cout << v.first << " " << v.second << std::endl;
	}
	for (int i = 0; i < things.size(); ++i) {
		if (things[i].second > m) {
			things.erase(things.begin() + i); i = 0;
		}
	}
	std::sort(things.begin(), things.end(), [](const auto& a, const auto& b) {
		return static_cast<double>(a.first) / (a.second) > static_cast<double>(b.first) / (b.second);
		});
	std::cout << std::endl;
	for (const auto& v : things) {
		std::cout << v.first << " " << v.second << std::endl;
	}
	std::vector<bool> bestes(n);
	std::vector<bool> x(n);
	std::uniform_int_distribution<int> dist1(0, 1);
	int best = 0;
	for (int i = 0; i < 200000; i++) {
		for (int j = 0; j < std::min(n,20); j++) {
			x[j] = dist1(gen);
		}
		int current = 0;
		int weight = 0;
		for (int j = 0; j < std::min(n,20); j++) {
			if (x[j]) {
				weight += things[j].second;
				current += things[j].first;
			}
		}
		if (weight < m) {
			if (current > best) {
				best = current;
				bestes = x;
			}
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < bestes.size();i++) {
		if (bestes[i])
			std::cout << i<<" ";
	}
}
