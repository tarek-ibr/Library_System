
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
    void addBook(const Book& book);
    void removeBook(const Custom_String_Class& ISBN);
    void manageMemberAccounts();
    // Other functionalities...
};


#endif //PROJECT_LIBRARIAN_H
