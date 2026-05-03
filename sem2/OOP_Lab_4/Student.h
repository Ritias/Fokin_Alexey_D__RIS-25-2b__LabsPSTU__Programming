#pragma once
#include "Person.h"

class Student :
    public Person //inheriting class definition
{
protected: //additional attributes
    std::string subject_;
	int grade_;
public:
	//class-specific constructors
    Student();
	Student(std::string, int, std::string, int);
	Student(const Student&);

	~Student(); //class-specific destructor

	//additional getters
	std::string getSubject() const;
	int getGrade() const;
	//additional setters
	void setSubject(std::string);
	void setGrade(int);
	//grade-checking method
	bool isGradeOkay() const;
	//assignment overload
	Student& operator=(const Student&);
	//stylized i/o overload
	friend std::istream& operator>>(std::istream&, Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
};

