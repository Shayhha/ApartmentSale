#ifndef _Apartment_H
#define _Apartment_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Apartment { //apartment class (father)
protected:
	int ApartmentNum;
	int ApartmentFloor;
	int ApartmentSize;
	bool ifSold;
public:
	Apartment(int apNun=0, int apFl=0, int apSize=0, bool ifsold1=false);
	Apartment(const Apartment& a);
	virtual int PriceofAp() = 0; //virtual methoud of sons later
	virtual void print();
	virtual ~Apartment() {}; //dtor
	Apartment& operator=(const Apartment& a); // operator = methoud
	int getFloor(); //get methoud
	int getApartmentSize(); //get methoud
	void setifSold(bool a); // set methoud for ifsold
	bool getifSold(); //get methoud for ifsold
	int getApartmentNum(); //get methoud for apartment number
};
#endif