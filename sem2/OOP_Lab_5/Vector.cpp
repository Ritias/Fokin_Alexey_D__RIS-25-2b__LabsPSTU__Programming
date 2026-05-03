#include "LabOOP5/Vector.h"

Vector::Vector() : head_(nullptr), size_(0), cur_(0) {}
Vector::Vector(int size) : head_(new Object* [size]), size_(size), cur_(0) {}

Vector::~Vector() { //when destructing we should delete pointers that are stored in the array
	if (head_ != nullptr) {
		delete[] head_;
		head_ = nullptr;
	}
}

void Vector::Add(Object* obj) {
	if (cur_ < size_) { //if we still haven't hit the maximum, add the element to the end of the array, then move our integer-pointer to the next position
		head_[cur_] = obj;
		cur_++;
	}
	else {
		std::cout << "Vector is full. Cannot add more objects.\n";
	}
}

//console output overload
std::ostream& operator<<(std::ostream& out, const Vector& v) {
	if (v.size_ == 0) {
		out << "Vector is empty.\n";
		return out;
	}
	Object** c = v.head_;
	for (int i = 0; i < v.cur_; i++) { //if the vector isn't empty we show each element of the array, one by one
		(*c)->Show();
		c++;
	}
	return out;
}