#include <iostream>
#include "LabOOP5/Person.h"
#include "LabOOP5/Student.h"
#include "LabOOP5/Vector.h"
using namespace std;

int main()
{
	//from here - repeat of tests from the Lab 4
	Person a;
	cin >> a;
	cout << a << "\n";
	Person b("Alice", 30);
	cout << b << "\n";
	a = b;
	cout << a << "\n";

	Student s;
	cin >> s;
	cout << s << "\n";
	s.isGradeOkay();
	//from here - original test
	Vector v(5); //initializing a Vector object
	//Initializing a Person and a Student - both share heritage with Object
	Person q;
	cin >> q;
	Student w;
	cin >> w;

	Object* p = &q; //creating a pointer to our Person
	v.Add(p); // add Person
	p = &b; //now points to a Student
	v.Add(p); // add Student
	cout << v; //Vector output
	return 0;
}