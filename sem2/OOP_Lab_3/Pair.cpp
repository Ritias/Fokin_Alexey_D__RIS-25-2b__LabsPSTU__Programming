#include "Pair.h"
#include <iostream>
using namespace std;

Pair& Pair::operator= (const Pair& p) { //overloading '='
	if (this == &p) return *this; //to avoid self-assignment
	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair::operator-(const Pair& p) { //subtration overload
	Pair temp;
	//subtracting both attributes separately
	temp.first = first - p.first;
	temp.second = second - p.second;
	return temp;
}

Pair Pair::operator+(int n) {
	Pair temp;
	//if we're adding 'int', add it to the first attribute
	temp.first = first + n;
	temp.second = second;
	return temp;
}

Pair Pair::operator+(double n) {
	Pair temp;
	//if we're adding 'double', add it to the second attribute
	temp.first = first;
	temp.second = second + n;
	return temp;
}
//overload of console i/o to make it stylized
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