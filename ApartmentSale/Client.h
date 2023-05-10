#ifndef _Client_H
#define _Client_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person.h"
#include "Apartment.h"
#include "ApStandard.h"
#include "ApGarden.h"
#include "ApPenthouse.h"
#include "Date.h"


using namespace std;

class Client: public Person { //Client class (son)
private:
	static int ClientNum;
	int Budget;
	Apartment** ClientAp;
	Date** DateOfPurchase;
	int NumOfApPurchased;
	int ClientIndex; //parameter for client index

public:
	Client(string firstname1="Unknown", string lastname1="Unknown", int budget1 = 0, Apartment** ClientAp1 = NULL, Date** DateOfPurchase1 = NULL, int NumOfApPurchased1 = 0); //ctor
	Client(const Client& a);
	void print()const;
    ~Client(); //dtor
	Client& operator=(const Client& a); // operator = methoud
	Client& AddAP(Apartment* a, Date* b); //methoud to add new apartment with date of purchase
	int* Arnona(); //methoud to return us the arnona for every apartment in array
	Apartment** GetClientAp(); //get methoud for clientAP

	int NumOfStandardAp()const; //get methoud of number of standard ap
	int NumOfGardenAp()const;  //get methoud of number of garden ap
	int NumOfPenthouseAp()const; //get methoud of number of penthouse ap

	//methouds that get month and gives the number of apartments in that month
	int NumOfStandardAp(int month1)const;
	int NumOfGardenAp(int month1)const;
	int NumOfPenthouseAp(int month1)const;
	int getClientIndex(); // get methoud
	int getBudget(); //get methoud
	int getNumOfApPurchased(); //get methoud
	Date** GetDateOfPurchase(); //get methoud
	void setNewBudget(int a); //set methoud
};
#endif