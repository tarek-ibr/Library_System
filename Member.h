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
#include <fstream>
#include "json.h"
#include "Request.h"
#include "Librarian.h"
using namespace std;

class Member {
protected:
    Custom_String_Class Name;
    int ID;
    Custom_String_Class Type;
    int Fines;
    static vector<Member> members;
public:
    vector<Loan> checkedOutBooks;
    Member();
    Member(const Custom_String_Class& ,int ,const Custom_String_Class& );
    Custom_String_Class getName();
    int getID() const;
    Custom_String_Class getType();
    int getFines();
    void setName(const Custom_String_Class&);
    void setID(int);
    void setType(const Custom_String_Class&);
    int calculateTotalFines ();
    void display();
    void displayloaned() const;
    void requestBorrow(Book& book);
    void returnBook(Book) ;
    static bool loadMembers();
    static bool savelibrary();
    static void displayAllMembers();
};


#endif //PROJECT_MEMBER_H
