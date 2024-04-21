#include "Librarian.h"


Librarian::Librarian():Member() {}

Librarian::Librarian(const Custom_String_Class& name, int ID) : Member(name, ID, Custom_String_Class("Librarian")) {}

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
    int publicationYear;
    cout << "Enter book's publication year: " << endl;
    cin >> publicationYear;
    int Quantity;
    cout<<"Enter Book's Quantity:";
    cin>>Quantity;
    Book newBook(title,author,isbn,genre,publicationYear,Quantity);
    Book::getBookList().push_back(newBook);
}
void Librarian::removeBook(const Custom_String_Class& ISBN) {
    for(auto it = Book::getBookList().begin(); it != Book::getBookList().end() + 1; ) {
        if(it->getISBN() == ISBN) {
            cout << "Now Iam removing \n";
            Book::getBookList().erase(it);
            return;
        } else {
            ++it; // move to the next element
        }
    }
}

void Librarian::addBorrowRequest(Loan& ln) {
    borrowRequests.push_back(ln);
}
void Librarian::displayRequests() {
    if (borrowRequests.empty()) {
        cout << "No pending borrow requests." << std::endl;
        return;
    }

    cout << "Pending Borrow Requests:\n";
    for (size_t i = 0; i < borrowRequests.size(); ++i) {
        const auto& request = borrowRequests[i];
        cout << i + 1 << ". Member ID: " << request.getMemberID()
             << ", Book ISBN: " << request.getBookID() << std::endl;
    }
}

bool Librarian::borrowBook(Book b, Member member){
    vector<Book>& bkList= Book::getBookList();
    vector<Loan>& checkedBooks= member.getCheckedOutBooks();
    vector<Loan>& loansList= Loan::getLoans_List();

    int i;
    for(i=0; !(bkList[i].getISBN() == b.getISBN()); i++);

    if(bkList[i].getQuantity()>0) {
        Date dueDate;
        if (bkList[i].getQuantity()==1){
            bkList[i].setAvailability(false);
        }
        bkList[i].setQuantity(bkList[i].getQuantity()-1);
        if(Type==Custom_String_Class("Member"))
            dueDate = Date::getCrrentDate() + 7;
        else if(Type==Custom_String_Class("Staff"))
            dueDate = Date::getCrrentDate() + 10;
        else if(Type==Custom_String_Class("Faculty"))
            dueDate = Date::getCrrentDate() + 14;
        Loan newloan(ID, bkList[i].getISBN(), dueDate);
        checkedBooks.push_back(newloan);
        loansList.push_back(newloan);
        return true;
    }
    else{
        cout << "there is no copies of the book available"<<endl;
        return false;
    }
}

void Librarian::approveBorrowRequest(Loan ln) {
    int i=0;
    Book bk = Book::findByISBN(ln.getBookID());
    Member member = Member::findByID(ln.getMemberID());

    for(auto it =borrowRequests.begin(); it != borrowRequests.end() + 1; ) {
        if(it->getBookID() == ln.getBookID() && it->getMemberID() ==ln.getMemberID()) {
            break;
        } else {
            i++;
            ++it;
        }
    }
    for(auto it =borrowRequests.begin(); it != borrowRequests.end() + 1; ) {
        if(it->getBookID() == ln.getBookID() && it->getMemberID() ==ln.getMemberID()) {
            cout << "Now Iam removing \n";
            borrowRequests.erase(it);
            break;
        } else {
            ++it;
        }
    }

    if(borrowBook(bk, member))
        cout << "Borrow request approved and book issued." << endl;
}

