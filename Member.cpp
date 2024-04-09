//
// Created by tarek on 4/5/2024.
//

#include "Member.h"
using namespace std;

vector<Loan> Member::checkedOutBooks={};
vector<Member> Member::members={};
Member::Member():Name(""),Type(""),ID(0),fines(0) {}
Member::Member(Custom_String_Class N,int I,Custom_String_Class T): Name(N),ID(I),Type(T){
    fines=0;
}
Custom_String_Class Member::getName() {
    return Name;
}

int Member::getID() {
    return ID;
}

Custom_String_Class Member::getType() {
    return Type;
}

int Member::getFines() {
    fines=calculateTotalFines();
    return fines;
}

void Member::setName(Custom_String_Class name) {
    Name = name;
}

void Member::setID(int id) {
    ID = id;
}

void Member::setType(Custom_String_Class type) {
    Type = type;
}
int Member::calculateTotalFines (){
    fines=0;
    for(auto it: checkedOutBooks){
        fines+=it.calculateFines();
    }
}
void Member::display(){
    std::cout << "Name: " << Name << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "Number of Checked Out Books: " << checkedOutBooks.size() << std::endl;
    std::cout << "Overdue Fines: " << calculateTotalFines() << std::endl;
}
void Member::displayloaned(){
    for(auto it =checkedOutBooks.begin(); it != checkedOutBooks.end() + 1; ++it) {
        if (it->getMemberID() == ID) {
            cout << "you have borrowed a book with ID " <<it->getBookID();
        }
    }
}
void Member::borrowBook(Book b){
    if(b.Quantity>0) {
        if (b.Quantity=1){
            b.Available= false;
        }
        b.Quantity--;
        Date dueDate = Date::getCrrentDate() + 7;
        Loan newloan(ID, b.ISBN, dueDate);
        checkedOutBooks.push_back(newloan);
    }
    else{
        cout << "there is no copies of the book available"<<endl;
    }
}
void Member::returnBook(Book b){
    if(b.Quantity==0)
        b.Available=true;
    b.Quantity++;
    for(auto it =checkedOutBooks.begin(); it != checkedOutBooks.end() + 1; ) {
        if(it->getBookID() == b.ISBN && it->getMemberID()==ID) {
            cout << "Now Iam removing \n";
            checkedOutBooks.erase(it);
            return;
        } else {
            ++it;
        }
    }
}