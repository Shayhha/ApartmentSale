#include "ApPenthouse.h"

//ctor
ApPenthouse::ApPenthouse(int apNun, int apFl, int apSize, bool ifsold1, int PenthouseBalSize1) :Apartment(apNun, apFl, apSize, ifsold1), PenthouseBalSize(PenthouseBalSize1){}
	
ApPenthouse::ApPenthouse(const ApPenthouse& a) : Apartment(a), PenthouseBalSize(a.PenthouseBalSize){} //copy ctor

int ApPenthouse::PriceofAp() { //price for penthouse
	return 700000 + ApartmentSize * 600 + PenthouseBalSize * 200;
}

void ApPenthouse::print() { //print methoud for class
	Apartment::print();
	cout << "size of penthouse balcony: " << PenthouseBalSize << endl;
	cout << "Price of apartment: " << PriceofAp() << endl;
	cout << endl;
	cout << endl;
}

ApPenthouse& ApPenthouse::operator=(const ApPenthouse& a) { // operator = methoud
	if (this != &a) {
		Apartment::operator=(a);
		this->PenthouseBalSize = a.PenthouseBalSize;
		
	}
	return *this;
}