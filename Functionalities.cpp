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
    cout << "\nSelect an option:\n";
    cout << "1. Request to borrow a book\n";
    cout << "2. Return a book\n";
    cout << "3. Display loaned books\n";
    cout << "4. Display your information\n";
    cout << "5. Display book list\n";
    cout << "6. Exit\n";
}

void displayMenuLibrarian()
{
    cout << "\nSelect an option:\n";
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
    cin.ignore();
    if (memberOption == 1) {
        Book::displaylist();
        int choice;
        cin>>choice;
        vector<Book> bookList = Book::getBookList();
        Book book = bookList[choice-1];
        member.requestBorrow(book);
    } else if (memberOption == 2) {
        member.displayloaned();
        cout<<"\n Choose a book to return: ";
        int choice;
        cin>>choice;
        vector<Loan> loanedbooks = member.getCheckedOutBooks();
        Book loanedbook = Book::findByISBN(loanedbooks[choice-1].getBookID());
        member.returnBook(loanedbook);
    } else if (memberOption == 3) {
        member.displayloaned();
    } else if (memberOption == 4) {
        member.display();
    } else if (memberOption == 5) {
        Book::displaylist();
    }
}

void implementLibrarianChoice(Librarian& librarian, int librarianOption){
    cin.ignore();
    if (librarianOption == 1) {
        librarian.addBook();
    } else if (librarianOption == 2) {
        Book::displaylist();
        int choice;
        cout << "\n Enter you choice: ";
        cin>>choice;
        vector<Book> bookList = Book::getBookList();
        Book book = bookList[choice-1];
        librarian.removeBook(book.getISBN());
    } else if (librarianOption == 3) {
        librarian.registerNewMember();
    } else if (librarianOption == 4) {
        librarian.displayAllMembers();
        cout << "\n";
        librarian.removeMember();
    } else if (librarianOption == 5) {
        Book::displaylist();
        int choice;
        cout << "\n Enter you choice: ";
        cin>>choice;

        Book& book =  Book::getBookList()[choice-1];
        librarian.editBook(book);
    } else if (librarianOption == 6) {
        librarian.displayRequests();
        int choice;
        cin>>choice;
        vector<Loan>& requests = Librarian::getBorrowRequests();
        Loan loan = requests[choice-1];
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