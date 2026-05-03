#pragma once
#include "Object.h"
#include <string>
#include <iostream>

class Person : public Object { //Same class definition as in Lab 4, now inheriting from Object
protected:
	std::string name_;
	int age_;
public:
	Person();
	Person(std::string, int);
	Person(const Person&);
	virtual ~Person();

	std::string getName() const;
	int getAge() const;

	void setName(std::string);
	void setAge(int);

	Person& operator=(const Person&);

	friend std::istream& operator>>(std::istream&, Person&);
	friend std::ostream& operator<<(std::ostream&, const Person&);

	void Show();
};

