#include <iostream>
#include "List.h"
#include "Pair.h"

using namespace std;

int main()
{
    /*
    Same tests as in Lab 6. Commented due to simplicity

    List<int> a(5, 0);
    cout << a << "\n";
    cin >> a;
    cout << a << "\n";
    a[2] = 40;
    cout << a << "\n";
    List<int> b(10);
    b = a;
    cout << b << "\n";
    List<int> c(10);
    c = b * b;
    cout << c << "\n";
    cout << "Size of c: " << c() << endl;*/

    Pair p;
	cin >> p; //Initializing a Pair
	cout << p << "\n";
    List<Pair> a(5, p); //Filling a List with said Pair
	cout << a << "\n"; //Printing a list
	cin >> a; //Filling a list from console
	cout << a << "\n"; //Printing a list

	List<Pair> b(10); //Initializing a list of ten default elements
	b = a; //assigning a to b
	cout << b << "\n"; //Printing a list
	cout << b[3] << "\n"; //Printing an element by index
	cout << "Size of b: " << b() << endl; //Printing size

    b = a * a; // Making elements of b equal to elements of a squared
	cout << b << "\n";
}