#include "ApGarden.h"

ApGarden::ApGarden(int apNun, int apFl, int apSize, bool ifsold1, int sizeOfGarden1, bool isPool1) :Apartment(apNun, apFl, apSize, ifsold1) { //ctor
	sizeOfGarden = sizeOfGarden1;
	isPool = isPool1;
}

ApGarden::ApGarden(const ApGarden &a) : Apartment(a) { //copy sctor
	this->sizeOfGarden = a.sizeOfGarden;
	this->isPool = a.isPool;
}

int ApGarden::PriceofAp() { //pirce of apartment methoud 
	if (isPool) { //if true it means we add pool's value as well
		return 600000 + ApartmentSize * 600 + 100000;
	}
	else {
		return 600000 + ApartmentSize * 600;
	}
}

void ApGarden::print() {//print for class
	Apartment::print(); //print of 'father' class
	cout << "Garden size: " << sizeOfGarden << endl; 
	if (isPool) //if true prints that apartment has pool
		cout << "Apartment has a pool" << endl;
	else
		cout << "Apartment doesn't have a pool" << endl;

	cout << "Price of apartment: " << PriceofAp() << endl;
	cout << endl;
	cout << endl;
}

ApGarden& ApGarden::operator=(const ApGarden& a) { // operator = methoud
	if (this != &a) {
		Apartment::operator=(a);
		this->sizeOfGarden = a.sizeOfGarden;
		this->isPool = a.isPool;
	}
	return *this;
}