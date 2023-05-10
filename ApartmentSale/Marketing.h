#ifndef _Marketing_H
#define _Marketing_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person.h"
#include "Apartment.h"
#include "ApStandard.h"
#include "ApGarden.h"
#include "ApPenthouse.h"
#include "Building.h"
#include "Project.h"
#include "Client.h"
#include "Seller.h"


using namespace std;

class Marketing {
private:
	Person** people;
	Apartment** apartments;
	Project** projects;
	int SizeOfPeople;
	int SizeofApartments;
	int SizeofProjects;
	int InitBuilding(Project* projects1); //init methoud
	int InitApartments(int* apNun1, int* apFl1, int* apSize1, bool* ifsold1, int* floors1); //init methoud
	int InitProject(string name1, int numofBl); // init methoud
	int InitSeller(); // init methoud
	int InitClient(); // init methoud
	Marketing& operator += (Apartment* a); //operator += methoud
	Marketing& operator += (Project* a); //operator += methoud
	Marketing& operator += (Person* a); //operator += methoud

public:
	Marketing(); //defualt ctor
	~Marketing(); //dtor
	void Menu();
};
#endif