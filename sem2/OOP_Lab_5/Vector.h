#pragma once
#include "Object.h"
#include <iostream>

class Vector //container class definition
{
private:
	Object** head_; //an attribute to store an array of pointers to Objects (Object is a fully abstract class and couldn't be stored directly)
	int size_; //size of the array / max size of the vector
	int cur_; //current size of the vector
public:
	//basic constructors and a destructor
	Vector();
	Vector(int);
	~Vector();
	//A method to add an element into the container
	void Add(Object*);
	//console output overload
	friend std::ostream& operator<<(std::ostream&, const Vector&);
};

