#include "Client.h"

int Client::ClientNum = 1;

Client::Client(string firstname1, string lastname1, int budget1, Apartment** ClientAp1, Date** DateOfPurchase1, int NumOfApPurchased1) :Person(firstname1, lastname1), Budget(budget1), NumOfApPurchased(NumOfApPurchased1) { //ctor
	Client::ClientNum++; 
	ClientIndex = ClientNum - 1; //gets client index
	if (ClientAp1 != NULL && DateOfPurchase1 != NULL) { //if true means we need to allocate that arrays
		ClientAp = new Apartment * [NumOfApPurchased];
		DateOfPurchase = new Date * [NumOfApPurchased];
		for (int i = 0; i < NumOfApPurchased; i++) {
			ClientAp[i] = ClientAp1[i];
			DateOfPurchase[i] = DateOfPurchase1[i];
		}
	}
	else { //else the arrays are empty
		ClientAp = NULL;
		DateOfPurchase = NULL;
	}
} 

Client::Client(const Client& a):Person(a.firstName, a.lastName), Budget(a.Budget), NumOfApPurchased(a.NumOfApPurchased) { //copy ctor
	ClientIndex = ClientNum - 1; //gets client index
	if (a.ClientAp != NULL && a.DateOfPurchase != NULL) { //if true means we need to allocate that arrays
		ClientAp = new Apartment * [NumOfApPurchased];
		DateOfPurchase = new Date * [NumOfApPurchased];
		for (int i = 0; i < NumOfApPurchased; i++) {
			ClientAp[i] = a.ClientAp[i];
			DateOfPurchase[i] = a.DateOfPurchase[i];
		}
	}
	else { //else the arrays are empty
		ClientAp = NULL;
		DateOfPurchase = NULL;
	}
} 

Client::~Client() { //dtor
	if (ClientAp != NULL && DateOfPurchase != NULL) { //if true means we need to delete arrays
		for (int i = 0; i < NumOfApPurchased; i++) {
			if (ClientAp[i] != NULL && DateOfPurchase[i] != NULL) {
				delete ClientAp[i];
				delete DateOfPurchase[i];
			}
		}
		delete[] ClientAp;
		delete[] DateOfPurchase;
	}
}

void Client::print()const { //print methoud for class
	cout << "Client ";
	Person::print(); //calls father's print
	cout << "Client number: " << ClientIndex << endl;
	cout << "Budget: " << Budget<<endl;
	if (ClientAp != NULL && DateOfPurchase != NULL) { //if true prints the apartments that he bought
		cout << "Client purchased apartments: ..... " << endl;
		cout << endl;
		for (int i = 0; i < NumOfApPurchased; i++) {
			ClientAp[i]->print();
			cout << "Date of purchase: ";
			DateOfPurchase[i]->print();
			cout << endl;
		}
	}
}

Client& Client::operator=(const Client& a) { //operator = methoud
	ClientIndex - ClientNum - 1; //gets client index
	if (this != &a) {
		Budget = a.Budget;
		NumOfApPurchased = a.NumOfApPurchased;

		if (a.ClientAp != NULL && a.DateOfPurchase != NULL) { //if true we reminating the arrays
			ClientAp = new Apartment * [NumOfApPurchased];
			DateOfPurchase = new Date * [NumOfApPurchased];
			for (int i = 0; i < NumOfApPurchased; i++) {
				ClientAp[i] = a.ClientAp[i];
				DateOfPurchase[i] = a.DateOfPurchase[i];
			}
		}
		else { //else the arrays are empty
			ClientAp = NULL;
			DateOfPurchase = NULL;
		}
	}
	return *this;
}

Client& Client::AddAP(Apartment* a, Date *b) { //methoud add apartment to array (gets date as well)
	NumOfApPurchased++;
	Apartment** temp = new Apartment * [NumOfApPurchased]; //allocation of apartment array
	Date** temp2 = new Date * [NumOfApPurchased]; //allocation of Date array

	for (int i = 0; i < NumOfApPurchased - 1; i++) {//copy with temps
		temp[i] = ClientAp[i];
		temp2[i] = DateOfPurchase[i];
	}
	temp[NumOfApPurchased - 1] = a;
	temp2[NumOfApPurchased - 1] = b;
	delete[] ClientAp; //delete memory
	delete[] DateOfPurchase; //delete memory
	ClientAp = temp; //gives address to ClientAP
	DateOfPurchase = temp2; //gives address to DateOfPurchase
	return *this;
}

