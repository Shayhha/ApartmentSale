#include "Marketing.h"

Marketing::Marketing() { //default ctor
	SizeofApartments = 4;
	SizeofProjects = 1;
	SizeOfPeople = 1;
	apartments = new Apartment * [SizeofApartments]; // default apartments
	apartments[0] = new ApGarden(1, 0, 500, false, 250, true);
	apartments[1] = new ApStandard(2, 1, 300, false);
	apartments[2] = new ApStandard(3, 1, 300, false);
	apartments[3] = new ApPenthouse(4, 2, 450, false, 150);

	Building** BL = new Building*[1]; //default building
	BL[0] = new Building("minkof", 3, apartments);

	projects = new Project * [SizeofProjects]; //default project
	projects[0] = new Project("sami", 1, BL);

	people = new Person * [SizeOfPeople];
	people[0] = new Seller("sami", "shamoon", projects[0]); //default seller 

}

Marketing::~Marketing() { //dtor
	Seller* SL = NULL;

	if (projects != NULL) { //if true we delete projects array and meanwhile building dtor delete's apartments
		for (int j = 0; j < SizeofProjects; j++) {
			delete projects[j];
		}
		delete[] projects;
	}

	if (people != NULL) { //if true we delete people array
		for (int i = 0; i < SizeOfPeople; i++) { //we go through the array of people to find sellers(sellers deletig clients)
			SL = dynamic_cast<Seller*>(people[i]);
			if (SL && SL->getNumofClients() == 0) { //if seller has no clients we delete him
				delete SL;
			}
			else if (SL && SL->getNumofClients() > 0) { //else seller has clients so we need to address the apartments situation
				for (int k = 0; k < SL->getNumofClients(); k++) { //we go through the loops and delete DateOfPurchase array
					for (int t = 0; t < SL->getSellerClients()[k]->getNumOfApPurchased(); t++) {
						delete SL->getSellerClients()[k]->GetDateOfPurchase()[t];
					}
					delete[] SL->getSellerClients()[k]->GetDateOfPurchase(); //we delete DateOfPurchase array 
					delete[] SL->getSellerClients()[k]->GetClientAp(); //we delete clients array allocation
				}
			}
		}
		delete[] people;
	}
}

