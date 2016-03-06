#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctime>
#include <iomanip>  
#include "date.h"
using namespace std;

DateFormat Date::format("dd-mmm-yy");
DateFormat::DateFormat(const char* p, const char* q, const char* r){
	dateFormat=const_cast<char *>(p);
	monthFormat=const_cast<char *>(q);
	yearFormat=const_cast<char *>(r);
}

DateFormat::DateFormat(const char* format){		
	char *string = new char[strlen(format) + 1];
	strcpy(string, format);
	char* chars_array = strtok(string, "-");
	dateFormat=chars_array;	
	chars_array = strtok(NULL, "-");
	monthFormat=chars_array;	
	chars_array = strtok(NULL, "-");
	yearFormat=chars_array;	
	
}

DateFormat::DateFormat(){	
	char string[] = "dd";
	dateFormat=string;	
	char string1[] = "mmm";
	monthFormat=string1;
	char string2[]= "yy";
	yearFormat=string2;	
}	

void Date:: setFormat(DateFormat& d){
	format.dateFormat=d.dateFormat;
	format.monthFormat=d.monthFormat;
	format.yearFormat=d.yearFormat;	
}
DateFormat& Date:: getFormat(){
	return format;
}
DateFormat::~DateFormat(){

}

Date::Date(const Date& d):day(d.day),month(d.month),year(d.year){}
//this method is used to return date n days from given date
Date Date::Ndays(int n,  const Date& dt){
    // initialize
    Year y=dt.year;
    Month  m=dt.month;
    Day d =dt.day;
    std::tm t = {};
    t.tm_year = y-1900;
    t.tm_mon  = m-1;
    t.tm_mday = d;
    // modify
    t.tm_mday += n;
    std::mktime(&t);
    //cout<<static_cast<Day>(t.tm_mday)<<" "<<static_cast<Month>(t.tm_mon+1)<<" "<<static_cast<Year>(t.tm_year+1900)<<endl;
    Date newd(static_cast<Day>(t.tm_mday), static_cast<Month>(t.tm_mon+1), static_cast<Year>(t.tm_year+1900));
    return newd;    
}


Date::Date(Day d, Month m, Year y)
{
	//exception handling
	try{
		if(m<=0||m>12||d<=0||d>31||y<0)
		  throw "invalid_argument";
		
		if(d==31 && (m==2 || m==4 ||m==6 ||m==9||m==11))
		  throw "domain_error";
		if(d==30 && m==2)
		  throw "domain_error";
		if ((d==29 && m==2))
		  throw "domain error";
		if(y<1950 || y>=2050)
		  throw "out_of_range";	
		day=d;
		month=m;
   		year=y;
    }
    catch (const char* strException) // catch exceptions of type const char*
    {
        cout << "Error: " << strException << endl;
		
    }
	
		
}
Date::Date(const char* date)
{
	char *string = new char[strlen(date) + 1];
	strcpy(string, date);
	char* chars_array = strtok(string, "-");
	char *dateFormat=chars_array;	
	chars_array = strtok(NULL, "-");
	char* monthFormat=chars_array;	
	chars_array = strtok(NULL, "-");
	char* yearFormat=chars_array;	
	tm tm1;
	sscanf(dateFormat,"%d", &tm1.tm_mday);
	sscanf(monthFormat,"%d", &tm1.tm_mon);
	sscanf(yearFormat,"%d", &tm1.tm_year);
	int y=tm1.tm_year;
	int d=tm1.tm_mday;
	int m=tm1.tm_mon;
	if (y<100)
	{
	 if(y>=50)
	    y=(1900+y);
	   else
	    y=(2000+y);	
	}
	//Exception handling
	try{
		if(m<=0||m>12||d<=0||d>31||y<0)
		  throw "invalid_argument";
		
		if(d==31 && (m==2 || m==4 ||m==6 ||m==9||m==11))
		  throw "domain_error";
		if(d==30 && m==2)
		  throw "domain_error";
		if ((d==29 && m==2))
		  throw "domain error";
		if(y<1950 || y>=2050)
		  throw "out_of_range";	
		day=static_cast<Day>(tm1.tm_mday);
		month=static_cast<Month>(tm1.tm_mon);	
		year=static_cast<Year>(y);
    }
    catch (const char* strException) // catch exceptions of type const char*
    {
        cout << "Error: " << strException << endl;
		
    }
	
}
Date::Date(){
	time_t t1 = time(0);   // get time now
    	struct tm * now = localtime( & t1 );
	Year y=now->tm_year + 1900;
	Day d=static_cast<Day>(now->tm_mday);
	Month m=static_cast<Month>(now->tm_mon + 1);
	try{
		if(m<=0||m>12||d<=0||d>31||y<0)
		  throw "invalid_argument";
		
		if(d==31 && (m==2 || m==4 ||m==6 ||m==9||m==11))
		  throw "domain_error";
		if(d==30 && m==2)
		  throw "domain_error";
		if ((d==29 && m==2))
		  throw "domain error";
		if(y<1950 || y>=2050)
		  throw "out_of_range";	
		
		year=now->tm_year + 1900;
		month=static_cast<Month>(now->tm_mon + 1);
		day=static_cast<Day>(now->tm_mday);    
    }
    catch (const char* strException) // catch exceptions of type const char*
    {
        cout << "Error: " << strException << endl;
		
    }
	
		
}