int* Client::Arnona() { //Arnona methoud
	int* Ar;
	if (NumOfApPurchased > 0 && ClientAp != NULL) { //if true client has purchased apartments
		Ar = new int[NumOfApPurchased]; // allocation of memory
		int ApType=(-1), SizeOfAp, ApStBl = 0;
		for (int i = 0; i < NumOfApPurchased; i++) { //goes in loop and finds right Ap types with RTTI
			SizeOfAp = ClientAp[i]->getApartmentSize(); //gets the apartment size
			ApStandard* Ap = dynamic_cast<ApStandard*>(ClientAp[i]);
			if (Ap) {
				ApType = 0;
				if (Ap->getNumofBalcony() == 2) //if true we have 2 balconys in apartment
					ApStBl = 1;
			}
			ApGarden* Ap1 = dynamic_cast<ApGarden*>(ClientAp[i]);
			if (Ap1) {
				ApType = 2;
			}
			ApPenthouse* Ap2 = dynamic_cast<ApPenthouse*>(ClientAp[i]);
			if (Ap2) {
				ApType = 1;
			}
			Ar[i] = ApType * 120 + ApStBl * 300 + SizeOfAp * 25; //clac of the arnona for Ar[i]
		}
		return Ar;
	}
	else { //else we returning an empty array
		Ar = NULL;
		return Ar;
	}
}

int Client::NumOfStandardAp()const { //gets the number of standard apartments
	int count = 0;
	for (int i = 0; i < NumOfApPurchased; i++) { //goes in loop and finds right Ap types with RTTI
		ApStandard* Ap = dynamic_cast<ApStandard*>(ClientAp[i]);
		if (Ap) { //if true we count the standard apartments
			count++;
		}
	}
	return count;
}

int Client::NumOfStandardAp(int month1)const { //gets the number of standard apartments sold in a specific month
	int count = 0;
	for (int i = 0; i < NumOfApPurchased; i++) { //goes in loop and finds right Ap types with RTTI
		ApStandard* Ap = dynamic_cast<ApStandard*>(ClientAp[i]);
		if (Ap && DateOfPurchase[i]->getMonth()==month1) { //if true we count the standard apartments
			count++;
		}
	}
	return count;
}

int Client::NumOfGardenAp()const { //gets the number of garden apartments
	int count = 0;
	for (int i = 0; i < NumOfApPurchased; i++) { //goes in loop and finds right Ap types with RTTI
		ApGarden* Ap = dynamic_cast<ApGarden*>(ClientAp[i]);
		if (Ap) { //if true we count the Garden apartments
			count++;
		}
	}
	return count;
}

int Client::NumOfGardenAp(int month1)const { //gets the number of garden apartments sold in a specific month
	int count = 0;
	for (int i = 0; i < NumOfApPurchased; i++) { //goes in loop and finds right Ap types with RTTI
		ApGarden* Ap = dynamic_cast<ApGarden*>(ClientAp[i]);
		if (Ap && DateOfPurchase[i]->getMonth() == month1) { //if true we count the Garden apartments
			count++;
		}
	}
	return count;
}

int Client::NumOfPenthouseAp()const { //gets the number of penthouse apartments
	int count = 0;
	for (int i = 0; i < NumOfApPurchased; i++) { //goes in loop and finds right Ap types with RTTI
		ApPenthouse* Ap = dynamic_cast<ApPenthouse*>(ClientAp[i]);
		if (Ap) { //if true we count the Penthouse apartments
			count++;
		}
	}
	return count;
}

int Client::NumOfPenthouseAp(int month1)const { //gets the number of penthouse apartments sold in a specific month
	int count = 0;
	for (int i = 0; i < NumOfApPurchased; i++) { //goes in loop and finds right Ap types with RTTI
		ApPenthouse* Ap = dynamic_cast<ApPenthouse*>(ClientAp[i]);
		if (Ap && DateOfPurchase[i]->getMonth() == month1) { //if true we count the Penthouse apartments
			count++;
		}
	}
	return count;
}

Apartment** Client::GetClientAp() { //get methoud for clientAP
	return ClientAp;
}

Date** Client::GetDateOfPurchase() {
	return DateOfPurchase;
}

int Client::getClientIndex() { //get methoud for ClientIndex
	return ClientIndex;
}
int Client::getBudget() { //get methoud for Budget
	return Budget;
}
int Client::getNumOfApPurchased() { //get methoud for numberofappurchased
	return NumOfApPurchased;
}

void Client::setNewBudget(int a) {
	Budget -= a;
}