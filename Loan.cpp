//
// Created by tarek on 4/5/2024.
//

#include "Loan.h"


std::vector<Loan> Loan::Loans_List={};

Loan::Loan(): memberID(0),bookID(""), dueDate(0,0,0), borrowDate(0,0,0){}

Loan::Loan(int m, const Custom_String_Class& b, Date due, Date borrow): memberID(m), bookID(b), dueDate(due), borrowDate(borrow) {}

Loan::Loan(int m, const Custom_String_Class& b, Date d): memberID(m), bookID(b), dueDate(d) {
    borrowDate=Date::getCrrentDate();
}
Loan::Loan(int m, const Custom_String_Class& b): memberID(m), bookID(b), dueDate(0,0,0), borrowDate(0,0,0) {}

Custom_String_Class Loan::getBookID() const{
    return bookID;
}
int Loan::getMemberID() const{
    return memberID;
}
Date Loan::getDueDate() const{
    return dueDate;
}
Date Loan::getBorrowDate() const{
    return borrowDate;
}
vector<Loan>& Loan::getLoans_List(){
    return Loans_List;
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

void Loan::setBorrowDate(Date r) {
    borrowDate = r;
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
    std::cout << "borrow date " <<borrowDate.getDate() <<endl;
}
void Loan::loadLoans() {
    std::ifstream file("loaned.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    json j;
    file >> j;
//hhhh
    for (const auto& loan_json : j) {
        Loan ln(loan_json["memberID"], loan_json["bookID"].get<string>(), Custom_String_Class(loan_json["dueDate"].get<string>()));
        ln.setBorrowDate(Custom_String_Class(loan_json["borrowDate"].get<string>()));
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
        loanJSON["bookID"] =loan.bookID.str;
        loanJSON["dueDate"] =loan.dueDate.getDate().str;
        loanJSON["borrowDate"] =loan.borrowDate.getDate().str;
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