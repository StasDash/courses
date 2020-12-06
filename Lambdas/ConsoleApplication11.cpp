#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;
	std::vector<int> gg;
	auto ini = [](std::vector<int>& vec, int n, int k = 0) {
		for (int i = k; i < n + k + 1; i++)
			vec.push_back(i);
	};

	auto ini2 = [](std::vector<int>& vec, int k = 0) {
		vec.erase(vec.begin(), vec.begin() + k);
		for (int i = 0; i < k; i++)
			vec.push_back(vec[vec.size() - 1] + 1);
	};
	ini(vec, 4);
	for (int c : vec) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	ini2(vec, 2);

	for (int c : vec) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
}