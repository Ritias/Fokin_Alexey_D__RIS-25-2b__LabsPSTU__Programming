#include <iostream>
#include <string>
#include "List.h"
#include "Print.h"
#include "Magazin.h"

//Basic constructors and destructor
List::List() : head(nullptr), tail(nullptr), size(0) {}

List::List(int s) {
	size = s;
	if (size == 0) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		//Populate list with interactive user input for each element
		for (int i = 0; i < size; i++) {
			Add();
		}
	}
}

//Copy constructor - deep copy of entire list
List::List(const List& l) {
	Node* cur = l.head;

	while (cur) {
		Node* to_add = new Node(cur->data);
		if (!head) {
			head = to_add;
			tail = to_add;
		}
		else {
			tail->next = to_add;
			tail->next->prev = tail;
			tail = to_add;
		}
		cur = cur->next;
	}
}

List::~List() {
	Node* cur = head;
	Node* buf;
	while (cur) {
		buf = cur;
		cur = cur->next;
		delete buf;
	}
	head = nullptr;
	tail = nullptr;
}

//Assignment operator with self-assignment defense
List& List::operator=(const List& l) {
	if (this == &l) return *this;
	size = l.size;

	//Clear existing list before copying
	if (head) {
		Node* cur = head;
		Node* buf;
		while (cur) {
			buf = cur;
			cur = cur->next;
			delete buf;
		}
		head = nullptr;
		tail = nullptr;
	}

	//Deep copy elements from source list
	Node* cur = l.head;
	for (int i = 0; i < size; i++) {
		Node* to_add = new Node(cur->data);
		if (!head) {
			head = to_add;
			tail = to_add;
		}
		else {
			tail->next = to_add;
			tail->next->prev = tail;
			tail = to_add;
		}
		cur = cur->next;
	}

	return *this;
}

//Returns current list size
int List::operator() () {
	return size;
}

//Add new element to the end of the list with user input
void List::Add() {
	std::string pars;
	Node* to_add = new Node();
	std::cout << "\n1. Print\n2. Magazin\nEnter 1/2: ";
	std::getline(std::cin, pars);
	int par = std::stoi(pars);
	if (par == 1) {
		Print* a = new Print();
		a->Input();
		to_add->data = a;
	}
	else if (par == 2) {
		Magazin* a = new Magazin();
		a->Input();
		to_add->data = a;
	}
	if (par > 2 || par < 1) {
		std::cout << "ERROR\n";
		return;
	}
	if (size == 0) {
		head = to_add;
		tail = to_add;
		size = 1;
		return;
	}
	to_add->prev = tail;
	tail->next = to_add;
	tail = to_add;
	size++;
}

//Delete the last element from the list
void List::Del() {
	if (size == 0) {
		std::cout << "Empty!\n";
		return;
	}
	if (size == 1) {
		delete tail;
		tail = nullptr;
		head = nullptr;
		size = 0;
		return;
	}
	tail = tail->prev;
	delete tail->next;
	tail->next = nullptr;
	size--;
}

//Display all elements in the list
void List::Show() {
	if (!head) {
		std::cout << "Empty!\n";
		return;
	}

	Node * cur = head;
	while (cur) {
		cur->data->Show();
		std::cout << '\n';
		cur = cur->next;
	}
	std::cout << '\n';
}

//Assign event to all elements in the list
void List::HandleEvent(const TEvent &e) {
	if (!head) {
		std::cout << "Empty!\n";
		return;
	}

	Node* cur = head;
	while (cur) {
		cur->data->HandleEvent(e);
		cur = cur->next;
	}
}