Date::~Date(){
	//cout<<"Destructor is called"<<endl;
}

Date& Date::operator=(const Date& d){
    if(this!=(&d)){
       	this->day=d.day;
       	this->month=d.month;
	this->year=d.year;
    }
    return *this;
}

Date& Date::operator++(){	
	Date x=Ndays(1, *this);
	*this=x;
	return *this;
}

Date& Date::operator++(int){
	Date x=Ndays(7,*this);
	*this=x;
	return *this;
}

Date& Date::operator--(){
	Date x=Ndays(-1,*this);
	*this=x;
	return *this;
}

Date& Date::operator--(int){
	Date x=Ndays(-7,*this);
	*this=x;
	return *this;
}

unsigned int Date::operator-(const Date& otherDate){
    struct std::tm a = {0,0,0,this->day,this->month-1,this->year-1900}; 
    //cout<<otherDate.day<<" "<<otherDate.month<<"  "<<otherDate.year<<endl;
    struct std::tm b = {0,0,0,otherDate.day,otherDate.month-1,otherDate.year-1900}; 
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) )
    {
        double difference = difftime(y, x) / (60 * 60 * 24);        
	return difference;
    }
}

Date Date::operator+(int noOfDays){
	Date x=Ndays(noOfDays,  *this);
	return x;
}

Date::operator WeekNumber() const{
	tm t={};
	t.tm_year=this->year-1900;
	t.tm_mon=0;
	t.tm_mday=1;	
	time_t x1=mktime(&t);
	int x=0;
	if (t.tm_wday>4)
	 x=4-t.tm_wday;
	else
	 x=t.tm_wday-4;
	if (t.tm_wday==0)
	 x=3;
	tm ti={};
	ti.tm_year=this->year-1900;
	ti.tm_mon=this->month-1;
    	ti.tm_mday = this->day;
    	time_t y1 =mktime(&ti);
	double diff=difftime(y1,x1) / (60 * 60 * 24);	
	return static_cast<WeekNumber>((diff-x+1)/7+1);
}

Date::operator Month() const{
	return this->month;
}

Date::operator WeekDay() const{
	tm t = {};
    	t.tm_year = this->year-1900;
    	t.tm_mon  = this->month-1;
    	t.tm_mday = this->day;
    	mktime(&t);
	if (t.tm_wday !=0){
	 return static_cast<WeekDay>(t.tm_wday);
	}
	else 
	return static_cast<WeekDay>(7);
}
//this function checks leap year
bool Date::leapYear() const{
  if ( year%400 == 0)
    return true;
  else if ( year%100 == 0)
    return false;
  else if ( year%4 == 0 )
    return true;
  else
    return false;  
 
} 
bool Date:: operator==(const Date& otherDate){
	return(*this - otherDate==0);

}
bool Date:: operator!=(const Date& otherDate){
	return(*this - otherDate!=0);
}

