#pragma once
#include <string>

class Pay { //class definition
private: //attributes
	std::string name_;
	double salary_;
	int bonus_;
public:
	Pay(); //default constructor
	Pay(const std::string&, double, int); //parametrized constructor
	Pay(const Pay&); //copy constructor
	~Pay(); //destructor
	//getters
	std::string getName() const;
	double getSalary() const;
	int getBonus() const;
	//setters
	void setName(const std::string&);
	void setSalary(double);
	void setBonus(int);

	void show() const; //Console output
};