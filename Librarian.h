
#ifndef PROJECT_LIBRARIAN_H
#define PROJECT_LIBRARIAN_H

#include "Member.h"

class Librarian : public Member{
public:
    Librarian();
    Librarian(const Custom_String_Class& name, int ID);

    static std::vector<Loan> borrowRequests;

// Additional functionalities specific to Librarian
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

    void displayRequests();

};


#endif //PROJECT_LIBRARIAN_H
