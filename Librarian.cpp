#include "Librarian.h"


Librarian::Librarian() {}

Librarian::Librarian(const Custom_String_Class& name, int ID) : Member(name, ID, "Librarian") {}

void Librarian::addBook() {
    // add a book to the library inventory
    Custom_String_Class title;
    cin >> title;
    Custom_String_Class isbn;
    cin >> isbn;
    Custom_String_Class author;
    cin >> author;
    Custom_String_Class genre;
    cin >> genre;
    Custom_String_Class duedate;
    cin >> duedate;
    int publicationYear;
    cin >> publicationYear;
    bool availablity;
    cin >> availablity;
    Book newBook(title,author,isbn,genre,duedate,publicationYear,availablity);
    Book::Book_List.push_back(newBook);
}
void Librarian::removeBook(const Custom_String_Class& ISBN) {
    for(auto it = Book::Book_List.begin(); it != Book::Book_List.end(); ) {
        if(it->ISBN.str == ISBN.str) {
            it = Book::Book_List.erase(it);
            return;// erase and get the next valid iterator
        } else {
            ++it; // move to the next element
        }
    }
}

void Librarian::editBook(const Book& book)
{
    // Edit book's data such as number of pages
}
void Librarian::manageMemberAccounts() {
    // manage member accounts (register new members, remove members, etc.)
}

