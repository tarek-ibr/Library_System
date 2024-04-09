//
// Created by tarek on 4/5/2024.
//

#include "Loan.h"

Loan::Loan(): memberID(0),bookID(""), returned(false){}
Loan::Loan(int m, const Custom_String_Class& b, Date d): memberID(m), bookID(b), dueDate(d) {
    returned=false;
}
Custom_String_Class Loan::getBookID() const{
    return bookID;
}
int Loan::getMemberID() const{
    return memberID;
}
Date Loan::getDueDate(){
    return dueDate;
}
bool Loan::getReturned() const{
    return returned;
}
void Loan::setMemberID(int m) {
    memberID = m;
}

void Loan::setBookID(const Custom_String_Class& b) {
    bookID = b;
}

void Loan::setDueDate(Date d) {
    dueDate = d;
}

void Loan::setReturned(bool r) {
    returned = r;
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
void Loan::displayDetails(){

    std::cout << "memberID " << memberID <<endl;
    std::cout << "bookID " << bookID <<endl;
    std::cout << "due date " <<dueDate.getDate() <<endl;
    if (returned)
        std::cout << "it is already returned" <<endl;
    else
        std::cout << "it is not returned" <<endl;
}