void Librarian::returnBook(Member& member, Book& book) {
    vector<Book>& bkList= Book::getBookList();
    vector<Loan>& checkedBooks= member.getCheckedOutBooks();
    vector<Loan>& loansList= Loan::getLoans_List();

    int i;
    for(i=0; bkList[i].getISBN() != bkList[i].getISBN(); i++);
    if(bkList[i].getQuantity()==0)
        bkList[i].setAvailability(true);
    bkList[i].setQuantity(bkList[i].getQuantity()+1);
    for(auto it = checkedBooks.begin(); it != checkedBooks.end() + 1; ) {
        if(it->getBookID() == bkList[i].getISBN() && it->getMemberID()==member.getID()) {
            cout << "Now Iam removing \n";
            checkedBooks.erase(it);
            break;
        } else {
            ++it;
        }
    }
    for(auto it =loansList.begin(); it != loansList.end() + 1; ) {
        if(it->getBookID() == bkList[i].getISBN() && it->getMemberID()==member.getID()) {
            cout << "Now Iam removing \n";
            loansList.erase(it);
            break;
        } else {
            ++it;
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
        cout << "Enter book's title: " << endl;
        cin >> book.getTitle();
    }
    cout << "Do you want to edit the ISBN ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout << "Enter book's ISBN: " << endl;
        cin >> book.getISBN();
    }
    cout << "Do you want to edit the author ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout << "Enter author's name: " << endl;
        cin >> book.getAuthor();
    }
    cout << "Do you want to edit the genre ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout << "Enter book's genre: " << endl;
        cin >> book.getGenre();
    }
    cout << "Do you want to edit the publication year ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout << "Enter book's publication year: " << endl;
        cin >> book.getPubYear();
    }
    cout << "Do you want to edit the quantity ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout<<"Enter Book's Quantity:";
        cin>>book.getQuantity();
    }
    book.setAvailability(book.getQuantity()>0);

}
//
void Librarian::registerNewMember(){
    Custom_String_Class name, type;
    int id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter type: ";
    cin >> type;
    members.push_back(Member(name, id, type));
    cout << "New member registered successfully.\n";
}

void Librarian::removeMember()
{
    int id;
    cout << "Enter member ID to remove: ";
    cin >> id;
    bool found = false;
    for (auto it = members.begin(); it != members.end() + 1 ; ++it) {
        if (it->getID() == id) {
            members.erase(it);
            cout << "Member with ID " << id << " removed successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Member not found.\n";
    }
}

void Librarian::displayAllMembers() {
    std::cout << "List of Members:\n";
    for (auto& member : members) {
        member.display();
        std::cout << "-------------------------\n";
    }

}

void Librarian::manageMemberAccounts() {

    int choice;
    do {
        cout << "1. Register new member\n";
        cout << "2. Remove member\n";
        cout << "3. Display all members\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                // Register new member
                registerNewMember();
                break;
            }
            case 2: {
                // Remove member
                removeMember();
                break;
            }
            case 3: {
                // Display all members
                displayAllMembers();
                break;
            }

            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

bool Librarian::loadLibrarian() {
    std::ifstream file("borrowRequests.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return false;
    }

    json j;
    file >> j;

    for (const auto& Requests_json : j) {
        Loan ln(Requests_json["memberID"], Custom_String_Class(Requests_json["bookID"].get<string>()), Date(Custom_String_Class(Requests_json["dueDate"].get<string>())), Date(Custom_String_Class(Requests_json["borrowDate"].get<string>())));
        borrowRequests.push_back(ln);
    }
    file.close();
    return true;
}
bool Librarian::saveLibrarian() {
    std::ofstream file("borrowRequests.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << endl;
        return false;
    }
    json OUTPUT;
    for(const auto& ln : borrowRequests)
    {
        json bookJson;

        bookJson["memberID"] = ln.getMemberID();
        bookJson["bookID"] = ln.getBookID().str;
        bookJson["dueDate"] = ln.getDueDate().getDate().str;
        bookJson["borrowDate"] = ln.getBorrowDate().getDate().str;

        OUTPUT.push_back(bookJson);
    }
    file<<setw(4)<<OUTPUT<<endl;// what is the meaning of setw(4) ya ziad
    file.close();
    return true;
}