void Marketing::Menu() {
	int choice, buff=0, buff2=0;
	int flag = 0;
	string name, address;
	string firstname2, lastname2;
	Project* PR = NULL;
	Building* BL = NULL;
	ApStandard* AP = NULL;
	Apartment* A = NULL;
	Seller* SE = NULL;
	Client* CL = NULL ,*CL2 = NULL, *CLBuff = NULL;
	ApPenthouse* PN = NULL;
	//Date
	Date* date = NULL;
	int day1, month1, year1;

do{
	do{
	   //print options
        cout << endl;
	    cout << "Please choose an option: " << endl;
	    cout << endl;
	    cout << "1 - Print clients who purchased standard apartments." << endl;
	    cout << "2 - Add building." << endl;
	    cout << "3 - Add project." << endl;
	    cout << "4 - Add seller." << endl;
	    cout << "5 - Add client." << endl;
	    cout << "6 - Print apartment with number and building address." << endl;
	    cout << "7 - Print standard apartments with two balconies that has't sold." << endl;
	    cout << "8 - Print payment of seller by first and last name." << endl;
	    cout << "9 - Print apartments in budget of client." << endl;
	    cout << "10 - Print penthouse apartments prices in a project." << endl;
	    cout << "11 - Sell an apartment." << endl;
	    cout << "12 - Print clients with the lowest arnona" << endl;
	    cout << "13 - Exit." << endl;
	    cout << endl;
	    cin >> choice;
	    cout << endl;

	    if (choice < 1 || choice > 13) { //if true it means user gave invalid number and tries again
		  cout << "Invalid option, try again..." << endl;
		  cout << endl;
	    }
	} while (choice < 1 || choice > 13);


	switch (choice) 
	{
	case 1: //prints clients who bought standard apartments
		cout << "The clients who purchased standard apartments: ......." << endl;
		for (int i = 0; i < SizeOfPeople; i++) {
			CL = dynamic_cast<Client*>(people[i]);
			if (CL && CL->NumOfStandardAp()>0) { //if true we print the client
				CL->print();
				flag = 1;
			}
		}
		if (flag == 0) {
			 cout << "There are no clients that bought standard apartments yet." << endl;
			 break;
		}
		break;

	case 2: //adds a building to project
		flag = 0;
		cout << "Enter project name: ";
		cin >> name;
		cout << endl;
		for (int i = 0; i < SizeofProjects; i++) {
			if (projects[i]->getPrName() == name) { //if true we found a matching name
				flag = 1;
				if (InitBuilding(projects[i]) == 1) { //calls Initbuilding
					break;
				}
			}
		}
		if (flag == 0) //if flag == 0 means no name matches the projects
			cout << "No projects found with name: " << name << endl;
		break;
		
	case 3: //add project
		flag = 0;
		cout << "Enter project name: ";
		cin >> name;
		cout << endl;
		for (int i = 0; i < SizeofProjects; i++) {
			if (projects[i]->getPrName() == name) {
				cout << "Project already exists." << endl;
				flag = 1;
			}
		}
		if (flag == 1) //if true project exists and we break
			break;
		
		cout << "Enter how many buildings: ";
		cin >> buff;
		cout << endl;
		if (buff < 1) {
			cout << "Invalid number of buildings" << endl;
			break;
		}
		if (InitProject(name, buff) == 1) {
			break;
		}
		break;

	case 4: //add seller
		if (InitSeller() == 1) {
			break;
		}
		break;

	case 5: //add client
		if (InitClient() == 1) {
			break;
		}
		break;

	case 6: //print apartment with number and building address
		flag = 0;
		cout << "Please enter number of apartment: " << endl;
		cin >> buff;
		cout << "Please enter building address: " << endl;
		cin >> name;
		cout << endl;
		for (int i = 0; i < SizeofProjects; i++) { //goes through all building and finds if address exists
			for (int j = 0; j < projects[i]->getNumofBuildings(); j++) {
				if (projects[i]->getBl()[j]->getAddress() == name) {
					BL = projects[i]->getBl()[j]; //we keep the building address for later
					flag = 1;
				}
			}
		}
		if (flag == 0) { //if true no building was found and we print and exit
			cout << "No building with the address: " << name << endl;
			break;
		}
		
		flag = 0;
		for (int k = 0; k < BL->getFloors()*2-2; k++) { //we go through all apartments and we print the right one
			if (BL->getAp()[k]->getApartmentNum() == buff) {
				BL->getAp()[k]->print();
				flag = 1;
			}
		}
		if (flag == 0) { //if true no apartment with matching number found
			cout << "No apartment number " << buff << " in building " << name << endl;
			break;
		}
		break;

	case 7: // print standard apartments with two balconies that has't sold
		flag = 0;
		for (int i = 0; i < SizeofApartments; i++) {
			AP = dynamic_cast<ApStandard*>(apartments[i]);
			if (AP) {
				if (AP->getNumofBalcony() == 2 && AP->getifSold() == false) { //if true we print the apartment 
					cout << endl;
					flag = 1;
					AP->print();
					
				}
			}
		}
		if (flag == 0) { //else no apartments found and we break with print
			cout << "No apartments found that have 2 balconies and not sold." << endl;
			break;
		}
		break;

	case 8: //Print payment of seller by first and last name ======(Check if works later with selling)======
		flag = 0;
		cout << "Please enter seller's first and last name: " << endl;
		cin >> firstname2;
		cin >> lastname2;
		cout << endl;
		cout << "Please enter a month: " << endl;
		cin >> buff;
		cout << endl;
		for (int i = 0; i < SizeOfPeople; i++) {
			SE = dynamic_cast<Seller*>(people[i]);
			if (SE) {
				if (SE->getfirstname() == firstname2 && SE->getlastname()==lastname2 && SE->getNumofClients()>0) { //if true we print the seller 
					cout << endl;
					flag = 1;
					cout << "Seller: " << firstname2 << " " << lastname2 << " payment for month " << buff << " is: " << SE->SellerPayment(buff);
					cout << endl;
				}
				else if (SE->getfirstname() == firstname2 && SE->getlastname() == lastname2 && SE->getNumofClients() == 0) { //else seller hasn't sold apartments, we give flag for print at the end
					flag = 2;
				}
			}
		}
		if (flag == 0) { //means no seller found
			cout << "No seller found" << endl;
			break;
		}
		else if (flag == 2) { //means seller hasn't sold apartments
			cout << "Seller has no clients, so he hasn't sold any apartments yet" << endl;
			break;
		}
		break;

	case 9: //Print apartments in budget of client
		flag = 0;
		cout << "Please enter client number: ";
		cin >> buff;
		cout << endl;
		for (int i = 0; i < SizeOfPeople; i++) { //we go through array of people to find client
			CL = dynamic_cast<Client*>(people[i]);
			if (CL) { //if found we get his budget with buff2
				if (CL->getClientIndex() == buff) {
					buff2 = CL->getBudget();
					flag = 1;
				}
			}
		}
		if (flag == 0) { //if flag is 0 it means no client found
			cout << "No client found with number " << buff << endl;
			break;
		}
		flag = 0; //terminating flag to 0
		for (int j = 0; j < SizeofApartments; j++) { //going through the array of apartments
			if (apartments[j]->PriceofAp() <= buff2 && apartments[j]->getifSold()==false) { //if true prints the apartment
				flag = 1;
				apartments[j]->print();
			}
		}
		if (flag == 0) { //if flag == 0 it means we have no apartmants matching client budget
			cout << "There are no aprtments matching client " << CL->getfirstname() << " " << CL->getlastname() << " budget." << endl;
			break;
		}
		break;

	case 10: //Print penthouse apartments prices in a project
		flag = 0;
		cout << "Please enter project name: ";
		cin >> name;
		cout << endl;
		for (int i = 0; i < SizeofProjects; i++) { //we go through all projects to find one that matches the name given
			if (projects[i]->getPrName() == name) { //if true we give the address to PR pointer
				flag = 1;
				PR = projects[i];
			}
		}
		if (flag == 0) { //if true we haven't found any matching project
			cout << "No project found with name " << name << endl;
			break;
		}
		flag = 0; //initilizing flag to 0

		for (int j = 0; j < PR->getNumofBuildings(); j++) { //we go through building array to find right apartments
			buff = PR->getBl()[j]->getFloors() * 2 - 2; //number of apartments in building index j
			for (int k = 0; k < buff; k++) {
				PN = dynamic_cast <ApPenthouse*>(PR->getBl()[j]->getAp()[k]);
				if (PN) { //if true prints the penthouse apartment 
					flag = 1;
					PN->print();
				}
			}
		}
		if (flag == 0) { //means that there are no apartments found and we print 
			cout << "There are no penthouse apartments in project " << name << endl;
			break;
		}
		break;

	case 11: //Sell an apartment
		flag = 0;
		cout << "Please enter project name: ";
		cin >> name;
		cout << endl;
		for (int i = 0; i < SizeofProjects; i++) { //we go through the array of projects to find a matching name
			if (projects[i]->getPrName() == name) { //if true we found one and we give it to pointer PR for later
				PR = projects[i];
				flag = 1;
			}
		}
		if (flag == 0) { //if we didnt find a project we print message and exit
			cout << "No project found with name " << name << endl;
			break;
		}
		flag = 0;


		for (int p = 0; p < SizeOfPeople; p++) { //we go through people array to find if there is a seller with project name
			SE = dynamic_cast<Seller*>(people[p]);
			if (SE && SE->getSellerProject()->getPrName() == name) { //if true we return flag 1
				flag = 1;
				break;
			}
		}
		if (flag == 0) { //if true we print error 
			cout << "There is no seller associated project name " << name << endl;
			break;
		}
		flag = 0; //initilazing flag to 0
		SE = NULL;

		cout << "Please enter building address: ";
		cin >> address;
		cout << endl;
		for (int j = 0; j <PR->getNumofBuildings(); j++) { //we go through array of building of PR to find matching address
			if (PR->getBl()[j]->getAddress() == address) { //if true we found one and we give it ti BL pointer
				BL = PR->getBl()[j];
				flag = 1;
			}
		}
		if (flag == 0) { //else we didnt find a building with same address and we print message and exit
			cout << "No building found with address " << address << endl;
			break;
		}
		flag = 0;

		cout << "Please enter apartment number: ";
		cin >> buff;
		cout << endl;
		for (int m = 0; m < BL->getFloors() * 2 - 2; m++) { //we go through BL to find the apartment given
			if (BL->getAp()[m]->getApartmentNum() == buff) { //if we found matching apartment we give it to A pointer of apartment
				flag = 1;
				A = BL->getAp()[m];
			}
		}
		if (flag == 0) { //else we didnt find an apartment with same number and we print message and exit
			cout << "No apartment found with number " << buff <<" in building " << address << endl;
			break;
		}
		flag = 0;

		cout << "Please enter client number: ";
		cin >> buff2;
		cout << endl;
		for (int l = 0; l < SizeOfPeople; l++) { //we go through array of people to find a client with same number
			CL = dynamic_cast<Client*>(people[l]);
			if (CL && CL->getClientIndex() == buff2) { 
				if (CL->getBudget() >= A->PriceofAp() && A->getifSold() == false) { //if true we found the right client and we break while CL has its address
					flag = 1;
					break;
				}
				else if (A->getifSold() == true) { //means apartment sold
					flag = 4;
				}
				else { //else client budget isn't enough
					flag = 2;
					break;
				}
			}
			else { //else we didn't find a client
				flag = 3;
			}
		}
		if (flag == 2) { // if true client budget isn't enough for apartment
			cout << "Apartment is out of budget of client"<< endl;
			break;
		}
		else if (flag == 4) {
			cout << "Apartment has been sold" << endl;
			break;
		}
		else if (flag == 3) { // means we didnt find a matching client and we exit
			cout << "No client found with number "<< buff2 << endl;
			break;
		}
		flag = 0;

		cout << "Please enter seller's first and last name: "<<endl;
		cin >> firstname2;
		cin >> lastname2;
		cout << endl;
		for (int t = 0; t < SizeOfPeople; t++) {
			SE = dynamic_cast<Seller*>(people[t]);
			if (SE && SE->getfirstname() == firstname2 && SE->getlastname() == lastname2) {
				if (SE->getSellerProject()->getPrName() == name) { //if true we found seller with right projet while SE has address of it
					flag = 1;
					break;
				}
				else {
					flag = 3;
					break;
				}
			}
			else {
				flag = 2;
			}
		}
		if (flag == 2) { //else we didnt find a seller and we exit
			cout << "No Seller found with name " << firstname2 <<" " <<lastname2<< endl;
			break;
		}
		else if (flag == 3) { //else means we found seller but project name isn't same
			cout << " Seller " << firstname2 << " " << lastname2 <<" doesn't have project "<< name << endl;
			break;
		}
		flag = 0;

		A->setifSold(true); // we changing the chosen apartment to "Sold"
		cout << "Enter date of purchase: " << endl;;
		cin >> day1;
		cin >> month1;
		cin >> year1;
		cout << endl;
		date = new Date(day1, month1, year1); //initilaze of date
		CL->AddAP(A, date); //adds the apartments and date to arrays of cilent
		CL->setNewBudget(A->PriceofAp()); //sets new budget for client after purchase
		*SE += CL; //adds client to array of clients of seller
		break;

		case 12: //Print clients with the lowest arnona
			flag = 0;
			for (int k = 0; k < SizeOfPeople; k++) { //we go through array of people tp find first client
				CL2 = dynamic_cast<Client*>(people[k]);
				if (CL2 && CL2->getNumOfApPurchased() == 1) { //if true we found first client and we give CLbuff his address
					CLBuff = CL2; //first client with 1 apartment
					buff = CL2->Arnona()[0]; //buff starts with arnona of client num 1
					flag = 1;
					break;
				}
				else if (CL2) {
					flag = 2;
				}
			}
			if (flag == 0) { //if true prints error
				cout << "There are no clients yet" << endl;
				break;
			}
			else if (flag == 2) { //if true no clients bought only 1 apartemnt
				cout << "No clients who bought only one apartment" << endl;
				break;
			}

			for (int i = 0; i < SizeOfPeople; i++) {
				CL = dynamic_cast<Client*>(people[i]);
				if (CL && CL->getNumOfApPurchased() == 1) {
					if (CL->Arnona()[0] < buff) {
						buff = CL->Arnona()[0];
						CLBuff = CL;
					}
				}
			}
			
			cout << "The client " << CLBuff->getfirstname() << " " << CLBuff->getlastname() << " has lowest arnona of " << buff << endl;
			cout << endl;
			cout << "Client Info: ....." << endl;
			CLBuff->print();

	case 13: //exit from menu
		break;

		
	default:
		break;
	}

	} while (choice != 13);
}

