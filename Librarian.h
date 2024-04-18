
#ifndef PROJECT_LIBRARIAN_H
#define PROJECT_LIBRARIAN_H


#include "Member.h"

class Librarian : public Member {
public:
    Librarian();
    Librarian(const Custom_String_Class& name, int ID);
    // Define other necessary constructors, destructor, and member functions

    Librarian(const Custom_String_Class &name, int ID, const Custom_String_Class &Type);



// Additional functionalities specific to Librarian
    void addBook();
    void removeBook(const Custom_String_Class& ISBN);
    void manageMemberAccounts();
    void editBook( Book& book);
    void borrowBook(Member& member, Book& book);
    void returnBook(Member& member, Book& book);
};


#endif //PROJECT_LIBRARIAN_H
