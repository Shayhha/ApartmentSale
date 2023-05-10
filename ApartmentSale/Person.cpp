#include "Person.h"

Person::Person(string a, string b): firstName(a), lastName(b){} //ctor

Person::Person(const Person& p) { //copy ctor
	this->firstName = p.firstName;
	this->lastName = p.lastName;
}

Person::~Person() {} //dtor

void Person::print()const { //print for class
	cout << "Name: " << firstName << " " << lastName << endl;
}

string Person::getfirstname() { //get methoud
	return firstName;
}
string Person::getlastname() { //get methoud
	return lastName;
}
