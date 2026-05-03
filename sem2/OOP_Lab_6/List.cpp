#include <iostream>
#include "List.h"

std::ostream& operator<<(std::ostream& out, const Node& l) {
	out << l.data; //A node simply outputs its data
	return out;
}
List::List() : size(0), head(nullptr), tail(nullptr), beg(Iterator()), end(Iterator()){}

List::List(int s, int k) {
	//when initializing a list we must link all nodes to each other properly
	size = s;
	//size check
	if (size == 0) {
		head = nullptr;
		tail = nullptr;
	}
	//insert nodes one by one
	else {
		Node* newNode = new Node(k, nullptr, nullptr);
		head = newNode;
		tail = newNode;
		for (int i = 1; i < size; i++) {
			Node* newNode = new Node(k, nullptr, tail);
			tail->next = newNode;
			tail = newNode;
		}
	}
	//assigning iterators
	beg.elem = head;
	end.elem = tail->next;
}
List::List(const List& l) {
	//when copying list we must create copy of each node and link it into a new list
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
	//iterators assignment
	beg = l.beg;
	end = l.end;
}
List::~List() {
	//when deleting a list we must delete list itself, all its attributes and nodes
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

List& List::operator=(const List& l) {
	if (this == &l) return *this; //self-assignment defense
	//everything else follows the principles described in the copy connstructor
	size = l.size;

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

	beg = l.beg;
	end = l.end;

	return *this;
}
int& List::operator[](int index) {
	//when recieving an index, we should iterate over a list until we find the correctly indexed element or reach the end of the list. O(n) operation
	if (index < size) {
		Node* cur = head;
		for (int i = 0; i < index; i++) {
			cur = cur->next;
		}
		return cur->data;
	}
	else {
		std::cout << "ERROR!";
		int stub;
		return stub;
	}
}
List List::operator*(const List& l) {
	//we create a new list that is as long as the shortest of two
	//and it's elements' values are equal to a multiplication of
	//values with the same indices from two multiplied lists
	List ans((size > l.size) ? l.size : size);
	Node* a = head;
	Node* b = l.head;
	Node* cur = ans.head;
	while (a && b) {
		cur->data = a->data * b->data;
		cur = cur->next;
		a = a->next;
		b = b->next;
	}
	return ans;
}
//a simple getter
int List::operator() () {
	return size;
}
//i/o overload inputs/outputs data fields of nodes
std::ostream& operator<<(std::ostream& out, const List& l) {
	Node* cur = l.head;
	for (int i = 0; i < l.size; i++) {
		out << cur->data << " ";
		cur = cur->next;
	}
	return out;
}
std::istream& operator>>(std::istream& in, List& l) {
	Node* cur = l.head;
	for (int i = 0; i < l.size; i++) {
		in >> cur->data;
		cur = cur->next;
	}
	return in;
}