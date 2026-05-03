#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;

void foo1(Person& p) { //function to check whether we could pass a Student (child) into a Person (parent) function - we could
	p.setName("Alex");
	cout << p << "\n";
}
Person foo2() { //a function to check whether we could intialize a Person (parent) object with Student (child) function - we could
	Student r("Bob", 20, "Math", 5);
	return r;
}

int main()
{
	//basic manipulations (parent) test
    Person a;
	cin >> a;
	cout << a << "\n";
	Person b("Alice", 30);
	cout << b << "\n";
	a = b;
	cout << a << "\n";
	//basic manipulations (child) test
	Student s;
	cin >> s;
	cout << s << "\n";
	s.isGradeOkay();

	//check functions defined above
	foo1(s);
	a = foo2();
	cout << a << "\n";

	return 0;
}