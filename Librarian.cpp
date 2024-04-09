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
    Book::Book_List.push_back(newBook);
}
void Librarian::removeBook(const Custom_String_Class& ISBN) {
    for(auto it = Book::Book_List.begin(); it != Book::Book_List.end() + 1; ) {
        if(it->ISBN == ISBN) {
            cout << "Now Iam removing \n";
            Book::Book_List.erase(it);
            return;
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
        cout << "Enter book's title: " << endl;
        cin >> book.Title;
    }
    cout << "Do you want to edit the ISBN ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout << "Enter book's ISBN: " << endl;
        cin >> book.ISBN;
    }
    cout << "Do you want to edit the author ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout << "Enter author's name: " << endl;
        cin >> book.Author;
    }
    cout << "Do you want to edit the genre ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout << "Enter book's genre: " << endl;
        cin >> book.Genre;
    }
    cout << "Do you want to edit the publication year ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout << "Enter book's publication year: " << endl;
        cin >> book.Publication_Year;
    }
    cout << "Do you want to edit the quantity ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cout<<"Enter Book's Quantity:";
        cin>>book.Quantity;
    }
    book.Available=book.Quantity>0;

}
//
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
                break;
            }
            case 2: {
                // Remove member
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
                break;
            }
            case 3: {
                // Display all members
                std::cout << "List of Members:\n";
                for (auto& member : members) {
                    member.display();
                    std::cout << "-------------------------\n";
                }
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

