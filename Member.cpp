//
// Created by tarek on 4/5/2024.
//

#include "Member.h"
using namespace std;

Member::Member():Name(""),Type(""),ID(0),Fines(0) {}
Member::Member(Custom_String_Class N,Custom_String_Class T,int I): Name(N),Type(T),ID(I),Fines(0) {}
vector<Custom_String_Class> Member::SearchByTitle(Custom_String_Class Title) {
    vector<Custom_String_Class> result;
}

void Member::addBook(const Book& book) {
    checkedOutBooks.push_back(book);
}

void Member::removeBook(const Custom_String_Class& ISBN) {
    for (auto it = checkedOutBooks.begin(); it != checkedOutBooks.end(); ++it) {
        if (it->getISBN() == ISBN) {
            checkedOutBooks.erase(it);
            break;
        }
    }
}

void Member::displayCheckedOutBooks() const {
    std::cout << "Checked Out Books:" << std::endl;
    for (const auto& book : checkedOutBooks) {
        book.display();
        std::cout << std::endl;
    }
}



void Member::display() const {
    std::cout << "Name: " << Name << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "Number of Checked Out Books: " << checkedOutBooks.size() << std::endl;
    std::cout << "Overdue Fines: " << Fines << std::endl;
}