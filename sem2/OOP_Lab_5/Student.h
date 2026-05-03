#pragma once
#include "Person.h"

class Student : //Same class definition as Lab 4
    public Person
{
protected:
    std::string subject_;
	int grade_;
public:
    Student();
	Student(std::string, int, std::string, int);
	Student(const Student&);

	~Student();

	std::string getSubject() const;
	int getGrade() const;

	void setSubject(std::string);
	void setGrade(int);

	bool isGradeOkay() const;

	Student& operator=(const Student&);

	friend std::istream& operator>>(std::istream&, Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);

	void Show();
};

