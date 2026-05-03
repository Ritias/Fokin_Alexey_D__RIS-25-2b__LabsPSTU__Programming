#include <iostream>
#include "List.h"

using namespace std;

int main()
{   
    //initializing a list of 5 elements (zeroes by default)
    List a(5);
    cout << a << "\n";
    cin >> a; //filling from console
    cout << a << "\n";
    a[2] = 40; //accessing and assigning an element by index
    cout << a << "\n";
    List b(10); //a new list of zeroes
    b = a; //copied from a
    cout << b << "\n";
    List c(10); //a new list of zeroes
    c = b * b; //equal to elements of b squared
    cout << c << "\n";
    cout << "Size of c: " << c() << endl; //size getting test
    
    cout << *(a.first()) << endl; //iterator test

    //iteration through all list's elements
    Iterator i = a.first();
        cout << *i << endl;
    for (i = a.first(); i != a.last(); ++i) cout << *i << " ";

    return 0;
}