bool Date:: operator<(const Date& otherDate){
	int dif=*this - otherDate;
	return(dif>0);
}
bool Date:: operator<=(const Date& otherDate){
	int dif=*this - otherDate;
	return(dif>=0);
}
bool Date:: operator>(const Date& otherDate){
	int dif=*this - otherDate;
	return(dif<0);
}
bool Date:: operator>=(const Date& otherDate){
	int dif=*this - otherDate;
	return(dif<=0);
}
istream& operator>>(istream& is, Date& d){
	cout<<"Enter the date"<<endl;
	char ch1, ch2;
	int di,mi;
	Year y;
	if(strcmp(d.format.dateFormat, "d") == 0)
	is>>di;
	if(strcmp(d.format.dateFormat, "dd") == 0)
	is>>di;
	is>>ch1;
	if(strcmp(d.format.monthFormat, "m") == 0)
	is>>mi;
	if(strcmp(d.format.monthFormat, "mm") == 0)
	is>>mi;		
	if(strcmp(d.format.monthFormat, "mmm") == 0)
	{
	  char s[]="";
	  is>>s;
	  if(strcmp(s, "Jan") == 0)
	  mi=1;
 	  if(strcmp(s, "Feb") == 0)
	  mi=2;
 	  if(strcmp(s, "Mar") == 0)
	  mi=3;
 	  if(strcmp(s, "Apr") == 0)
	  mi=4;
 	  if(strcmp(s, "May") == 0)
	  mi=5;
 	  if(strcmp(s, "Jun") == 0)
	  mi=6;
 	  if(strcmp(s, "Jul") == 0)
	  mi=7;
 	  if(strcmp(s, "Aug") == 0)
	  mi=8;
 	  if(strcmp(s, "Sep") == 0)
	  mi=9;
 	  if(strcmp(s, "Oct") == 0)
	  mi=10;
 	  if(strcmp(s, "Nov") == 0)
	  mi=11;
 	  if(strcmp(s, "Dec") == 0)
	  mi=12; 		
		
	}
	is>>ch2;
	if(strcmp(d.format.yearFormat, "yy") == 0)
	{
	   is>>y;
	   if(y>=50)
	    y=(1900+y);
	   else
	    y=(2000+y);
	}
	if(strcmp(d.format.yearFormat, "yyyy") == 0)
	is>>y;
	
    	if(ch1 == '-' && ch2 == '-')
        {
	    Date f(static_cast<Day>(di),static_cast<Month>(mi),y);
	    d=f;
	 }
	else
	cout<<"Invalid Input Date format "<<endl; 

	return is; 
	 
  }
ostream& operator<<(ostream& os, const Date&d){
	int count=0;
	if(strcmp(d.format.dateFormat, "0") == 0 || strcmp(d.format.yearFormat, "0") == 0)
	{
	   os<<"No Date";
	   return os;
	}
	if(strcmp(d.format.dateFormat, "d") == 0)
	{os<<d.day;count++;}	
	if(strcmp(d.format.dateFormat, "dd") == 0)	
	{os<<setfill('0')<<setw(2)<<d.day;count++;}
	os<<"-";
	
	if(strcmp(d.format.monthFormat, "0") == 0)
	{
	  if(d.month==1)
	  os<<"January";
 	  if(d.month==2)
	  os<<"February";
 	  if(d.month==3)
	  os<<"March";
 	  if(d.month==4)
	  os<<"April";
 	  if(d.month==5)
	  os<<"May";
 	  if(d.month==6)
	  os<<"June";
 	  if(d.month==7)
	  os<<"July";
 	  if(d.month==8)
	  os<<"August";
 	  if(d.month==9)
	  os<<"September";
 	  if(d.month==10)
	  os<<"October";
 	  if(d.month==11)
	  os<<"November";
 	  if(d.month==12)
	  os<<"December";
	  count++; 	  
	}
	if(strcmp(d.format.monthFormat, "m") == 0)
	{os<<d.month;count++;}
	if(strcmp(d.format.monthFormat, "mm") == 0)
	{os<<setfill('0')<<setw(2)<<d.month;count++;}
	if(strcmp(d.format.monthFormat, "mmm") == 0)
	{
	  if(d.month==1)
	  os<<"Jan";
 	  if(d.month==2)
	  os<<"Feb";
 	  if(d.month==3)
	  os<<"Mar";
 	  if(d.month==4)
	  os<<"Apr";
 	  if(d.month==5)
	  os<<"May";
 	  if(d.month==6)
	  os<<"Jun";
 	  if(d.month==7)
	  os<<"Jul";
 	  if(d.month==8)
	  os<<"Aug";
 	  if(d.month==9)
	  os<<"Sep";
 	  if(d.month==10)
	  os<<"Oct";
 	  if(d.month==11)
	  os<<"Nov";
 	  if(d.month==12)
	  os<<"Dec";
	  count++;
	}
	
	os<<"-";
	
	if(strcmp(d.format.yearFormat, "yy") == 0)	
	{os<<d.year%100;count++;}
	if(strcmp(d.format.yearFormat, "yyyy") == 0)
	{os<<d.year;count++;}	
	if(count==3)
     	return os;
	else
	cout<<"Invalid Date Format"<<endl;
}

