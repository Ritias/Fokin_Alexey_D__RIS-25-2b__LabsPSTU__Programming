#pragma once

struct fraction { // struct itself /
	double first;
	int second;

	void Init(double, int); //Initializer/constructor method
	void Read(); //Stylized input from console
	void Show(); //Stylized output into console
	double Power(); //A function to power the first attribute by second
	double element(int); //A function to find an element of the sequence
};