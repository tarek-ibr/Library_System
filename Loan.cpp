//
// Created by tarek on 4/5/2024.
//

#include "Loan.h"

Loan::Loan(){}
Loan::Loan(int m, Custom_String_Class b, Date d): memberID(m), bookID(b), dueDate(d) {
    returned=false;
}
int Loan::calculateFines(){
    if(dueDate<Date::getCrrentDate()){
        int days=Date::getCrrentDate()-dueDate;
        return days*2;
    }
    else {
        return 0;
    }
}
Custom_String_Class Loan::getBookID(){
    return bookID;
}
int Loan::getMemberID(){
    return memberID;
}
Date Loan::getDueDate(){
    return dueDate;
}
bool Loan::getReturned(){
    return returned;
}
void Loan::setMemberID(int m) {
    memberID = m;
}

void Loan::setBookID(Custom_String_Class b) {
    bookID = b;
}

void Loan::setDueDate(Date d) {
    dueDate = d;
}

void Loan::setReturned(bool r) {
    returned = r;
}
void Loan::displayDetails(){

    std::cout << "memberID " << memberID <<endl;
    std::cout << "bookID " << bookID <<endl;
    std::cout << "due date " <<dueDate.getDate() <<endl;
    if (returned)
        std::cout << "it is already returned" <<endl;
    else
        std::cout << "it is not returned" <<endl;
}
