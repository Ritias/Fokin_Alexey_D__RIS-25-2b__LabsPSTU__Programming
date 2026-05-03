#pragma once
#include <iostream>

//Pair behaves almost exactly like the one described in previous labs
class Pair {
private:
	int first;
	double second;
public:
	Pair() { first = 0; second = 0.0; };
	Pair(int f, double s) { first = f; second = s; }
	Pair(const Pair& p) { first = p.first; second = p.second;}
	virtual ~Pair() {};

	int getFirst() const { return first; }
	double getSecond() const { return second; }

	void setFirst(int f) { first = f; }
	void setSecond(double s) { second = s; }

	Pair& operator= (const Pair&);
	Pair operator-(const Pair&);
	Pair operator+(int);
	Pair operator+(double);
	Pair operator*(const Pair&);

	friend std::istream& operator>> (std::istream& in, Pair& p);
	friend std::ostream& operator<< (std::ostream& out, const Pair& p);
};