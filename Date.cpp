//
// Created by tarek on 4/8/2024.
//

#include "Date.h"

Date::Date(){}
Date::Date(int d, int m, int y): day(d), month(m), year(y){}
Date::Date(Custom_String_Class d) {
    day=int(d[0])-48;
    day=day*10+int(d[1])-48;

    month=int(d[3])-48;
    month=month*10+int(d[4])-48;

    year=int(d[6])-48;
    year=year*10+int(d[7])-48;
    year=year*10+int(d[8])-48;
    year=year*10+int(d[9])-48;
}
void Date::setDate (Custom_String_Class d){
    day=int(d[0])-48;
    day=day*10+int(d[1])-48;

    month=int(d[3])-48;
    month=month*10+int(d[4])-48;

    year=int(d[6])-48;
    year=year*10+int(d[7])-48;
    year=year*10+int(d[8])-48;
    year=year*10+int(d[9])-48;
}
Custom_String_Class Date::getDate(){
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
Date Date::getCrrentDate(){
    // Get the current system time point
    auto now = std::chrono::system_clock::now();

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm* localTime = std::localtime(&currentTime);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    return Date(day,month,year);
}
bool Date::operator>( Date d)  {
    int days =*this-d;
    return days>0;  // Return true if day is greater, false otherwise
}

bool Date::operator<( Date d) {
    int days =*this-d;
    return days<0; // Return true if day is less, false otherwise
}

bool Date::operator == (Date d){
    if (year==d.year && month==d.month && day==d.day)
        return true;
    else
        return false;
}
Date Date::operator = (Date d){
    day=d.day;
    month=d.month;
    year=d.year;
    return *this;
}
Date Date::operator = (Custom_String_Class d){
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
int Date::operator - (Date d){
    int thisDays = daysSinceReferenceDate();
    int dDays = d.daysSinceReferenceDate();


    return thisDays - dDays;
}

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