int Marketing::InitBuilding(Project* projects1) {
	string blname;
	string letter;
	int buff=0;
	int apNun1=0, apFl1=0, apSize1=0; //apartment
	bool ifsold1= false; //
	int NumofBalcony1=0; //standard
	int* balconySize1=NULL; //
	int sizeOfGarden1=0; //garden
	bool isPool1=false; //
	int PenthouseBalSize1=0; //penthouse
	//prints apartment input
	int floors = 0;

	cout << "Please enter Building address: ";
	cin >> blname;
	cout << endl;
	//we check the array of buildings by getting size of array of buildings
	for (int i = 0; i < SizeofProjects; i++) { //we go through every project and check if there's a building with the same address
		for (int j = 0; j < projects[i]->getNumofBuildings(); j++) {
			if (projects[i]->getBl()[j]->getAddress() == blname) { //if true we found one with the same name and we return 1 for error
				cout << "Building already exists in another project." << endl;
				return 1;
			}
		}
	}
	cout << "Please enter how many floors: ";
	cin >> floors;
	cout << endl;
	if (floors < 3) {
		cout << "Invalid number of floors" << endl;
		return 1;
	}
	int numofapartments = floors * 2 - 2; //num of apartments

	Apartment** NewAP = new Apartment * [numofapartments];
	cout << "Enter information for apartments: ..........." << endl;
	cout << endl;
	for (int i = 0; i < numofapartments; i++) {
		if (i == 0) { //means we input garden apartment
			cout << "Please enter a garden apartment: ............." << endl;
			cout << endl;
			if (InitApartments(&apNun1, &apFl1, &apSize1, &ifsold1, &floors) == 1) { //if true we return 1 for error
				return 1;
			}
			if (apFl1 != 0) {
				cout << "Garden apartment must be in first floor!" << endl;
				return 1;
			}
			cout << "Enter garden size: ";
			cin >> sizeOfGarden1;
			cout << endl;
			if (sizeOfGarden1 <= 0) {
				cout << "Invalid garden size." << endl;
				return 1;
			}
			cout << "Enter if has pool: (Y/N)";
			cin >> letter;
			cout << endl;
			if (letter == "Y")
				isPool1 = true;
			else if (letter == "N")
				isPool1 = false;
			else {
				cout << "Invalid option." << endl;
				return 1;
			}
			NewAP[i] = new ApGarden(apNun1, apFl1, apSize1, ifsold1, sizeOfGarden1, isPool1); //allocation of memory
			*this += NewAP[i]; // adds apartment to array of apartments
		}

		else if (i == numofapartments - 1) { //means we input a penthouse
			cout << "Please enter a penthouse apartment: ............." << endl;

			if (InitApartments(&apNun1, &apFl1, &apSize1, &ifsold1, &floors) == 1) {  //if true we return 1 for error
				return 1;
			}
			if (apFl1 != floors-1) {
				cout << "Penthouse apartment must be in " << floors - 1 << " floor!" << endl;
				return 1;
			}
			cout << "Enter penthouse balcony size: ";
			cin >> PenthouseBalSize1;
			cout << endl;
			if (PenthouseBalSize1 <= 0) {
				cout << "Invalid balcony size." << endl;
				return 1;
			}
			NewAP[i] = new ApPenthouse(apNun1, apFl1, apSize1, ifsold1, PenthouseBalSize1); //allocation of memory
			*this += NewAP[i]; // adds apartment to array of apartments
		}

		else { // means we input standard apartment
			cout << "Please enter a standard apartment: ............... " << endl;
			cout << endl;
			if (InitApartments(&apNun1, &apFl1, &apSize1, &ifsold1, &floors) == 1) {  //if true we return 1 for error
				return 1;
			}
			if (apFl1 == floors - 1 || apFl1 == 0) {
				cout << "Standard apartment can't be in first or last floors!" << endl;
				return 1;
			}
			cout << "Enter how many balconies: ";
			cin >> NumofBalcony1;
			cout << endl;
			if (NumofBalcony1 < 0 || NumofBalcony1 > 2) { //if true we return 1 for error
				cout << "Invalid number of balconies." << endl; 
				balconySize1 = NULL;
				return 1;
			}
			if (NumofBalcony1 != 0) { //if not 0 we allocate memory 
				balconySize1 = new int[NumofBalcony1]; //allocation of number of balcony

				for (int j = 0; j < NumofBalcony1; j++) { //input of size of balconies
					cout << "Enter balcony number " << j + 1 << " size:";
					cin >> buff;
					cout << endl;
					balconySize1[j] = buff;
				}
			}
			else { //else we giving array null
				balconySize1 = NULL;
			}
			NewAP[i] = new ApStandard(apNun1, apFl1, apSize1, ifsold1, NumofBalcony1, balconySize1); //allocation of memory
			*this += NewAP[i]; // adds apartment to array of apartments
		}
	}
	Building *NewBL = new Building(blname, floors, NewAP); //allocation of new building
	*projects1 += NewBL; // operator += of projects
	return 0;
}

