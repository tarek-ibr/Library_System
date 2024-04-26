// Include the necessary header files
#include "Functionalities.h"

// Function to save all data to files
void saveFiles(){
    // Save all members, loans, librarians, and books
    Librarian::saveMembers();
    Loan::saveLoans();
    Librarian::saveLibrarian();
    Book::savelibrary();
}

// Function to load all data from files
void loadFiles(){
    // Load all members, loans, librarians, and books
    Librarian::loadMembers();
    Loan::loadLoans();
    Librarian::loadLibrarian();
    Book::loadlibrary();
}

// Function to login a user
Custom_String_Class login(int id){
    // Get all members and librarians
    vector<Member>& member = Member::getMembers();
    vector<Librarian>& librarian = Librarian::getLibrarians();

    // Check if ID matches any member or librarian
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

// Function to load all data from files
void LoadFiles()
{
    Book::loadlibrary();
    Loan::loadLoans();
    Librarian::loadMembers();
    Librarian::loadLibrarian();
}

// Function to save all data to files
void SaveFiles()
{
    Book::savelibrary();
    Loan::saveLoans();
    Librarian::saveMembers();
    Librarian::saveLibrarian();
}


// Function to implement the choice of a member
void implementMemberChoice(Member& member, int memberOption){

    cin.ignore();
    switch (memberOption) {
        case 1: {
            // Option 1: Borrow a book
            Book::displaylist();
            cout << "\n Choose a book to borrow: ";
            int choice;
            cin >> choice;
            vector<Book> bookList = Book::getBookList();
            Book book = bookList[choice - 1];
            member.requestBorrow(book);
            break;
        }
        case 2: {
            // Option 2: Return a book
            member.displayloaned();
            cout << "\n Choose a book to return: ";
            int choice;
            cin >> choice;
            vector<Loan> loanedbooks = member.getCheckedOutBooks();
            Book loanedbook = Book::findByISBN(loanedbooks[choice - 1].getBookID());
            member.returnBook(loanedbook);
            break;
        }
        case 3: {
            // Option 3: Display loaned books
            member.displayloaned();
            break;
        }
        case 4: {
            // Option 4: Display member details
            member.display();
            break;
        }
        case 5: {
            // Option 5: Display all books
            Book::displaylist();
            break;
        }
        case 6: {
            // Option 6: Find a book
            displayMenuFindBook();
            int findOptions;
            cin >> findOptions;
            implementFindBookChoice(findOptions);
            break;
        }
        default: {
            break;
        }
    }

}

// Function to implement the choice of the librarian
void implementLibrarianChoice(Librarian& librarian, int librarianOption){
    cin.ignore();
    switch (librarianOption) {
        case 1:
            // Option 1: Add a book
            librarian.addBook();
            break;
        case 2: {
            // Option 2: Remove a book
            Book::displaylist();
            int choice;
            cout << "\n Enter you choice: ";
            cin >> choice;
            vector<Book> bookList = Book::getBookList();
            Book book = bookList[choice - 1];
            librarian.removeBook(book.getISBN());
            break;
        }
        case 3:
            // Option 3: Register a new member
            librarian.registerNewMember();
            break;
        case 4: {
            // Option 4: Remove a member
            librarian.displayAllMembers();
            int choice;
            cout << "\n Enter you choice: ";
            cin >> choice;
            vector<Member> members= Member::getMembers();
            Member member = members[choice-1];
            librarian.removeMember(member.getID());
            break;
        }
        case 5: {
            // Option 5: Edit a book
            Book::displaylist();
            int choice;
            cout << "\n Enter you choice: ";
            cin >> choice;
            Book& book = Book::getBookList()[choice - 1];
            librarian.editBook(book);
            break;
        }
        case 6: {
            // Option 6: Approve a borrow request
            librarian.displayRequests();
            int choice;
            cin >> choice;
            vector<Loan>& requests = Librarian::getBorrowRequests();
            Loan loan = requests[choice - 1];
            librarian.approveBorrowRequest(loan);
            break;
        }
        case 7: {
            // Option 7: Return a book
            cout << "Enter member ID: ";
            int memberId;
            cin >> memberId;
            cin.ignore();
            Member member = Librarian::findMemberByID(memberId);
            cout << "Enter ISBN of book to return: ";
            Custom_String_Class isbn;
            cin >> isbn;
            Book book = Book::findByISBN(isbn);
            librarian.returnBook(member, book);
            break;
        }
        case 8:
            // Option 8: Display all members
            librarian.displayAllMembers();
            break;
        case 9:
            // Option 9: Display all books
            Book::displaylist();
            break;
        case 10:
            // Option 10: Display all requests
            librarian.displayRequests();
            break;
        case 11:
            // Option 11: Display all loans
            Loan::displaylist();
            break;
        case 12: {
            // Option 12: Find a book
            displayMenuFindBook();
            int findOptions;
            cin >> findOptions;
            implementFindBookChoice(findOptions);
            break;
        }
        case 13: {
            // Option 13: Find a member
            displayMenuFindMember();
            int findOptions;
            cin >> findOptions;
            implementFindMemberChoice(findOptions);
            break;
        }
        case 14: {
            // Option 14: Find a librarian
            displayMenuFindlibrarian();
            int findOptions;
            cin >> findOptions;
            implementFindLibrarianChoice(findOptions);
            break;
        }
        default:
            break;
    }
}

// Function to implement the choice of finding a book
void implementFindBookChoice(int option){
    switch (option) {
        case 1: {
            // Option 1: Find a book by ISBN
            cout << "enter the ISBN of the book you want to find" << endl;
            Custom_String_Class isbn;
            cin.ignore();
            cin >> isbn;
            Book bk = Book::findByISBN(isbn);
            if (!(bk.getTitle() == Book().getTitle()))
                bk.displayBook();
            break;
        }
        case 2: {
            // Option 2: Find a book by title
            cout << "enter the title of the book you want to find" << endl;
            Custom_String_Class title;
            cin.ignore();
            cin >> title;
            Book bk = Book::findByName(title);
            if (!(bk.getTitle() == Book().getTitle()))
                bk.displayBook();
            break;
        }
        case 3: {
            // Option 3: Find a book by author
            cout << "enter the name of author of the book you want to find" << endl;
            Custom_String_Class author;
            cin.ignore();
            cin >> author;
            Book bk = Book::findByAuthor(author);
            if (!(bk.getTitle() == Book().getTitle()))
                bk.displayBook();
            break;
        }
        default: {
            break;
        }
    }
}

// Function to implement the choice of finding a member
void implementFindMemberChoice(int option){
    switch (option) {
        case 1: {
            // Option 1: Find a member by name
            cout << "enter the name of the member you want to find" << endl;
            Custom_String_Class name;
            cin.ignore();
            cin >> name;
            Member member = Librarian::findMemberByName(name);
            cout<<"\n";
            if (!(member.getName() == Member().getName()))
                member.display();
            break;
        }
        case 2: {
            // Option 2: Find a member by ID
            cout << "enter the ID of the member you want to find" << endl;
            int id;
            cin >> id;
            Member member = Librarian::findMemberByID(id);
            cout<<"\n";
            if (!(member.getName() == Member().getName()))
                member.display();
            break;
        }
        default: {
            break;
        }
    }
}

// Function to implement the choice of finding a librarian
void implementFindLibrarianChoice(int option){
    switch (option) {
        case 1: {
            // Option 1: Find a librarian by name
            cout << "enter the name of the librarian you want to find" << endl;
            Custom_String_Class name;
            cin.ignore();
            cin >> name;
            Librarian librarian = Librarian::findLibrarianByName(name);
            cout<<"\n";
            if (!(librarian.getName() == Librarian().getName()))
                librarian.display();
            break;
        }
        case 2: {
            // Option 2: Find a librarian by ID
            cout << "enter the ID of the librarian you want to find" << endl;
            int id;
            cin >> id;
            Librarian librarian = Librarian::findLibrarianByID(id);
            cout<<"\n";
            if (!(librarian.getName() == Librarian().getName()))
                librarian.display();
            break;
        }
        default: {
            break;
        }
    }
}
