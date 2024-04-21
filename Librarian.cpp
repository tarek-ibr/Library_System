#include "Librarian.h"
#include "Request.h"



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

void Librarian::addBorrowRequest(Request& request) {
    borrowRequests.push_back(request);
}
void Librarian::displayRequests() {
    cout << "Pending Borrow Requests:\n";
    for (size_t i = 0; i < borrowRequests.size(); ++i) {
        const auto& request = borrowRequests[i];
        cout << i + 1 << ". Member ID: " << request.memberID
             << ", Book ISBN: " << request.bookISBN << std::endl;
    }
}

void Librarian::approveBorrowRequest() {
    if (borrowRequests.empty()) {
        cout << "No pending borrow requests." << std::endl;
        return;
    }

    int choice;
    cout << "Enter the number of the request to approve (or 0 to cancel): ";
    cin >> choice;

    if (choice == 0) {
        cout << "Request approval canceled." << std::endl;
        return;
    }

    if (choice > 0 && choice <= borrowRequests.size()) {
        const auto& approvedRequest = borrowRequests[choice - 1];
        // Find the member
        auto memberIt = std::find_if(Member::members.begin(), Member::members.end(),
                                     [&approvedRequest](const Member& m) {
                                         return m.getID() == approvedRequest.memberID;
                                     });

        // Find the book
        auto bookIt = std::find_if(Book::getBookList().begin(), Book::getBookList().end(),
                                   [&approvedRequest](const Book& b) {
                                       return b.getISBN() == approvedRequest.bookISBN;
                                   });

        if (memberIt != Member::members.end() && bookIt != Book::getBookList().end()) {
            Member& member = *memberIt;
            Book& book = *bookIt;

            if (book.getQuantity() > 0) {
                // Adjust book inventory
                if (book.getQuantity() == 1) {
                    book.setAvailability(false);
                }
                book.setQuantity(book.getQuantity() - 1);

                // Assign due date based on member type
                Date dueDate;
                if (member.getType() == Custom_String_Class("Member")) {
                    dueDate = Date::getCrrentDate() + 7;
                } else if (member.getType() == Custom_String_Class("Staff")) {
                    dueDate = Date::getCrrentDate() + 10;
                } else if (member.getType() == Custom_String_Class("Faculty")) {
                    dueDate = Date::getCrrentDate() + 14;
                }

                Loan newLoan(member.getID(), book.getISBN(), dueDate);
                member.checkedOutBooks.push_back(newLoan);
                Loan::Loans_List.push_back(newLoan);

                cout << "Borrow request approved and book issued." << std::endl;

                // Remove the approved request from the list
                borrowRequests.erase(borrowRequests.begin() + choice - 1);
            } else {
                cout << "No copies of the book are available." << std::endl;
            }
        } else {
            cout << "Invalid request. Either the member or book could not be found." << std::endl;
        }
    } else {
        cout << "Invalid choice." << std::endl;
    }
}

void Librarian::rejectBorrowRequest() {
    if (borrowRequests.empty()) {
        cout << "No pending borrow requests." << std::endl;
        return;
    }

    cout << "Pending Borrow Requests:\n";
    for (size_t i = 0; i < borrowRequests.size(); ++i) {
        const auto& request = borrowRequests[i];
        cout << i + 1 << ". Member ID: " << request.memberID
             << ", Book ISBN: " << request.bookISBN << std::endl;
    }

    int choice;
    cout << "Enter the number of the request to reject (or 0 to cancel): ";
    cin >> choice;

    if (choice == 0) {
        cout << "Request rejection canceled." << std::endl;
        return;
    }

    if (choice > 0 && choice <= borrowRequests.size()) {
        cout << "Borrow request rejected." << std::endl;
        // Remove the rejected request from the list
        borrowRequests.erase(borrowRequests.begin() + choice - 1);
    } else {
        cout << "Invalid choice." << std::endl;
    }
}


void Librarian::returnBook(Member& member, Book& book) {
    member.returnBook(book);
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

