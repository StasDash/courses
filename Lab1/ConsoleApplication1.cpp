
#include <iostream>
#include <algorithm>
#include <vector>
#include "Student.h"

int main()
{
	std::cout << "Hello World!\n";

	int n;
	std::cin >> n;
	std::vector<Student> students(n);

	for (Student& student : students)
		std::cin >> student;

	std::sort(students.begin(), students.end());

	std::cout << "Sorted\n";

	for (Student& student : students)
		std::cout << student;
}
