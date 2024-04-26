//
// Created by tarek on 4/5/2024.
//

#include "User.h"
using namespace std;

// Use nlohmann's json library
using json = nlohmann::json;

// Static list of all members
vector<Member> Member::members={};

// Default constructor
Member::Member():Name(""),Type(""),ID(0),Fines(0) {}

// Constructor with name, ID, and type. Fines are set to 0.
Member::Member(const Custom_String_Class& N,int I,const Custom_String_Class& T): Name(N),ID(I),Type(T){
    Fines=0;
}

// Getter for name
Custom_String_Class Member::getName() const{
    return Name;
}

// Getter for list of members
vector<Member>& Member::getMembers(){
    return members;
}

// Getter for ID
int Member::getID() const {
    return ID;
}

// Getter for type
Custom_String_Class Member::getType() const{
    return Type;
}

// Getter for fines
int Member::getFines() const{
    return Fines;
}

// Getter for checked out books
vector<Loan>& Member::getCheckedOutBooks(){
    return checkedOutBooks;
}

// Setter for name
void Member::setName(const Custom_String_Class& name) {
    Name = name;
}

// Setter for ID
void Member::setID(int id) {
    ID = id;
}

// Setter for type
void Member::setType(const Custom_String_Class& type) {
    Type = type;
}

// Setter for fines
void Member::setFines(int f){
    Fines=f;
}

// Function to calculate total fines
int Member::calculateTotalFines (){
    Fines=0;
    for(auto it: checkedOutBooks){
        Fines+=it.calculateFines();
    }
    return Fines;
}

// Function to update total fines
void Member::updateTotalFines (){
    Fines=calculateTotalFines();
}

// Function to display member details
void Member::display(){

    std::cout << "Name: " << Name << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "Number of Checked Out Books: " << checkedOutBooks.size() << std::endl;
    std::cout << "Overdue Fines: " << calculateTotalFines() << std::endl;
    cout<< "--------------------\n";
}

// Function to display loaned books
void Member::displayloaned() const{

    int j=1;
    cout<< "--------------------\n";
    for (int i = 0; i < this->checkedOutBooks.size(); ++i) {
        cout<<j++<<" ";
        std::cout << "you have borrowed a book with ID " << this->checkedOutBooks[i].getBookID() << " \n";
    }
    cout<< "--------------------\n";
}

// Function to request to borrow a book
void Member::requestBorrow(Book& book) {
    Loan ln(ID, book.getISBN());
    Librarian::addBorrowRequest(ln);
}

// Function to return a book
void Member::returnBook(Book book) {
    Librarian::returnBook(*this, book);
}
