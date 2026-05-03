#include "Lab1.h"
#include <iostream>
using namespace std;

fraction make_fraction(double f, int s) { //make_ function to create an object of the user type
	fraction res;
	res.Init(f, s);
	return res;
}

int main() {
	fraction A;
	fraction B;
	A.Init(3.0, 2); //An example object
	B.Read(); //Checking functionality of readers and showers
	A.Show();
	B.Show();
	cout << "A.Power(" << A.first << ", " << A.second << ") = " << A.Power() << "\n"; //A test of Power() function
	cout << "B.Power(" << B.first << ", " << B.second << ") = " << B.Power() << "\n";

	fraction* X = new fraction; //Pointer to an object
	X->Init(2.0, 5); //Same methods but with a different method of access
	X->Show();
	X->Power();
	cout << "X.Power(" << X->first << ", " << X->second << ") = " << X->Power() << "\n"; //Testing power for pointer object
	delete X;

	fraction arr[3]; //Array of the user type
	for (int i = 0; i < 3; i++) {
		arr[i].Read(); //Read into array
	}
	for (int i = 0; i < 3; i++) {
		arr[i].Show(); //Showing an array
	}
	for (int i = 0; i < 3; i++) {
		arr[i].Power(); //Powering array elements
		cout << "arr[" << i << "].Power(" << arr[i].first << ", " << arr[i].second << ") = " << arr[i].Power() << "\n";
	}

	fraction* p_arr = new fraction[3]; //Same as before, but this is an array of pointers
	for (int i = 0; i < 3; i++) {
		p_arr[i].Read();
	}
	for (int i = 0; i < 3; i++) {
		p_arr[i].Show();
	}
	for (int i = 0; i < 3; i++) {
		p_arr[i].Power();
		cout << "p_arr[" << i << "].Power(" << p_arr[i].first << ", " << p_arr[i].second << ") = " << p_arr[i].Power() << "\n";
	}
	delete[] p_arr; //Cleaning memory up

	double y;
	int z;
	cout << "\nfirst: "; cin >> y;
	cout << "\nsecond: "; cin >> z;
	fraction F = make_fraction(y, z); //Checking how make_ function works
	F.Show();

	fraction J;
	J.Init(2.0, 3);
	for (int i = 0; i < 5; i++) {
		cout << "J.element(" << i << ") = " << J.element(i) << "\n"; //Checking if variant-defined element() function works
	}

	return 0;
}