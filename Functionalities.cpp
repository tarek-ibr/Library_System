//
// Created by tarek on 4/22/2024.
//

#include "Functionalities.h"


Custom_String_Class login(int id){
    vector<Member>& member = Member::getMembers();
    vector<Librarian>& librarian = Librarian::getLibrarians();

    for(auto it:member){
        if(id==it.getID()){
            return "member";
        }
    }
    for(auto it:librarian){
        if(id==it.getID()){
            return "librarian";
        }
    }
    return "not found";
}

void diplayMenuMember(){
    cout << "Select an option:\n";
    cout << "1. Request to borrow a book\n";
    cout << "2. Return a book\n";
    cout << "3. Display loaned books\n";
    cout << "4. Display your information\n";
    cout << "5. Display book list\n";
    cout << "6. Exit\n";
}

void displayMenuLibrarian()
{
    cout << "Select an option:\n";
    cout << "1. Add book\n";
    cout << "2. Remove book\n";
    cout << "3. Register new member\n";
    cout << "4. Remove member\n";
    cout << "5. Edit book\n";
    cout << "6. Approve borrow request\n";
    cout << "7. Return book\n";
    cout << "8. Display all members\n";
    cout << "9. Display all books\n";
    cout << "10. Display borrow requests\n";
    cout << "11. Exit\n";
}

void implementMemberChoice(Member& member, int memberOption){
    if (memberOption == 1) {
        cout << "Enter ISBN of book to borrow: ";
        Custom_String_Class isbn;
        cin >> isbn;
        Book book = Book::findByISBN(isbn);
        member.requestBorrow(book);
    } else if (memberOption == 2) {
        cout << "Enter ISBN of book to return: ";
        Custom_String_Class isbn;
        cin >> isbn;
        Book book = Book::findByISBN(isbn);
        member.returnBook(book);
    } else if (memberOption == 3) {
        member.displayloaned();
    } else if (memberOption == 4) {
        member.display();
    } else if (memberOption == 5) {
        Book::displaylist();
    }
}

void implementLibrarianChoice(Librarian& librarian, int librarianOption){
    if (librarianOption == 1) {
        librarian.addBook();
    } else if (librarianOption == 2) {
        cout << "Enter ISBN of book to remove: ";
        Custom_String_Class isbn;
        cin >> isbn;
        librarian.removeBook(isbn);
    } else if (librarianOption == 3) {
        librarian.registerNewMember();
    } else if (librarianOption == 4) {
        librarian.removeMember();
    } else if (librarianOption == 5) {
        cout << "Enter ISBN of book to edit: ";
        Custom_String_Class isbn;
        cin >> isbn;
        Book book = Book::findByISBN(isbn);
        librarian.editBook(book);
    } else if (librarianOption == 6) {
        Loan loan = Loan::getLoans_List().back(); // will be edited ".back()"
        librarian.approveBorrowRequest(loan);
    } else if (librarianOption == 7) {
        cout << "Enter member ID: ";
        int memberId;
        cin >> memberId;
        Member member = Member::findByID(memberId);
        cout << "Enter ISBN of book to return: ";
        Custom_String_Class isbn;
        cin >> isbn;
        Book book = Book::findByISBN(isbn);
        librarian.returnBook(member, book);
    } else if (librarianOption == 8) {
        librarian.displayAllMembers();
    } else if (librarianOption == 9) {
        Book::displaylist();
    } else if (librarianOption == 10) {
        librarian.displayRequests();
    }
}