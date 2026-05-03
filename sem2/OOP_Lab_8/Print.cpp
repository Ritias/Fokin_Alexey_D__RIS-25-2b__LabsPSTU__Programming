#include "Print.h"
#include <string>
#include <iostream>
#include "Event.h"

//Basic constructors and a destructor
Print::Print() : name(""), author("") {}
Print::Print(std::string name_, std::string author_) : name(name_), author(author_) {}
Print::Print(const Print& oth) {
	name = oth.name;
	author = oth.author;
}
Print::~Print() {}

//Formatted input and output
void Print::Show() {
	std::cout << "\nName: " << name << "\nAuthor: " << author;
}
void Print::Input() {
	std::cout << "Name?\n";
	std::getline(std::cin, name);
	std::cout << "Author?\n";
	std::getline(std::cin, author);
}

//Basic getters and setters
std::string Print::getName() { return name; }
std::string Print::getAuthor() { return author; }
void Print::setName(std::string name_) { name = name_; }
void Print::setAuthor(std::string author_) { author = author_; }

//basic assignment
Print& Print::operator=(const Print& oth) {
	if (this == &oth) return *this; //self-assignment defense
	name = oth.name;
	author = oth.author;
	return *this;
}

//On an event -- give the name of a print
void Print::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		switch (e.command) {
		case cmName:
			std::cout << "name = " << getName() << std::endl;
			break;
		}
	}
}