//
// Created by tarek on 4/5/2024.
//

#include "Loan.h"

Loan::Loan(){}
Loan::Loan(int m, int b, Date d): memberID(m), bookID(b), dueDate(d) {
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
void Loan::displayDetails(){

    std::cout << "memberID " << memberID <<endl;
    std::cout << "bookID " << bookID <<endl;
    std::cout << "due date " <<dueDate.getDate() <<endl;
    if (returned)
        std::cout << "it is already returned" <<endl;
    else
        std::cout << "it is not returned" <<endl;
}
