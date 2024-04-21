
#ifndef PROJECT_LIBRARIAN_H
#define PROJECT_LIBRARIAN_H

#include <iostream>
#include "Custom_String_Class.h"
#include <vector>
#include "Book.h"
#include "Loan.h"
#include <fstream>
#include "json.h"
#include "User.h"

using json = nlohmann::json;
using namespace std;


class Member {
private:

    int Fines;
protected:
    Custom_String_Class Name;
    int ID;
    Custom_String_Class Type;


    static vector<Member> members;
public:
    vector<Loan> checkedOutBooks;
    Member();
    Member(const Custom_String_Class& ,int ,const Custom_String_Class& );
    Custom_String_Class getName();
    int getID() const;
    Custom_String_Class getType();
    int getFines();
    vector<Loan>& getCheckedOutBooks();
    void setName(const Custom_String_Class&);
    void setID(int);
    void setType(const Custom_String_Class&);
    int calculateTotalFines ();
    void display();
    void displayloaned() const;
    void requestBorrow(Book&);
    void returnBook(Book) ;
    static bool loadMembers();
    static bool saveMembers();
    static Member findByID(int);
    static void displayAllMembers();

};


class Librarian : public Member{
public:
    Librarian();
    Librarian(const Custom_String_Class& name, int ID);

    static std::vector<Loan> borrowRequests;

// Additional functionalities specific to Librarian
    static vector<Librarian> librarians;
    void addBook();
    void removeBook(const Custom_String_Class& ISBN);
    void manageMemberAccounts();
    void editBook( Book& book);
    static void addBorrowRequest(Loan&);
    bool borrowBook(Book, Member);
    void approveBorrowRequest(Loan);
    static void returnBook(Member& member, Book& book);
    void registerNewMember();
    void removeMember();
    void displayAllMembers();
    static bool loadLibrarian();
    static bool saveLibrarian();
    static Librarian findByID(int);

    void displayRequests();

};


#endif //PROJECT_LIBRARIAN_H
