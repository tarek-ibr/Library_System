//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_MEMBER_H
#define PROJECT_MEMBER_H

#include <iostream>
#include "Custom_String_Class.h"
#include <vector>
#include "Book.h"

using namespace std;

class Member {
private:
    Custom_String_Class Name;
    int ID;
    vector<Custom_String_Class> Checked_Books;
    std::vector<Book> checkedOutBooks;
    float Fines;
    Custom_String_Class Type;
public:
    Member();
    Member(Custom_String_Class N,Custom_String_Class T,int I);
    vector<Custom_String_Class> SearchByTitle(Custom_String_Class Title);
    // Add a book to the checkedOutBooks vector
    void addBook(const Book& book);

    // Remove a book from the checkedOutBooks vector
    void removeBook(const Custom_String_Class& ISBN);

    // Display all checked out books
    void displayCheckedOutBooks() const;
    void display() const;
};


#endif //PROJECT_MEMBER_H
