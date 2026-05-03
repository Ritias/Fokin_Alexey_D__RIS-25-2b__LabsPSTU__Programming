#include "Lab1.h"
#include <iostream>
#include <cmath>

void fraction::Init(double f, int s) {
	first = f;
	second = s;
}

void fraction::Read() {
	std::cout << "\nfirst: "; std::cin >> first;
	std::cout << "\nsecond: "; std::cin >> second;
}

void fraction::Show() {
	std::cout << "\nfirst = " << first << "\nsecond = " << second << "\n";
}

double fraction::Power() {
	return std::pow(first, second); //Standard <cmath> powering
}

double fraction::element(int j) {
	return first * std::pow(second, j); //Finding an element using the variant defined formula
}