int Marketing::InitApartments(int *apNun1, int *apFl1, int *apSize1, bool *ifsold1, int *floors1) { //init for apartments
	string letter;
	//prints apartment input
	cout << "Enter apartment number: ";
	cin >> *apNun1;
	cout << endl;
	cout << "Enter apartment floor: ";
	cin >> *apFl1;
	cout << endl;
	if (*apFl1 > *floors1 || *apFl1 < 0) { //if true we return 1 for error
		cout << "Invalid apartment floor." << endl;
		return 1;
	}
	cout << "Enter apartment size: ";
	cin >> *apSize1;
	cout << endl;
	if (*apSize1 <= 0) { //if true we return 1 for error
		cout << "Invalid apartment size." << endl;
		return 1;
	}
	cout << "Enter if apartment sold: (Y/N)";
	cin >> letter;
	cout << endl;
	if (letter == "Y")
		*ifsold1 = true;
	else if (letter == "N")
		*ifsold1 = false;
	else { //if true we return 1 for error
		cout << "Invalid option." << endl;
		return 1;
	}
	return 0;
}

int Marketing::InitProject(string name1, int numofBl) {
	
	Project* newPr = new Project(name1); //allocation of new project
	cout << "Enter info for buildings: ........." << endl;
	cout << endl;
	for (int i = 0; i < numofBl; i++) { //adds building to project
		cout << "Building num " << i + 1 << " :" << endl;
		if (InitBuilding(newPr) == 1) { 
			return 1;
		}
	}
	*this += newPr;
	return 0;
}

