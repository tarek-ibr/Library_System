// Created by tarek on 4/8/2024.

#include "Date.h"

// Default constructor initializing date to 0/0/0
Date::Date():day(0), month(0), year(0){}

// Parameterized constructor to create a date with given day, month, and year
Date::Date(int d, int m, int y): day(d), month(m), year(y){}

// Constructor that takes a string in the format "dd/mm/yyyy"
Date::Date(Custom_String_Class d) {
    // Extract day, month, and year from the string
    day=int(d[0])-48;
    day=day*10+int(d[1])-48;

    month=int(d[3])-48;
    month=month*10+int(d[4])-48;

    year=int(d[6])-48;
    year=year*10+int(d[7])-48;
    year=year*10+int(d[8])-48;
    year=year*10+int(d[9])-48;
}

// Function to set the date from a string in the format "dd/mm/yyyy"
void Date::setDate (Custom_String_Class d){
    // Extract day, month, and year from the string
    day=int(d[0])-48;
    day=day*10+int(d[1])-48;

    month=int(d[3])-48;
    month=month*10+int(d[4])-48;

    year=int(d[6])-48;
    year=year*10+int(d[7])-48;
    year=year*10+int(d[8])-48;
    year=year*10+int(d[9])-48;
}

// Function to get the date as a string in the format "dd/mm/yyyy"
Custom_String_Class Date::getDate() const{
    Custom_String_Class d;
    if (day<10)
        d='0' + to_string(day) + '/'+ to_string(month) + '/' +to_string(year);
    if(month<10)
        d= to_string(day) + '/'+ '0' + to_string(month) + '/' +to_string(year);
    if(day<10 && month<10)
        d= '0' + to_string(day) + '/'+ '0' + to_string(month) + '/' +to_string(year);
    if(day>=10 && month>=10)
        d= to_string(day) + '/'+ to_string(month) + '/' +to_string(year);

    return d;
}

// Function to get the current date
Date Date::getCrrentDate(){
    // Get the current system time point
    auto now = std::chrono::system_clock::now();

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm* localTime = std::localtime(&currentTime);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    return {day,month,year};
}

// Overloaded greater than operator to compare two dates
bool Date::operator>( Date d)  {
    int days =*this-d;
    return days>0;  // Return true if day is greater, false otherwise
}

// Overloaded less than operator to compare two dates
bool Date::operator<( Date d) {
    int days =*this-d;
    return days<0; // Return true if day is less, false otherwise
}

// Overloaded equality operator to compare two dates
bool Date::operator == (Date d) const{
    if (year==d.year && month==d.month && day==d.day)
        return true;
    else
        return false;
}

// Overloaded assignment operator to assign one date to another
Date Date::operator = (Date d){
    day=d.day;
    month=d.month;
    year=d.year;
    return *this;
}

// Overloaded assignment operator to assign a string to a date
Date Date::operator = (Custom_String_Class d){
    // Extract day, month, and year from the string
    day=int(d[0])-48;
    day=day*10+int(d[1])-48;

    month=int(d[3])-48;
    month=month*10+int(d[4])-48;

    year=int(d[6])-48;
    year=year*10+int(d[7])-48;
    year=year*10+int(d[8])-48;
    year=year*10+int(d[9])-48;

    return *this;
}

// Overloaded addition operator to add days to a date
Date Date::operator + (int days){
    day+=days;
    int daysinmonth= daysInMonth(month, year);
    while (day> daysinmonth) {
        day -= daysinmonth;
        if(month==12) {
            month = 1;
            year++;
        }
        else
            month++;
    }
    return *this;
}

// Overloaded subtraction operator to find the difference between two dates
int Date::operator - (Date d){
    int thisDays = daysSinceReferenceDate();
    int dDays = d.daysSinceReferenceDate();

    return thisDays - dDays;
}

// Function to calculate the number of days since a reference date
int Date::daysSinceReferenceDate() {
    int days = 0;
    for (int yr = REFERENCE_YEAR; yr < year; ++yr) {
        days += ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))? 366: 365;
    }
    for (int mon = 1; mon < month; ++mon) {
        days += daysInMonth(mon, year);
    }
    days += day;
    return days;
}

// Function to calculate the number of days in a month
int Date::daysInMonth(int m, int y) {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (y%4==0)
                return 29;
            else
                return 28;
        default:
            return -1; // Invalid month
    }
}
