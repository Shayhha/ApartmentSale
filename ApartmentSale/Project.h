#ifndef _Project_H
#define _Project_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Building.h"


using namespace std;

class Project {
private:
	string PrName;
	int NumofBuildings;
	Building** Bl;
public:
	Project(string PrName1 = "Unknown", int NumofBuildings1 = 0, Building** Bl1 = NULL); //ctor
	Project(const Project& a); //copy ctor
	~Project();//dtor
	void print()const;
	Project& operator +=(Building* a);
	int PrintNumAp(string ad);
	string getPrName(); //get methoud
	Building** getBl(); //get methoud
	int getNumofBuildings(); //get methoud
};
#endif