//
// Created by tarek on 4/5/2024.
//

#include "Loan.h"

// Static list of all loans
std::vector<Loan> Loan::Loans_List={};

// Default constructor
Loan::Loan(): memberID(0),bookID(""), dueDate(0,0,0), borrowDate(0,0,0){}

// Constructor with member ID, book ID, due date, and borrow date
Loan::Loan(int m, const Custom_String_Class& b, Date due, Date borrow): memberID(m), bookID(b), dueDate(due), borrowDate(borrow) {}

// Constructor with member ID, book ID, and due date. Borrow date is set to current date.
Loan::Loan(int m, const Custom_String_Class& b, Date d): memberID(m), bookID(b), dueDate(d) {
    borrowDate=Date::getCrrentDate();
}

// Constructor with member ID and book ID. Due date and borrow date are set to 0.
Loan::Loan(int m, const Custom_String_Class& b): memberID(m), bookID(b), dueDate(0,0,0), borrowDate(0,0,0) {}

// Getter for book ID
Custom_String_Class Loan::getBookID() const{
    return bookID;
}

// Getter for member ID
int Loan::getMemberID() const{
    return memberID;
}

// Getter for due date
Date Loan::getDueDate() const{
    return dueDate;
}

// Getter for borrow date
Date Loan::getBorrowDate() const{
    return borrowDate;
}

// Getter for list of loans
vector<Loan>& Loan::getLoans_List(){
    return Loans_List;
}

// Setter for member ID
void Loan::setMemberID(int m) {
    memberID = m;
}

// Setter for book ID
void Loan::setBookID(const Custom_String_Class& b) {
    bookID = b;
}

// Setter for due date
void Loan::setDueDate(Date d) {
    dueDate = d;
}

// Setter for borrow date
void Loan::setBorrowDate(Date r) {
    borrowDate = r;
}

// Function to calculate fines
int Loan::calculateFines(){
    if(dueDate<Date::getCrrentDate()){
        int days=Date::getCrrentDate()-dueDate;
        return days*2;
    }
    else {
        return 0;
    }
}

// Function to display details of the loan
void Loan::displayDetails(){

    std::cout << "memberID " << memberID <<endl;
    std::cout << "bookID " << bookID <<endl;
    std::cout << "due date " <<dueDate.getDate() <<endl;
    std::cout << "borrow date " <<borrowDate.getDate() <<endl;
}

// Function to load loans from a file
void Loan::loadLoans() {
    Loans_List.clear();
    std::ifstream file("loaned.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    json j;
    file >> j;

    for (const auto& loan_json : j) {
        Loan ln(loan_json["memberID"], loan_json["bookID"].get<string>(), Custom_String_Class(loan_json["dueDate"].get<string>()));
        ln.setBorrowDate(Custom_String_Class(loan_json["borrowDate"].get<string>()));
        Loan::Loans_List.push_back(ln);
    }
    file.close();
}

// Function to save loans to a file
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
        loanJSON["bookID"] =loan.bookID.getSTR();
        loanJSON["dueDate"] =loan.dueDate.getDate().getSTR();
        loanJSON["borrowDate"] =loan.borrowDate.getDate().getSTR();
        OUTPUT.push_back(loanJSON);
    }
    file<<std::setw(4)<<OUTPUT<<std::endl; // setw(4) sets the width of the output field to 4
    file.close();
}

// Function to display the list of loans
void Loan::displaylist() {
    for (const auto &it: (Loan::Loans_List)) {
        cout<<it.bookID<<endl;
    }
}
