#include "Building.h"

Building::Building(string address1, int numoffloors1, Apartment** ap1):Address(address1),NumofFloors(numoffloors1) { //ctor
	if (ap1 != NULL) {
		int ApSize = NumofFloors * 2 - 2; //size of apartments
		Ap = new Apartment * [ApSize]; //allocation of array
		for (int i = 0; i < ApSize; i++) {
			Ap[i] = ap1[i];
		}
	}
	else
		Ap = NULL;
	
}

Building::Building(const Building& a) : Address(a.Address), NumofFloors(a.NumofFloors) { //copy ctor
	if (a.Ap != NULL) {
		int ApSize = NumofFloors * 2 - 2; //size of apartments
		Ap = new Apartment * [ApSize]; //allocation of array
		for (int i = 0; i < ApSize; i++) {
			Ap[i] = a.Ap[i];
		}
		delete[] a.Ap;
	}
	else
		Ap = NULL;
} 

Building::~Building() {
	if (Ap != NULL) {
		int ApSize = NumofFloors * 2 - 2; //size of apartments
		if (ApSize) {
			for (int i = 0; i < ApSize; i++) { //delete array in loop 
				delete Ap[i]; 
			}
			delete[] Ap;
		}
	}
}

void Building::print()const { //print methoud for class
	if (Ap != NULL) {
		int ApSize = NumofFloors * 2 - 2; //size of apartments
		cout << endl;
		cout << "List of building apartments: " << endl;
		cout << endl;
		for (int i = 0; i < ApSize; i++) { //prints the apartments in loop
			cout << "Apartment " << i + 1 << ":" << endl;
			cout << endl;
			cout << typeid(*(Ap)[i]).name() << endl; //prints class name 
			Ap[i]->print();
			cout << endl;
		}
	}
	else {
		cout << "Error, empty building" << endl;
	}
}

Building& Building::operator=(const Building& a) { // operator = methoud
	if (this != &a) {
		Address = a.Address;
		NumofFloors = a.NumofFloors;
		int ApSize = NumofFloors * 2 - 2; //size of apartments
		if (a.Ap != NULL) {
			Ap = new Apartment * [ApSize]; //allocation of array
			for (int i = 0; i < ApSize; i++) { //allocation of array in loop 
				Ap[i] = a.Ap[i];
			}
		}
		else
			Ap = NULL;
	}
	return *this;
}

int Building::getFloors() { //get methoud for NumofFloor
	return NumofFloors;
}

string Building::getAddress() { //get methoud for Address
	return Address;
}

Apartment** Building::getAp() { // get apartments
	return Ap;
}