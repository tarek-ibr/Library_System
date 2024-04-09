//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_MEMBER_H
#define PROJECT_MEMBER_H

#include <iostream>
#include "Custom_String_Class.h"
#include <vector>
#include "Book.h"
#include "Loan.h"

using namespace std;

class Member {
private:
    Custom_String_Class Name;
    int ID;
    Custom_String_Class Type;
    int fines;
    vector<Loan> checkedOutBooks;
public:
    Member();
    Member(Custom_String_Class N,int I,Custom_String_Class T);
    int calculateTotalFines ();
    void display();
};


#endif //PROJECT_MEMBER_H
