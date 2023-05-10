#include "ApStandard.h"

ApStandard::ApStandard(int apNun, int apFl, int apSize, bool ifsold1, int NumofBalcony1, int* balconySize1) :Apartment(apNun, apFl, apSize, ifsold1) {//ctor
	NumofBalcony = NumofBalcony1;

	if (NumofBalcony <= 2 && NumofBalcony >= 0) { //if true it means that given values are currect
		balconySize = new int[NumofBalcony]; //allocation of new array
		for (int i = 0; i < NumofBalcony; i++) {
			balconySize[i] = balconySize1[i];
		}
	}
	else { //else treminating the array to null
		NumofBalcony = 0;
		balconySize = NULL;
	}
}

ApStandard::ApStandard(const ApStandard& a) :Apartment(a) { //copy ctor
	this->NumofBalcony = a.NumofBalcony;
	if (a.balconySize != NULL) {
		balconySize = new int[NumofBalcony]; //allocation of new array
		for (int i = 0; i < NumofBalcony; i++) {
			balconySize[i] = a.balconySize[i];
		}
	}
	else { //else treminating the array to null
		balconySize = NULL;
	}
}

int ApStandard::PriceofAp() { //price of apartment
	return 300000 + NumofBalcony * 12000 + ApartmentFloor * 300 + ApartmentSize * 500;
}

ApStandard::~ApStandard() { //dtor
	if (balconySize != NULL) { //checks if the array is empty
		delete[] balconySize;
	}
}

void ApStandard::print() { //print methoud for class
	Apartment::print();
	cout << "Number of balconies: " << NumofBalcony << endl;
	if (NumofBalcony > 0) { //if true prints apartment balcony sizes
		cout << "Size of balconies: ........ " << endl;
		for (int i = 0; i < NumofBalcony; i++) {
			cout << "Balcony num " << i + 1 << ", size: " << balconySize[i] << endl;
		}
	}
	cout << "Price of apartment: " << PriceofAp() << endl;
	cout << endl;
	cout << endl;
}

ApStandard& ApStandard::operator=(const ApStandard& a) { // operator = methoud
	if (this != &a) {
		Apartment::operator=(a);
		NumofBalcony = a.NumofBalcony;
		balconySize = new int[NumofBalcony];
		for (int i = 0; i < NumofBalcony; i++) {
			balconySize[i] = a.balconySize[i];
		}
	}
	return *this;
}

int ApStandard::getNumofBalcony() { //get methoud
	return NumofBalcony;
}

