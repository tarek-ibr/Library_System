#include "Librarian.h"


Librarian::Librarian() {}

Librarian::Librarian(const Custom_String_Class& name, int ID) : Member(name, ID, "Librarian") {}

void Librarian::addBook() {
    // add a book to the library inventory
    Custom_String_Class title;
    cout << "Enter book's title: " << endl;
    cin >> title;
    Custom_String_Class isbn;
    cout << "Enter book's ISBN: " << endl;
    cin >> isbn;
    Custom_String_Class author;
    cout << "Enter author's name: " << endl;
    cin >> author;
    Custom_String_Class genre;
    cout << "Enter book's genre: " << endl;
    cin >> genre;
    Custom_String_Class duedate;
    cout << "Enter book's duedate: " << endl;
    cin >> duedate;
    int publicationYear;
    cout << "Enter book's publication year: " << endl;
    cin >> publicationYear;
    bool availablity;
    cout << "Enter whether the book is available or not(Y/N): " << endl;
    char ans;
    cin >> ans;
    int Quantity;
    if(ans='N')
      Quantity=0;
    else
    {
        cout<<"Enter Book Quantity:";
        cin>>Quantity;
    }

    (ans == 'Y')? availablity = 1: availablity = 0;
    Book newBook(title,author,isbn,genre,publicationYear,availablity,Quantity);
    Book::Book_List.push_back(newBook);
}
void Librarian::removeBook(const Custom_String_Class& ISBN) {
    for(auto it = Book::Book_List.begin(); it != Book::Book_List.end() + 1; ) {
        if(it->ISBN == ISBN) {
            cout << "Now Iam removing \n";
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
    cout << "Do you want to edit the title ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Title;
    }
    cout << "Do you want to edit the ISBN ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.ISBN;
    }
    cout << "Do you want to edit the author ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Author;
    }
    cout << "Do you want to edit the genre ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Genre;
    }
    cout << "Do you want to edit the publication year ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Publication_Year;
    }
    cout << "Do you want to edit the availability ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin >> book.Available;
    }

}
//
void Librarian::manageMemberAccounts() {
    // manage member accounts (register new members, remove members, etc.)
}

