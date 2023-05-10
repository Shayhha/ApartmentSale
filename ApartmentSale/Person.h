#ifndef _Person_H
#define _Person_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person {
protected:
	string firstName;
	string lastName;
public:
	Person(string a = "NULL", string b = "NULL"); //ctor + defualt ctor
	Person(const Person& p); //copy ctor
	virtual ~Person();
	virtual void print()const;
	string getfirstname(); //get methoud
	string getlastname(); //get methoud
};
#endif