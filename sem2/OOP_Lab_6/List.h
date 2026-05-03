#pragma once
#include <iostream>

struct Node { //A node of the list structure
	int data; //data storage
	Node* next; //pointers
	Node* prev;

	//utility constructors
	Node(int i) : data(i), next(nullptr), prev(nullptr) {}
	Node() : data(0), next(nullptr), prev(nullptr) {}
	Node(int i, Node* first, Node* second) : data(i), next(first), prev(second) {}
	//stylized output
	friend std::ostream& operator<<(std::ostream& out, const Node& l);
};

class Iterator { //An Iterator to itareate over a List
	friend class List;
private:
	Node* elem; //Pointer to the current element
public:
	//basic constructors
	Iterator() { elem = nullptr; }
	Iterator(const Iterator& other) { elem = other.elem; }
	//basic operations of list traversing
	bool operator==(const Iterator& other) { return elem == other.elem; }
	bool operator!=(const Iterator& other) { return elem != other.elem; }
	void operator++() { elem = elem->next; }
	void operator--() { elem = elem->prev; }
	void operator+(int n) { for (int i = 0; i < n; i++) elem = elem->next; }
	void operator-(int n) { for (int i = 0; i < n; i++) elem = elem->prev; }
	//An operator to get the value stored in the element iterator points to
	Node& operator *() const { return *elem; }
};

class List {
private: //attributes of the list
	int size; //size indicator
	Node* head; //first element of the list
	Node* tail; //last element of the list
	Iterator beg; //beginning iterator
	Iterator end; //ending iterator
public:
	//basic constructor/destructor set
	List(int s, int k = 0);
	List(const List& l);
	List();
	~List();

	//list assignment
	List& operator=(const List& l);
	//access through index
	int& operator[](int index);
	//multyplying one list by another
	List operator*(const List& l);
	//a method to get size of the list
	int operator() ();

	//accessing iteraators pointing at list ends
	Iterator first() { return beg; }
	Iterator last() { return end; }

	//i/o overload
	friend std::ostream& operator<<(std::ostream& out, const List& l);
	friend std::istream& operator>>(std::istream& in, List& l);
};