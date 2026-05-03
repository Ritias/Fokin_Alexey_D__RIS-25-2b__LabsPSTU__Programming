#include "Pair.h"
#include <iostream>
using namespace std;

//Pair behaves almost exactly like the one described in previous labs
Pair& Pair::operator= (const Pair& p) {
	if (this == &p) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair::operator-(const Pair& p) {
	Pair temp;
	temp.first = first - p.first;
	temp.second = second - p.second;
	return temp;
}

Pair Pair::operator+(int n) {
	Pair temp;
	temp.first = first + n;
	temp.second = second;
	return temp;
}

Pair Pair::operator+(double n) {
	Pair temp;
	temp.first = first;
	temp.second = second + n;
	return temp;
}
Pair Pair::operator*(const Pair& p) {
	Pair temp;
	temp.first = first * p.first;
	temp.second = second * p.second;
	return temp;
}

istream& operator>> (istream& in, Pair& p) {
	cout << "Enter first: ";
	in >> p.first;
	cout << "Enter second: ";
	in >> p.second;
	return in;
}
ostream& operator<< (ostream& out, const Pair& p) {
	out << p.first << " : " << p.second;
	return out;
}