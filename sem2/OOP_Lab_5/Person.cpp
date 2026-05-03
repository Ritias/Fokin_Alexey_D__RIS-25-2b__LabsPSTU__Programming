#include "LabOOP5/Person.h"
#include <string>
#include <iostream>

Person::Person() : name_(""), age_(0) {}
Person::Person(std::string name, int age) : name_(name), age_(age) {}
Person::Person(const Person& other) : name_(other.name_), age_(other.age_) {}

Person::~Person() {}

std::string Person::getName() const {
	return name_;
}
int Person::getAge() const {
	return age_;
}
void Person::setName(std::string name) {
	name_ = name;
}
void Person::setAge(int age) {
	age_ = age;
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		name_ = other.name_;
		age_ = other.age_;
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Person& person) {
	std::cout << "Enter name: ";
	in >> person.name_;
	std::cout << "Enter age: ";
	in >> person.age_;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Person& person) {
	out << "Name: " << person.name_ << ", Age: " << person.age_;
	return out;
}
void Person::Show() {
	std::cout << "Name: " << name_ << ", Age: " << age_ << std::endl;
}