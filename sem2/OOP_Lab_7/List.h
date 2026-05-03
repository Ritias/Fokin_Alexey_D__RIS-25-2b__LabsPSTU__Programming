#pragma once
#include <iostream>
//Forward declaration to ensure friend methods work properly
template <class T>
class List;
//forward declarations of said methods
template <class T>
std::ostream& operator<<(std::ostream&, const List<T>&);
template <class T>
std::istream& operator>>(std::istream&, List<T>&);

//Declaration of Node and List (Except for template usage)
//everything else behaves similiar to Lab 6
//And iterators are abscent
template <class T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;

	Node(T i) : data(i), next(nullptr), prev(nullptr) {}
	Node() : data(T()), next(nullptr), prev(nullptr) {}
	Node(T i, Node<T>* first, Node<T>* second) : data(i), next(first), prev(second) {}

	friend std::ostream& operator<<(std::ostream& out, const Node<T>& l);
};
template <class T>
class List {
private:
	int size;
	Node<T>* head;
	Node<T>* tail;
public:
	List(int s, T k = T());
	List(const List<T>& l);
	~List();

	List<T>& operator=(const List<T>& l);
	T& operator[](int index);
	List<T> operator*(const List<T>& l);
	//+n?
	int operator() ();

	friend std::ostream& operator<< <>(std::ostream& out, const List<T>& l);
	friend std::istream& operator>> <>(std::istream& in, List<T>& l);
};

//Realization of methods now sits in .h file due to template-specific behavior
template <class T>
std::ostream& operator<<(std::ostream& out, const Node<T>& l) {
	out << l.data;
	return out;
}
template <class T>
List<T>::List(int s, T k) {
	size = s;
	if (size == 0) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<T>* newNode = new Node<T>(k, nullptr, nullptr);
		head = newNode;
		tail = newNode;
		for (int i = 1; i < size; i++) {
			Node<T>* newNode = new Node<T>(k, nullptr, tail);
			tail->next = newNode;
			tail = newNode;
		}
	}
}
template <class T>
List<T>::List(const List& l) {
	Node<T>* cur = l.head;

	while (cur) {
		Node<T>* to_add = new Node<T>(cur->data);
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
template <class T>
List<T>::~List() {
	Node<T>* cur = head;
	Node<T>* buf;
	while (cur) {
		buf = cur;
		cur = cur->next;
		delete buf;
	}
	head = nullptr;
	tail = nullptr;
}
template <class T>
List<T>& List<T>::operator=(const List<T>& l) {
	if (this == &l) return *this;
	size = l.size;

	if (head) {
		Node<T>* cur = head;
		Node<T>* buf;
		while (cur) {
			buf = cur;
			cur = cur->next;
			delete buf;
		}
		head = nullptr;
		tail = nullptr;
	}

	Node<T>* cur = l.head;
	for (int i = 0; i < size; i++) {
		Node<T>* to_add = new Node<T>(cur->data);
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
template <class T>
T& List<T>::operator[](int index) {
	if (index < size) {
		Node<T>* cur = head;
		for (int i = 0; i < index; i++) {
			cur = cur->next;
		}
		return cur->data;
	}
	else {
		std::cout << "ERROR!";
		T stub;
		return stub;
	}
}
template <class T>
List<T> List<T>::operator*(const List<T>& l) {
	List<T> ans((size > l.size) ? l.size : size);
	Node<T>* a = head;
	Node<T>* b = l.head;
	Node<T>* cur = ans.head;
	while (a && b) {
		cur->data = a->data * b->data;
		cur = cur->next;
		a = a->next;
		b = b->next;
	}
	return ans;
}
template <class T>
int List<T>::operator() () {
	return size;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const List<T>& l) {
	Node<T>* cur = l.head;
	for (int i = 0; i < l.size; i++) {
		out << cur->data << " ";
		cur = cur->next;
	}
	return out;
}
template <class T>
std::istream& operator>>(std::istream& in, List<T>& l) {
	Node<T>* cur = l.head;
	for (int i = 0; i < l.size; i++) {
		in >> cur->data;
		cur = cur->next;
	}
	return in;
}