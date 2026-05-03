#include "Pair.h"
#include <iostream>
using namespace std;

int main()
{
    Pair a; //three default objects
    Pair b;
    Pair c;
    cin >> a; //input of two objects from console
    cin >> b;
    a = a + 5; //modification of objects
	b = b + 2.5;
    c = a - b; //subtraction of objects, then assignment
    cout << "a: " << a << endl; //testing output
    cout << "b: " << b << endl;
	cout << "c: " << c << endl;
}