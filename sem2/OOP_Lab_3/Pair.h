#pragma once
#include <iostream>

class Pair { //class definition
private:
	int first;
	double second;
public:
	Pair() { first = 0; second = 0.0; }; //default constructor
	Pair(int f, double s) { first = f; second = s; } //constructor with parameters
	Pair(const Pair& p) { first = p.first; second = p.second;} //copy constructor
	~Pair() {}; //destructor
	//basic getters
	int getFirst() const { return first; }
	double getSecond() const { return second; }
	//basic setters
	void setFirst(int f) { first = f; }
	void setSecond(double s) { second = s; }
	//basic operations overload
	Pair& operator= (const Pair& p);
	Pair operator-(const Pair&);
	Pair operator+(int);
	Pair operator+(double);
	//console i/o overload
	friend std::istream& operator>> (std::istream& in, Pair& p);
	friend std::ostream& operator<< (std::ostream& out, const Pair& p);
};