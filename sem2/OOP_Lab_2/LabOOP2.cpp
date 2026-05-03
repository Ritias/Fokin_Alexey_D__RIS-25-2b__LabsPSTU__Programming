#include "Pay.h"
#include <iostream>
#include <string>
using namespace std;

Pay makePay() { //make_ function to create objects of the class
	string s;
	int i;
	double d;
	cout << "Enter name: "; getline(cin, s);
	cout << "Enter salary: "; cin >> d;
	cout << "Enter bonus: "; cin >> i;
	Pay p(s, d, i);
    return p;
}

void printPay(Pay p) { //for printing into console
	p.show();
}

int main()
{
	Pay p1; //default object
	p1.show();

	Pay p2("John Doe", 50000, 10); //object with parameters
	p2.show();

	Pay p3 = p2; //copy object
	p3.show();
	p3.setName("Jane Smith"); //changing object's fields using setters
	p3.setSalary(60000);
	p3.setBonus(15);
	printPay(p3); //printing function

	p1 = makePay(); //make_ function to reach for user input
	p1.show(); //also console output
	return 0;
}