#include "Seller.h"

Seller::Seller(string firstname1, string lastname1, Project* SellerProject1, Client** SellerClients1, int NumofClients1):Person(firstname1, lastname1),NumofClients(NumofClients1) {
	
	SellerProject = SellerProject1; 
	if (SellerClients1 != NULL) {
		SellerClients = new Client * [NumofClients]; //allocation of memeory
		for (int i = 0; i < NumofClients; i++) { //copys the adresses
			SellerClients[i] = SellerClients1[i];
		}
	}
	else
		SellerClients = NULL;
}

Seller::Seller (const Seller& a): Person(a), NumofClients(a.NumofClients) { //copy ctor
	SellerProject = a.SellerProject;
	if (a.SellerClients != NULL) {
		SellerClients = new Client * [NumofClients];
		for (int i = 0; i < NumofClients; i++) {
			SellerClients[i] = a.SellerClients[i];
		}
	}
	else
		SellerClients = NULL;
}

Seller::~Seller() { //dtor
	if (SellerClients != NULL) {
		for (int i = 0; i < NumofClients; i++) {
			delete SellerClients[i];
		}
		delete[] SellerClients;
	}
}

void Seller::print()const { //print methoud for seller
	cout << "Seller ";
	Person::print();
	cout << endl;
	cout << "Project info: ....." << endl;
	SellerProject->print();
	cout << endl;
	if (SellerClients != NULL) { //if true seller has clients and we print them
		cout << "Seller clients: " <<NumofClients<< endl;
		cout << "List of clients: ....." << endl;
		cout << endl;
		for (int i = 0; i < NumofClients; i++) {
			SellerClients[i]->print();
		}

		cout << endl;
		cout << "Seller " << firstName << " " << lastName << " has sold this amount of apartments: " << endl;
		cout << "Standard apartments: " << NumofStandartApSold() << endl;
		cout << "Garden apartments: " << NumofGardenApSold() << endl;
		cout << "Penthouse apartments: " << NumofPethouseApSold() << endl;
		cout << endl;
	}
	else { //else we print a message
		cout << "Seller "<<firstName<<" "<<lastName<<" doesn't have clients yet." << endl;
		cout << endl;
	}
	
}

int Seller::NumofStandartApSold()const { //get num of standard apartments sold
	int standard = 0;
	for (int i = 0; i < NumofClients; i++) {
		standard += SellerClients[i]->NumOfStandardAp();
	}
	return standard;
}

int Seller::NumofStandartApSold(int month1)const { //get num of standard apartments sold in specific month
	int standard = 0;
	for (int i = 0; i < NumofClients; i++) {
		standard += SellerClients[i]->NumOfStandardAp(month1);
	}
	return standard;
}

int Seller::NumofGardenApSold()const { //get num of Garden apartments sold
	int garden = 0;
	for (int i = 0; i < NumofClients; i++) {
		garden += SellerClients[i]->NumOfGardenAp();
	}
	return garden;
}

int Seller::NumofGardenApSold(int month1)const { //get num of Garden apartments sold in specific month
	int garden = 0;
	for (int i = 0; i < NumofClients; i++) {
		garden += SellerClients[i]->NumOfGardenAp(month1);
	}
	return garden;
}

int Seller::NumofPethouseApSold()const { //get num of penthouse apartments sold
	int penthouse = 0;
	for (int i = 0; i < NumofClients; i++) {
		penthouse += SellerClients[i]->NumOfPenthouseAp();
	}
	return penthouse;
}

int Seller::NumofPethouseApSold(int month1)const { //get num of penthouse apartments sold in specific month
	int penthouse = 0;
	for (int i = 0; i < NumofClients; i++) {
		penthouse += SellerClients[i]->NumOfPenthouseAp(month1);
	}
	return penthouse;
}

int Seller::SellerPayment(int month1) { //methoud for sellers payment for a specific month
	return NumofStandartApSold(month1) * 1000 + NumofPethouseApSold(month1) * 1500 + NumofGardenApSold(month1) * 2000;
}

int Seller::HowManyApSold(int month1) { //methoud for amount of apartments sold in a specific month
	return NumofStandartApSold(month1) + NumofPethouseApSold(month1) + NumofGardenApSold(month1);
}


Seller& Seller::operator += (Client* a) { // += operator to add a Client
	if (a->GetClientAp() != NULL) { //if true the client purchased an apartment from seller and we add him to array
		Client** temp = new Client * [NumofClients+1];
		int i = 0;
		if (SellerClients != NULL) {//if not null we copy the array with temp and insert the new array 
			for (i; i < NumofClients; i++) {
				temp[i] = SellerClients[i];
			}
			temp[i] = a;
			NumofClients++;
			delete[] SellerClients;
			SellerClients = temp;
		}
		else { //else array is empty and we add the object array in first index withoud loop
			temp[0] = a;
			SellerClients = temp;
			NumofClients++;
		}
	}
	return *this;
}

int Seller::getNumofClients() { //get methoud
	return NumofClients;
}

Project* Seller::getSellerProject() { // get methoud
	return SellerProject;
}

Client** Seller::getSellerClients() { // get methoud
	return SellerClients;
}