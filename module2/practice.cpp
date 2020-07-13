#include <iostream>

using namespace std;

class DayOfYear {
private:
	string month;
	int dayOfMonth, dayOfYear;
public:
	DayOfYear(string, int);
	DayOfYear(int);
	void print();
DayOfYear operator++() {
	dayOfYear += 1;
	if (dayOfYear > 365) {
		dayOfYear -= 365;
	}
    return *this;
}
DayOfYear operator--() {
	dayOfYear -= 1;
	if (dayOfYear < 0) {
		dayOfYear += 365;
	}
    return *this;
}
DayOfYear operator++(int) {
	dayOfYear += 1;
    DayOfYear temp = *this;
	if (dayOfYear > 365) {
		dayOfYear -= 365;
	}
    return temp;
}
DayOfYear operator--(int) {
	dayOfYear -= 1;
    DayOfYear temp = *this;
	if (dayOfYear < 0) {
		dayOfYear += 365;
	}
    return temp;
}
};





DayOfYear::DayOfYear(int day) {
	dayOfYear = day;
	if (dayOfYear <= 31) {
		month = "January";
		dayOfMonth = day;
	}
	else if (dayOfYear > 31 && dayOfYear <= 59) {
		month = "February";
		dayOfMonth = day - 31;
	}
	else if (dayOfYear > 59 && dayOfYear <= 90) {
		month = "March";
		dayOfMonth = day - 59;
	}
	else if (dayOfYear > 90 && dayOfYear <= 120) {
		month = "April";
		dayOfMonth = day - 90;
	}
	else if (dayOfYear > 120 && dayOfYear <= 151) {
		month = "May";
		dayOfMonth = day - 120;
	}
	else if (dayOfYear > 151 && dayOfYear <= 181) {
		month = "June";
		dayOfMonth = day - 151;
	}
	else if (dayOfYear > 181 && dayOfYear <= 212) {
		month = "July";
		dayOfMonth = day - 181;
	}
	else if (dayOfYear > 212 && dayOfYear <= 243) {
		month = "August";
		dayOfMonth = day - 212;
	}
	else if (dayOfYear > 243 && dayOfYear <= 273) {
		month = "September";
		dayOfMonth = day - 243;
	}
	else if (dayOfYear > 273 && dayOfYear <= 304) {
		month = "October";
		dayOfMonth = day - 273;
	}
	else if (dayOfYear > 304 && dayOfYear <= 334) {
		month = "November";
		dayOfMonth = day - 304;
	}
	else if (dayOfYear > 334 && dayOfYear <= 365) {
		month = "December";
		dayOfMonth = day - 31;
	}
}
DayOfYear::DayOfYear(string month, int day) {
	this->month = month;
	dayOfMonth = day;
}

void DayOfYear::print() {
	cout << "Day " << dayOfYear << " would be " << month << " " << dayOfMonth << "." << endl;
}



using namespace std;

int main()
{
	int inputDay;
	cout<<"Using the first constructor that only requires the day of the year (1-365).\n";
	
	cout<<"Enter the a day of the year or a number <=0 to end:";
	cin>>inputDay;
	
	if(inputDay > 365 || inputDay < 0)
	{
		cout<<"Program terminating: The day entered is >365.\n";
	}
	
	else
	{
		DayOfYear(inputDay);
	}
			
	
	return 0;
}