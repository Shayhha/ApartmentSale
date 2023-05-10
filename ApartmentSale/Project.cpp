#include "Project.h"

Project::Project(string PrName1, int NumofBuildings1, Building** Bl1): PrName(PrName1), NumofBuildings(NumofBuildings1) {
	if (NumofBuildings > 0 && Bl1 !=NULL) {
		Bl = new Building * [NumofBuildings]; //allocation of array
		for (int i = 0; i < NumofBuildings; i++) {
			Bl[i] = Bl1[i];
		}
	}
	else {
		Bl = NULL;
	}
}

Project::Project(const Project& a) : PrName(a.PrName), NumofBuildings(a.NumofBuildings) {//copy ctor
	Bl = new Building * [NumofBuildings]; //allocation of array
	for (int i = 0; i < NumofBuildings; i++) {
		Bl[i] = a.Bl[i];
	}
}

Project::~Project() {
	if (NumofBuildings && Bl!=NULL) {
		for (int i = 0; i < NumofBuildings; i++) { //delete array in loop 
			delete Bl[i];
		}
		delete[] Bl;
	}
}

void Project::print()const { //print methoud for class
	if (NumofBuildings && Bl != NULL) {
		cout << endl;
		cout << "Project name: " << PrName << endl;
		cout << endl;
		cout << "List of buildings: " << endl;
		cout << endl;
		for (int i = 0; i < NumofBuildings; i++) { //prints the apartments in loop
			cout << "Building " << i + 1 << ":" << endl;
			cout << endl;
			Bl[i]->print();
			cout << endl;
		}
	}
	else
		cout << "Project: " << PrName << " has no building."<<endl;
}

Project& Project::operator += (Building* a) { // += operator to add a building
	if (a->getFloors() >= 3 && a != NULL) { //if true building has at least 3 floors and we add it
		Building** temp = new Building * [NumofBuildings + 1];
		int i=0;
		if (Bl != NULL) { //if not null we copy the array with temp and insert the new building
			for (i; i < NumofBuildings; i++) {
				temp[i] = Bl[i];
			}
			temp[i] = a;
			NumofBuildings++;
			delete[] Bl;
			Bl = temp;
		}
		else { //else array is empty and we add the object array in first index withoud loop
			temp[0] = a;
			Bl = temp;
			NumofBuildings++;
		}
    }
	
    return *this;
}

int Project::PrintNumAp(string ad) { //prints the building with the same name, else return -1
	for (int i = 0; i < NumofBuildings; i++) {
		if (Bl[i]->getAddress() == ad) { //if true prints the number of apartments in building
			cout << "Number of apartments in building " << ad << ": " << Bl[i]->getFloors() * 2 - 2 << endl;
			return 0;
		}
	}
	return -1;
}

string Project::getPrName() { //get methoud for PrName
	return PrName;
}

Building** Project::getBl() { // get methoud for Bl
	return Bl;
}

int Project::getNumofBuildings() { // get methoud for NumofBuildings
	return NumofBuildings;
}