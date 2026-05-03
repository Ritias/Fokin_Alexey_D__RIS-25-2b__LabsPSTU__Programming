#pragma once
#include "Object.h"
#include <iostream>

//Node structure for doubly linked list
struct Node {
	Object * data;
	Node* next;
	Node* prev;

	//Node constructors with different initialization patterns
	Node(Object * i) : data(i), next(nullptr), prev(nullptr) {}
	Node() : data(nullptr), next(nullptr), prev(nullptr) {}
	Node(Object * i, Node* first, Node* second) : data(i), next(first), prev(second) {}
};

class List {
protected:
	int size;      //current number of elements
	Node* head;    //pointer to first element
	Node* tail;    //pointer to last element

public:
	//Basic constructors and destructor
	List();
	List(int s);
	List(const List& l);
	~List();

	//Assignment operator
	List& operator=(const List& l);

	//List operations
	void Add();
	void Del();
	void Show();

	//Event handling
	void HandleEvent(const TEvent& e);

	//Returns list size
	int operator() ();
};