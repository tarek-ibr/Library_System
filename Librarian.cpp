#include "Librarian.h"

Librarian::Librarian() {}

Librarian::Librarian(const Custom_String_Class& name, int ID) : Member(name, ID, "Librarian") {}

void Librarian::addBook(const Book& book) {
    // add a book to the library inventory
}
void Librarian::removeBook(const Custom_String_Class& ISBN) {
    //  remove a book from the library inventory
}
void Librarian::editBook(const Book& book)
{
    // Edit book's data such as number of pages
}
void Librarian::manageMemberAccounts() {
    // manage member accounts (register new members, remove members, etc.)
}

