#include "Apartment.h"

Apartment::Apartment(int apNun, int apFl, int apSize, bool ifsold1) { //ctor
	ApartmentNum = apNun;
	ApartmentFloor = apFl;
	ApartmentSize = apSize;
	ifSold = ifsold1;
	
}

Apartment::Apartment(const Apartment& a) { //copy ctor
	this->ApartmentNum = a.ApartmentNum;
	this->ApartmentFloor = a.ApartmentFloor;
	this->ApartmentSize = a.ApartmentSize;
	this->ifSold = a.ifSold;
}

void Apartment::print() { //prints the apartment information
	cout << "Apartment Number: " << ApartmentNum << endl;
	cout << "Floor: " << ApartmentFloor << endl;
	cout << "Size: " << ApartmentSize << endl;
	if (ifSold == true) {
		cout << "Apartment Sold!" << endl;
	}
	else if (ifSold == false) {
		cout << "Apartment not Sold." << endl;
	}
}

Apartment& Apartment::operator=(const Apartment& a) { // operator = methoud
	if (this != &a) {
		ApartmentNum = a.ApartmentNum;
		ApartmentFloor = a.ApartmentFloor;
		ApartmentSize = a.ApartmentSize;
		ifSold = a.ifSold;
	}
	return *this;
}

int Apartment::getFloor() { //get methoud
	return ApartmentFloor;
}
int Apartment::getApartmentSize() { //get methoud
	return ApartmentSize;
}

void Apartment::setifSold(bool a) { //set methoud for ifsold
	ifSold = a;
}

bool Apartment::getifSold() { //get methoud for ifsold
	return ifSold;
}
int Apartment::getApartmentNum() { //get methoud for apartment number
	return ApartmentNum;
}