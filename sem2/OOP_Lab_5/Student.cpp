#include "LabOOP5/Student.h"

Student::Student() : Person(), subject_(""), grade_(0) {}
Student::Student(std::string s, int i, std::string s2, int i2) : Person(s, i), subject_(s2), grade_(i2) {};
Student::Student(const Student& other) {
	name_ = other.name_;
	age_ = other.age_;
	subject_ = other.subject_;
	grade_ = other.grade_;
}

Student::~Student() {}

std::string Student::getSubject() const {
	return subject_;
}
int Student::getGrade() const {
	return grade_;
}

void Student::setSubject(std::string subject) {
	subject_ = subject;
}
void Student::setGrade(int grade) {
	grade_ = grade;
}

Student& Student::operator=(const Student& other) {
	if (this != &other) {
		name_ = other.name_;
		age_ = other.age_;
		subject_ = other.subject_;
		grade_ = other.grade_;
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Student& s) {
	std::cout << "Enter name: ";
	in >> s.name_;
	std::cout << "Enter age: "; in >> s.age_;
	std::cout << "Enter subject: ";
	in >> s.subject_;
	std::cout << "Enter grade: "; in >> s.grade_;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Student& s) {
	out << "Name: " << s.name_ << ", Age: " << s.age_ << ", Subject: " << s.subject_ << ", Grade: " << s.grade_;
	return out;
}

bool Student::isGradeOkay() const {
	if (grade_ <= 2) {
		std::cout << "That's a bad grade!\n";
	}
	return grade_ > 2;
}

void Student::Show() {
	std::cout << "Name: " << name_ << ", Age: " << age_ << ", Subject: " << subject_ << ", Grade: " << grade_ << std::endl;
}