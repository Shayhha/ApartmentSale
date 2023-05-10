#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Date { //date class
private:
	int day;
	int month;
	int year;
public:
	Date() //default ctor
	{
		time_t rawtime;
		struct tm* timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		day = timeinfo->tm_mday;
		month = timeinfo->tm_mon + 1;
		year = timeinfo->tm_year + 1900;
	} 
	//methouds 
	void setDay(int d) { day = d; };
	void setMonth(int m) { month = m; };
	void setYear(int y) { year = y; };
	int getDay() { return day; };
	int getMonth() { return month; };
	int getYear() { return year; };
	Date(int day1, int month1, int year1);
	void print();
	void printmonth(int month2);
	int returnday(int month1);
	bool ismeobar();
	~Date() {}//dtor
	void check();
	bool operator ==(const Date& sec)const {
		return day == sec.day && month == sec.month && year == sec.year;
	}
};
 