Marketing& Marketing::operator += (Apartment* a) { // += operator to add an apartment
	if (a != NULL) {
		Apartment** temp = new Apartment * [SizeofApartments + 1]; //allocation of memory
		int i = 0;
		if (apartments != NULL) {//if not null we copy the array with temp and insert the new Apartment 
			for (i; i < SizeofApartments; i++) {
				temp[i] = apartments[i];
			}
			temp[i] = a;
			SizeofApartments++;
			delete[] apartments;
			apartments = temp;
		}
		else { //else array is empty and we add the object array in first index withoud loop
			temp[0] = a;
			apartments = temp;
			SizeofApartments++;
		}
	}
	return *this;
}

Marketing& Marketing::operator += (Project* a) { // += operator to add an project
	if (a != NULL) {
		Project** temp = new Project * [SizeofProjects + 1];
		int i = 0;
		if (projects != NULL) {//if not null we copy the array with temp and insert the new project 
			for (i; i < SizeofProjects; i++) {
				temp[i] = projects[i];
			}
			temp[i] = a;
			SizeofProjects++;
			delete[] projects;
			projects = temp;
		}
		else { //else array is empty and we add the object array in first index withoud loop
			temp[0] = a;
			projects = temp;
			SizeofProjects++;
		}
	}
	return *this;
}

