#ifndef _ApGarden_H
#define _ApGarden_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;

class ApGarden : public Apartment { //Apgarden class (son)
private:
	int sizeOfGarden;
	bool isPool;
public:
	ApGarden(int apNun = 0, int apFl = 0, int apSize = 0, bool ifsold1 = false, int sizeOfGarden1 = 0, bool isPool1 = false);//ctor
	ApGarden(const ApGarden& a);//copy ctor
	int PriceofAp();
	void print();
	~ApGarden() {} //dtor for class
	ApGarden& operator=(const ApGarden& a);

};
#endif