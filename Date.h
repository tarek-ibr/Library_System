//
// Created by tarek on 4/8/2024.
//

#ifndef PROJECT_DATE_H
#define PROJECT_DATE_H
#include "Custom_String_Class.h"
#include <iostream>
#include <chrono>
#include <ctime>

#define REFERENCE_YEAR 1970


class Date {
    int day;
    int month;
    int year;
public:
    Date();
    Date(int, int, int);
    Date(Custom_String_Class);
    void setDate (Custom_String_Class);
    Custom_String_Class getDate() const;
    static Date getCrrentDate();
    bool operator > (Date);
    bool operator < (Date);
    bool operator == (Date d) const;
    Date operator = (Date);
    Date operator = (Custom_String_Class);
    Date operator + (int);
    int operator - (Date d);
    int daysSinceReferenceDate();
    static int daysInMonth(int, int);

};


#endif //PROJECT_DATE_H
