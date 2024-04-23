
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


protected:
    int Fines;
    Custom_String_Class Name;
    int ID;
    Custom_String_Class Type;


    static vector<Member> members;
public:
    vector<Loan> checkedOutBooks;
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

    static Member findByID(int);
    static Book findBookByAuthor(Custom_String_Class);
    static void displayAllMembers();


};


class Librarian : public Member{
public:
    Librarian();
    Librarian(const Custom_String_Class& name, int ID);

    static std::vector<Loan> borrowRequests;
    static std::vector<Librarian> librarians;
    static vector<Librarian>& getLibrarians();
// Additional functionalities specific to Librarian

    void addBook();
    void removeBook(const Custom_String_Class& ISBN);
    void manageMemberAccounts();
    void editBook( Book& book);
    static void addBorrowRequest(Loan&);
    bool borrowBook(Book, Member);
    void approveBorrowRequest(Loan);
    static void returnBook(Member& member, Book& book);//not working
    void registerNewMember();
    void removeMember();
    void displayAllMembers();
    static bool loadLibrarian();
    static bool saveLibrarian();
    static Librarian findByID(int);

    static bool loadMembers();
    static bool saveMembers();

    void displayRequests();

};


#endif //PROJECT_LIBRARIAN_H
