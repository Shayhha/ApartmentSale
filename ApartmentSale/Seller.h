#ifndef _Seller_H
#define _Seller_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person.h"
#include "Client.h"
#include "Project.h"

using namespace std;

class Seller: public Person { // son class of person
private:
	Project* SellerProject;
	Client** SellerClients;
	int NumofClients;

public:
	Seller(string firstname1= "Unknown", string lastname1 = "Unknown", Project* SellerProject1 =NULL, Client** SellerClients1 =NULL, int NumofClients1=0); //ctor
	Seller(const Seller& a); //copy ctor
	~Seller(); //dtor
	void print()const;
	int HowManyApSold(int month1);
	int SellerPayment(int month1);
	Seller& operator += (Client* a); // += operator to add a client
	int NumofStandartApSold()const; //get num of standard apartments sold
	int NumofGardenApSold()const; //get num of Garden apartments sold
	int NumofPethouseApSold()const; //get num of Penthouse apartments sold

	//methouds that get month and give the amount of apartment sold
	int NumofStandartApSold(int month1)const; 
	int NumofGardenApSold(int month1)const; 
	int NumofPethouseApSold(int month1)const; 
	int getNumofClients();
	Project* getSellerProject(); // get methoud for seller project
	Client** getSellerClients(); // get methoud for seller cliets
};
#endif