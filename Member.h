//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_MEMBER_H
#define PROJECT_MEMBER_H

#include <iostream>
#include "Custom_String_Class.h"
#include <vector>
#include "Book.h"
#include "Loan.h"

using namespace std;

class Member {
private:
    Custom_String_Class Name;
    int ID;
    Custom_String_Class Type;
    int fines;
    static vector<Loan> checkedOutBooks;
    static vector<Member> members;
public:
    Member();
    Member(Custom_String_Class N,int I,Custom_String_Class T);
    Custom_String_Class getName();
    int getID();
    Custom_String_Class getType();
    int getFines();
    void setName(Custom_String_Class name);
    void setID(int id);
    void setType(Custom_String_Class type);
    int calculateTotalFines ();
    void display();
    void displayloaned();
    void borrowBook(Book);
    void returnBook(Book);
};


#endif //PROJECT_MEMBER_H
