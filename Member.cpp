//
// Created by tarek on 4/5/2024.
//

#include "User.h"
using namespace std;

using json = nlohmann::json;


vector<Member> Member::members={};
Member::Member():Name(""),Type(""),ID(0),Fines(0) {}
Member::Member(const Custom_String_Class& N,int I,const Custom_String_Class& T): Name(N),ID(I),Type(T){
    Fines=0;
}
Custom_String_Class Member::getName() const{
    return Name;
}

int Member::getID() const {
    return ID;
}

Custom_String_Class Member::getType() const{
    return Type;
}

int Member::getFines() const{
    return Fines;
}

vector<Loan>& Member::getCheckedOutBooks(){
    return checkedOutBooks;
}

void Member::setName(const Custom_String_Class& name) {
    Name = name;
}

void Member::setID(int id) {
    ID = id;
}

void Member::setType(const Custom_String_Class& type) {
    Type = type;
}
void Member::setFines(int f){
    Fines=f;
}
int Member::calculateTotalFines (){
    Fines=0;
    for(auto it: checkedOutBooks){
        Fines+=it.calculateFines();
    }
    return Fines;
}
void Member::updateTotalFines (){
    Fines=calculateTotalFines();
}
void Member::display(){
    std::cout << "Name: " << Name << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "Number of Checked Out Books: " << checkedOutBooks.size() << std::endl;
    std::cout << "Overdue Fines: " << calculateTotalFines() << std::endl;
}
void Member::displayloaned() const{

    /*for(auto it =this->checkedOutBooks.begin(); it != this->checkedOutBooks.end() ; ++it) {
        if (it->getMemberID() == ID) {
            cout << "you have borrowed a book with ID " <<it->getBookID()<< endl;
        }
    }*/
    for (int i = 0; i < this->checkedOutBooks.size(); ++i) {
        std::cout << "you have borrowed a book with ID " << this->checkedOutBooks[i].getBookID() << " ";
    }
}
void Member::requestBorrow(Book& book) {
    Loan ln(ID, book.getISBN());
    Librarian::addBorrowRequest(ln);
}
void Member::returnBook(Book book) {
    Librarian::returnBook(*this, book);
}

Member Member::findByID(int id){
    for(auto it:members)
    {
        if(it.getID()==id)
        {
            return it;
        }
    }
    cout<<"Couldn't Find member"<<endl;
}

void Member::displayAllMembers() {
    std::cout << "List of Members:\n";
    for (auto &member: members) {
        member.display();
        std::cout << "-------------------------\n";
    }
}