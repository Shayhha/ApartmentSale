#ifndef _Building_H
#define _Building_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"
#include "ApStandard.h"
#include "ApGarden.h"
#include "ApPenthouse.h"

using namespace std;

class Building {
private:
	string Address;
	int NumofFloors;
	Apartment **Ap;
public:
	Building(string address1=0, int numoffloors1=0, Apartment** ap1=NULL); //ctor
	Building(const Building& a); //copy ctor
	~Building();//dtor
	void print()const;
	Building& operator=(const Building& a); // operator = methoud
	int getFloors();
	string getAddress(); // get address
	Apartment** getAp(); //get apartments
	
};
#endif