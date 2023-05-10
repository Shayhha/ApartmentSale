#include "Date.h"


Date::Date(int day1, int month1, int year1) { //ctor
	
    if (day1 > 30) {
        day = 00;
    }
    else
        day = day1;
	
    if (month1 > 30) {
        month = 00;
    }
    else
        month = month1;
	
	year = year1;

}
void Date::print() { //print methoud
	cout << day << "/" << month << "/" << year << endl;
}
void Date::printmonth(int month2) { //prints month
    switch (month2) {
    case 1:
        cout << "January";
        break;
    case 2:
        cout << "February";
        break;
    case 3:
        cout << "March";
        break;
    case 4:
        cout << "April";
        break;
    case 5:
        cout << "May";
        break;
    case 6:
        cout << "June";
        break;
    case 7:
        cout << "July";
        break;
    case 8:
        cout << "Agoust";
        break;
    case 9:
        cout << "September";
        break;
    case 10:
        cout << "October";
        break;
    case 11:
        cout << "November";
        break;
    case 12:
        cout << "December";
            break;
        defualt: 
            cout << "Error";
    }
}
int Date::returnday(int month1) { //returns day or month
    switch (month1)
    {
    case 1:
        return 31;
        break;

    case 2:
        return 28;
        break;

    case 3:
        return 31;
        break;

    case 4:
        return 30;
        break;

    case 5:
        return 31;
        break;

    case 6:
        return 30;
        break;

    case 7:
        return 31;
        break;

    case 8:
        return 31;
        break;

    case 9:
        return 30;
        break;

    case 10:
        return 31;
        break;

    case 11:
        return 30;
        break;

    case 12:
        return 31;
        break;


    default:
        cout << "BIG OOF !";
        return 0;
        break;
    }
}
bool Date::ismeobar() { //checks if meobar
    if ((year % 4 == 0 && year % 100 == 1) || (year % 4 == 0)) {
        return true;
    }
    return false;
}
void Date::check() {
    
    if (returnday(month) >= day) {
        day++;
        cout<<"Next day "<< day << "/" << month << "/" << year << endl;
    }
}