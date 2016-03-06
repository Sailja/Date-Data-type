#include <iostream>
#include "date.h"

using namespace std;

void TestDate()
{  
	// Construct a Date from (d, m, y) 
	Date d1(D03,Mar,2016);		
	cout<<"Constructing a Date from (d, m, y) "<<d1<<endl;
	//construct 'today' 
	Date today;
	cout<<"Today's date is "<<today<<endl;
	//copy constructor is called
	d1=today;
	cout<<"Copying date "<<d1<<endl;
	// Next day
	cout<<"Next date of "<<d1;
	cout<<" is "<<++d1<<endl;
	// Same day next week
	cout<<"Same day next week of "<<d1;
	cout<<" is "<<d1++<<endl;
	//Previous day
	cout<<"Previous day of "<<d1;
	cout<<" is "<<--d1<<endl;
	//Same day previous week
	cout<<"Same day previous week of "<<d1;
	cout<<" is "<<d1--<<endl;
	Date d(D04,Feb,2016);
	int diff= d-d1;
	// Number of days between otherDate and current date
	cout<<"Number of days between "<<d1<<" and "<<d<< " is "<<diff<<endl;
	// Day noOfDays after the current date
	cout<<"15 days after "<<d<<" is "<<d+15<<endl;
	// Day noOfDays before the current date
	cout<<"15 days before "<<d<<" is "<<d+(-15)<<endl;
	// Cast to the week number of the year in which the current date falls
	cout<<"Week number of "<<d<<" is "<<(WeekNumber)d<<endl;
	// Cast to the month of the year in which the current date falls
	cout<<"Month of "<<d<<" is "<<(Month)d<<endl;
	// Cast to the day of the week of the current date
	cout<<"Day of the week of "<<d<<" is "<<(WeekDay)d<<endl;

	Date d3(D01,Mar,2016);
	Date d2(D01,Apr,2015);
	if(d2.leapYear())
	cout<<d2<<" is in leap year"<<endl;
	else
	cout<<d2<<" is not in leap year"<<endl;
	if(d3.leapYear())
	cout<<d3<<" is in leap year"<<endl;
	else
	cout<<d3<<" is not in leap year"<<endl;
	// BINARY RELATIONAL OPERATORS
	Date d4=d2;
	if (d4==d2)
	cout<<d4<<" and "<<d2<<" are same"<<endl;
	else
	cout<<d4<<" and "<<d2<<" are not same"<<endl;
	if (d3==d2)
	cout<<d3<<" and "<<d2<<" are same"<<endl;
	else
	cout<<d3<<" and "<<d2<<" are not same"<<endl;
	if (d3!=d2)
	cout<<d3<<" and "<<d2<<" are not same"<<endl;
	else
	cout<<d3<<" and "<<d2<<" are same"<<endl;
	if (d4!=d2)
	cout<<d4<<" and "<<d2<<" are not same"<<endl;
	else
	cout<<d4<<" and "<<d2<<" are same"<<endl<<endl;
	// "<=" operator
	if (d4<=d2)
	cout<<d4<<" is <= "<<d2<<endl;
	else
	cout<<d4<<" is not <= "<<d2<<endl;	
	if (d3<=d2)
	cout<<d3<<" is <= "<<d2<<endl;
	else
	cout<<d3<<" is not <= "<<d2<<endl;
	if (d4<=d3)
	cout<<d4<<" is <= "<<d3<<endl;
	else
	cout<<d4<<" is not <= "<<d3<<endl<<endl;
	// ">=" operator
	if (d4>=d2)
	cout<<d4<<" is >= "<<d2<<endl;
	else
	cout<<d4<<" is not >= "<<d2<<endl;	
	if (d3>=d2)
	cout<<d3<<" is >= "<<d2<<endl;
	else
	cout<<d3<<" is not >= "<<d2<<endl;
	if (d4>=d3)
	cout<<d4<<" is >= "<<d3<<endl;
	else
	cout<<d4<<" is not >= "<<d3<<endl<<endl;
	// "<" operator
	if (d4<d2)
	cout<<d4<<" is < "<<d2<<endl;
	else
	cout<<d4<<" is not < "<<d2<<endl;	
	if (d3<d2)
	cout<<d3<<" is < "<<d2<<endl;
	else
	cout<<d3<<" is not < "<<d2<<endl;
	if (d4<d3)
	cout<<d4<<" is < "<<d3<<endl;
	else
	cout<<d4<<" is not < "<<d3<<endl<<endl;
	// ">" operator
	if (d4>d2)
	cout<<d4<<" is > "<<d2<<endl;
	else
	cout<<d4<<" is not > "<<d2<<endl;	
	if (d3>d2)
	cout<<d3<<" is > "<<d2<<endl;
	else
	cout<<d3<<" is not > "<<d2<<endl;
	if (d4>d3)
	cout<<d4<<" is > "<<d3<<endl;
	else
	cout<<d4<<" is not > "<<d3<<endl<<endl;
	
	//checking different date formats
	cout<<"dd-mmm-yy format date is "<<d1<<endl;
	DateFormat set("d","m","yy");
	d1.setFormat(set);
	cout<<"d-m-yy format date is "<<d1<<endl;
	DateFormat set2("d-mm-yyyy");
	d1.setFormat(set2);
	cout<<"d-mm-yyyy format date is "<<d1<<endl;
	DateFormat set3("0","m","yy");
	d1.setFormat(set3);
	cout<<d1<<endl;
	DateFormat set4("dd","m","0");
	d1.setFormat(set4);
	cout<<d1<<endl;
	DateFormat set5("dd","0","yyyy");
	d1.setFormat(set5);
	cout<<"dd-0-yyyy format date is "<<d1<<endl;
	DateFormat set6("ddd","sm","sada");
	d1.setFormat(set6);
	cout<<d1<<endl;	
	d1.setFormat(set2);

	//handling exception
	Date ed=Date("1-1-2013");//use of explicit converter from string to date
	ed.setFormat(set2);
	cout<<"Day is 0"<<endl;	
	ed=Date("0-2-13");
	cout<<"Month is 13"<<endl;
	ed=Date("2-13-13");
	cout<<"31st Feb is not valid"<<endl;	
	ed=Date("31-2-23");
	cout<<"30th feb is not valid"<<endl;
	ed=Date("30-2-12");
	cout<<"29th Feb of 2017 which is not leap year"<<endl;
	ed=Date("29-2-17");
	cout<<"Date below 1950"<<endl;
	ed=Date("2-3-1919");
	cout<<"Date above 2050"<<endl;
	ed=Date("2-3-2053");

	//Taking input date from user 
	Date input;
	cin>>input;
	cout<<"You have entered "<<input<<endl;
	input.setFormat(set);
	cin>>input;
	cout<<"You have entered ";
	input.setFormat(set2);
	cout<<input<<endl;
}
int main()
{
    TestDate();
}
