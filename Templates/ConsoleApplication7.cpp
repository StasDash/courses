#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

/**************************************************************************/
template<typename T>
constexpr T sum(const T a, const T b) {
	return std::max(a, b);
}

template<>
std::string sum(const std::string a, const std::string b) {
	return a.size() > b.size() ? a : b;
}


/**************************************************************************/
template<typename T, int size>
constexpr T sum(const T(&arr)[size]) {
	if (size == 0) return 0;
	if (size == 1) return arr[0];
	if (size == 2) return sum(arr[0], arr[1]);
	T max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

template<int size>
std::string sum(const std::string(&arr)[size]) {
	if (size == 0) return "";
	if (size == 1) return arr[0];
	if (size == 2) return sum(arr[0], arr[1]);
	std::string max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i].size() > max) {
			max = arr[i];
		}
	}
	return max;
}

/**************************************************************************/
template<typename T>
constexpr T sum(const std::vector<T>& arr) {
	if (arr.size() == 0) return 0;
	if (arr.size() == 1) return arr[0];
	if (arr.size() == 2) return sum(arr[0], arr[1]);
	T max = arr[0];
	for (T el : arr) {
		if (el > max) {
			max = el;
		}
	}
	return max;
}

template<>
std::string sum(const std::vector<std::string>& arr) {

	if (arr.size() == 0) return "";
	if (arr.size() == 1) return arr[0];
	if (arr.size() == 2) return sum(arr[0], arr[1]);
	std::string max = arr[0];
	for (auto el : arr) {
		if (el.size() > max.size()) {
			max = el;
		}
	}
	return max;
}

/**************************************************************************/
template<typename T>
constexpr T sum(std::initializer_list<T>&& arr) {
	std::vector<T> array = arr;
	return sum(array);
}

template<>
std::string sum(std::initializer_list<std::string>&& arr) {
	std::vector<std::string> array = arr;
	return sum(array);
}

/**************************************************************************/
int main()
{
	std::vector<int> a = { 4, 5, 6, 7, 7 };
	int arr[4] = { 4,5,6,9 };
	std::cout << sum(a) << " " << sum(5, 4) << " " << sum({ 6,5,4,3,2,1 }) << " " << sum(arr) << std::endl;
	std::vector<std::string> b = { "max","well", "gg" };
	std::cout << sum(b) << " " <<
		sum(std::string("max"), std::string("gg")) << " " <<
		sum({ std::string("max"),std::string("welyl"), std::string("gg") }) << std::endl;
}