Marketing& Marketing::operator += (Person* a) { // += operator to add an project
	if (a != NULL) {
		Person** temp = new Person * [SizeOfPeople + 1];
		int i = 0;
		if (people != NULL) {//if not null we copy the array with temp and insert the new project 
			for (i; i < SizeOfPeople; i++) {
				temp[i] = people[i];
			}
			temp[i] = a;
			SizeOfPeople++;
			delete[] people;
			people = temp;
		}
		else { //else array is empty and we add the object array in first index withoud loop
			temp[0] = a;
			people = temp;
			SizeOfPeople++;
		}
	}
	return *this;
}


int Marketing::InitSeller() {
	Seller* SL = NULL, *SLbuff=NULL;
	Project* SellerPr = NULL;
	string firstname2, lastname2, nameofpr;
	int flag = 0;
	cout << "Please enter seller's first and last name: " << endl;;
	cin >> firstname2;
	cin >> lastname2;
	cout << endl;
	for (int i = 0; i < SizeOfPeople; i++) { //if we find a matching name we increase flag to 1
		SL = dynamic_cast<Seller*>(people[i]);
		if (SL && SL->getfirstname() == firstname2 && SL->getlastname() == firstname2) { //if true we return flag 1
			flag = 1;
			break;
		}

	}
	if (flag == 1) { //if true we print error and return 1
		cout << "Seller already exists." << endl;
		return 1;
	}
	flag = 0; //initilazing flag to 0

	cout << "Enter seller's project name: ";
	cin >> nameofpr;
	cout << endl;
	for (int p = 0; p < SizeOfPeople; p++) { //we go through people array to find if there is a seller with same project name
		SL = dynamic_cast<Seller*>(people[p]);
		if (SL && SL->getSellerProject()->getPrName() == nameofpr) { //if true we return flag 1
			flag = 1;
			break;
		}
	}
	if (flag == 1) { //if true we print error and return 1
		cout << "There is already seller with project name "<< nameofpr << endl;
		return 1;
	}
	flag = 0; //initilazing flag to 0

	for (int i = 0; i < SizeofProjects; i++) { //we go through the array and find the project of seller
		if (projects[i]->getPrName() == nameofpr) {
		  flag = 1;
		  SellerPr = projects[i]; //SellerPr has address of the project we need 
		  break;
		}
	}
	if (flag == 0) { //if we dont find a project with the same name we return 1 for error
		cout << "Project doesn't exists." << endl;
		return 1;
	}

	//if true means no project found with matching name and we create new one
	
	Person* NewSeller = new Seller(firstname2, lastname2, SellerPr); //allocation of seller
	*this += NewSeller; //add seller to array
	
	return 0;
}

int Marketing::InitClient() {
	Client* CL = NULL;
	string firstname2, lastname2;
	int ClBudget;
	int flag = 0;
	cout << "Please enter client's first and last name: " << endl;;
	cin >> firstname2;
	cin >> lastname2;
	cout << endl;
	for (int i = 0; i < SizeOfPeople; i++) { //if we find a matching client name we break and increase flag to 1
		CL = dynamic_cast<Client*>(people[i]);
		if (CL && CL->getfirstname() == firstname2 && CL->getlastname() == firstname2) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) { //if true we print error and return 1
		cout << "Client already exists." << endl;
		return 1;
	}
	cout << "Enter client's budget: ";
	cin >> ClBudget;
	cout << endl;
	
	 //if everything is fine we create new client
	Person* NewSeller = new Client(firstname2, lastname2, ClBudget); //allocation of memory for client
	*this += NewSeller; //add client to array

	return 0;
}
