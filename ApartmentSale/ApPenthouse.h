#ifndef _ApPenthouse_H
#define _ApPenthouse_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;

class ApPenthouse : public Apartment { //ApPenthouse class (son)
private:
	int PenthouseBalSize;
public:
	ApPenthouse(int apNun = 0, int apFl = 0, int apSize = 0, bool ifsold1 = false, int PenthouseBalSize1 = 0);//ctor
	ApPenthouse(const ApPenthouse& a);//copy ctor
	int PriceofAp();
	void print();
	~ApPenthouse() {} //dtor for class
	ApPenthouse& operator=(const ApPenthouse& a);

};
#endif