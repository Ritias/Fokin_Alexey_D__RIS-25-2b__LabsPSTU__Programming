#include "Magazin.h"
#include <string>
#include <iostream>

//Basic constructors and a destructor
Magazin::Magazin() : Print(), pages(0) {}
Magazin::Magazin(std::string s1, std::string s2, int p) : Print(s1, s2), pages(p) {}
Magazin::Magazin(const Magazin& oth) {
	name = oth.name;
	author = oth.author;
	pages = oth.pages;
}

Magazin::~Magazin() {}

//Formatted input and output
void Magazin::Show() {
	std::cout << "Name: " << name << "\nAuthor: " << author << "\nPages: " << pages;
}
void Magazin::Input() {
	std::cout << "Name?\n";
	std::getline(std::cin, name);
	std::cout << "Author?\n";
	std::getline(std::cin, author);
	std::cout << "Pages?\n";
	std::string buf;
	std::getline(std::cin, buf);
	pages = std::stoi(buf); //convert string input to integer
}

//Basic getters and setters
int Magazin::getPages() { return pages; }
void Magazin::setPages(int p) { pages = p; }

//Assignment operator with self-assignment defense
Magazin& Magazin::operator=(const Magazin& oth) {
	if (&oth == this) return *this;
	name = oth.name;
	author = oth.author;
	pages = oth.pages;
	return *this;
}