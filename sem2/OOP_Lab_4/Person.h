#pragma once
#include <string>
#include <iostream>

class Person { //basic class
protected: //class attributes
	std::string name_;
	int age_;
public:
	Person(); //default constructor
	Person(std::string, int); //constructor with parameters
	Person(const Person&); //copy constructor
	virtual ~Person(); //destructor

	//basic getters
	std::string getName() const;
	int getAge() const;
	//basic setters
	void setName(std::string);
	void setAge(int);
	//assignment operator overload
	Person& operator=(const Person&);
	//console i/o overload
	friend std::istream& operator>>(std::istream&, Person&);
	friend std::ostream& operator<<(std::ostream&, const Person&);
};

