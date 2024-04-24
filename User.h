
#ifndef PROJECT_LIBRARIAN_H
#define PROJECT_LIBRARIAN_H

#include <iostream>
#include "Custom_String_Class.h"
#include <vector>
#include "Book.h"
#include "Loan.h"
#include <fstream>
#include "json.h"


using json = nlohmann::json;
using namespace std;


class Member {
private:
    vector<Loan> checkedOutBooks;
    int Fines;
protected:
    Custom_String_Class Name;
    int ID;
    Custom_String_Class Type;
    static vector<Member> members;
public:
    Member();
    Member(const Custom_String_Class& ,int ,const Custom_String_Class& );

    Custom_String_Class getName() const;
    int getID() const;
    Custom_String_Class getType() const;
    int getFines() const;
    static vector<Member>& getMembers();
    vector<Loan>& getCheckedOutBooks();

    void setName(const Custom_String_Class&);
    void setID(int);
    void setType(const Custom_String_Class&);
    void setFines(int f);

    int calculateTotalFines ();
    void updateTotalFines ();

    void display();
    void displayloaned() const;

    void requestBorrow(Book&);
    void returnBook(Book) ;
};


class Librarian : public Member{
private:
    static std::vector<Loan> borrowRequests;
    static std::vector<Librarian> librarians;
public:
    Librarian();
    Librarian(const Custom_String_Class& name, int ID);

    static vector<Librarian>& getLibrarians();
    static vector<Loan>& getBorrowRequests();

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
    void display();

    static bool loadLibrarian();
    static bool saveLibrarian();

    static Librarian findLibrarianByName(Custom_String_Class);
    static Librarian findLibrarianByID(int);
    static Member findMemberByName(Custom_String_Class);
    static Member findMemberByID(int);


    static bool loadMembers();
    static bool saveMembers();

    void displayRequests();

};


#endif //PROJECT_LIBRARIAN_H
