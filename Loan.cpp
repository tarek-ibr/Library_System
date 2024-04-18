//
// Created by tarek on 4/5/2024.
//

#include "Loan.h"
std::vector<Loan> Loan::Loans_List;
Loan::Loan(): memberID(0),bookID(""){}
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
void Loan::loadLoans() {
    std::ifstream file("loaned.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
             return;
    }

    json j;
    file >> j;

    for (const auto& loan_json : j) {
        Loan ln(loan_json["memberID"], loan_json["bookID"].get<string>(),
                Custom_String_Class(loan_json["dueDate"].get<string>()));
        Loan::Loans_List.push_back(ln);
    }
    file.close();
}
void Loan::saveLoans() {
    std::ofstream file("loaned.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << endl;
        return;
    }
    json OUTPUT;
    for(const auto& loan : Loan::Loans_List)
    {
        json loanJSON;
        loanJSON["memberID"]=loan.memberID;
        loanJSON["dueDate"] =loan.dueDate.getDate().str;
        loanJSON["bookID"] =loan.bookID.str;
        OUTPUT.push_back(loanJSON);
    }
    file<<std::setw(4)<<OUTPUT<<std::endl;
    file.close();
}
void Loan::displaylist() {
    for (const auto &it: (Loan::Loans_List)) {
     cout<<it.bookID<<endl;
    }
}