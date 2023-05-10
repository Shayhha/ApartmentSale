#ifndef _ApStandard_H
#define _ApStandard_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;

class ApStandard: public Apartment{ //ApStandard class (son)
private:
	int NumofBalcony;
	int* balconySize;
public:
	ApStandard(int apNun = 0, int apFl = 0, int apSize = 0, bool ifsold1 = false, int  NumofBalcony1=0, int* balconySize1= NULL);//ctor
	ApStandard(const ApStandard& a);//copy ctor
	int PriceofAp();
	void print();
	~ApStandard();//dtor
	ApStandard& operator=(const ApStandard& a);
	int getNumofBalcony(); //get methoud
		
};
#endif