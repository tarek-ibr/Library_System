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

void Librarian::editBook(Book& book)
{
    char answer;
    cout << "Do you want to edit the title ?(Y/N)";
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Title;
    }
    cout << "Do you want to edit the ISBN ?(Y/N)";
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.ISBN;
    }
    cout << "Do you want to edit the author ?(Y/N)";
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Author;
    }
    cout << "Do you want to edit the genre ?(Y/N)";
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Genre;
    }
    cout << "Do you want to edit the due date ?(Y/N)";
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.duedate;
    }
    cout << "Do you want to edit the publication year ?(Y/N)";
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Publication_Year;
    }
    cout << "Do you want to edit the availability ?(Y/N)";
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Available;
    }

}
void Librarian::manageMemberAccounts() {
    // manage member accounts (register new members, remove members, etc.)
}

