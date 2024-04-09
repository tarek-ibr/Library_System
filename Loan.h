//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_LOAN_H
#define PROJECT_LOAN_H
#include "Custom_String_Class.h"
#include "Date.h"
#include <iostream>

class Loan  {
    int memberID;
    Custom_String_Class bookID;
    Date dueDate;
    bool returned;
public:
    Loan();
    Loan(int, Custom_String_Class, Date);
    Custom_String_Class getBookID();
    int getMemberID();
    int calculateFines();
    void displayDetails();



};


#endif //PROJECT_LOAN_H
