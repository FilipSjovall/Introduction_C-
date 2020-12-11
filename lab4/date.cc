#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if(month==12 && day==daysPerMonth[12]){
		day   = 1;
		month = 1;
		year += 1; 
	}else if(month!=12 && day==daysPerMonth[month]){
		day   = 1;
		month+= 1; 
	}else{
		day  += 1;
	}

}

std::ostream& operator<<(std::ostream& os, const Date& dt)
{
    os << dt.getYear() << '-' << dt.getMonth() << '-' << dt.getDay();
    return os;
}

std::istream& operator>>(std::istream& is, const Date& dt)
{
	// std::string format;
	// is >> format;
	// läs int sen char sen int 
	// hjälpfunk '-' , ( exceptions * ? )
	if(is){	
		
	}else{
    	is.setstate(ios_base::failbit);
	}
	
	return is;
}


// Template function for toString()
template<typename T>
std::string toString(T &x){
	std::ostringstream oss;
    oss << T;
    return oss.str();
}

template<typename S>
S string_cast(std::istringstream& stream){
	return stream >> S;
}