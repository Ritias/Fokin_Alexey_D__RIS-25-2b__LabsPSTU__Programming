#include "Pay.h"
#include <string>
#include <iostream>
using namespace std;

Pay::Pay() { //default constructor
	name_ = "";
	salary_ = 0;
	bonus_ = 0;
}
Pay::Pay(const string& name, double salary, int bonus) { //constructor with parameters
	name_ = name;
	salary_ = salary;
	bonus_ = bonus;
}
Pay::Pay(const Pay& other) { //copy constructor
	name_ = other.name_;
	salary_ = other.salary_;
	bonus_ = other.bonus_;
}

Pay::~Pay() {} //destructor
//basic getters of private attributes
string Pay::getName() const {
	return name_;
}
double Pay::getSalary() const {
	return salary_;
}
int Pay::getBonus() const {
	return bonus_;
}
//basic setters of private attributes
void Pay::setName(const string& name) {
	name_ = name;
}
void Pay::setSalary(double salary) {
	salary_ = salary;
}
void Pay::setBonus(int bonus) {
	bonus_ = bonus;
}
//Console output method
void Pay::show() const {
	cout << "Name: " << name_ << endl;
	cout << "Salary: " << salary_ << endl;
	cout << "Bonus: " << bonus_ << endl;
}