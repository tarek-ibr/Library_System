//
// Created by tarek on 4/22/2024.
//

#include "Functionalities.h"


void saveFiles(){
    Librarian::saveMembers();
    Loan::saveLoans();
    Librarian::saveLibrarian();
    Book::savelibrary();
}

void loadFiles(){
    Librarian::loadMembers();
    Loan::loadLoans();
    Librarian::loadLibrarian();
    Book::loadlibrary();
}

string* executeGUIOption(string* options, size_t num_options) {

    loadFiles();

    vector<string> response = {};

    string* response_array = new string[num_options];

    int operation = std::stoi(options[0]);

    switch (operation) {
        case 1:
            response.push_back(login(std::stoi(options[1])).toString());
            break;
        case 2: {
            Librarian librarian = Librarian::findLibrarianByID(stoi(options[1]));

            string title = (options[2]);
            string isbn = (options[3]);
            string author = (options[4]);
            string genre = (options[5]);
            int publicationYear = stoi(options[6]);
            int Quantity = stoi(options[7]);
            Book newBook(title,author,isbn,genre,publicationYear,Quantity);
            Book::getBookList().push_back(newBook);

            break;
        }
        case 3: {
            Librarian librarian = Librarian::findLibrarianByID(stoi(options[1]));

            string isbn = options[2];
            librarian.removeBook(isbn);
            break;
        }
        case 4: {
            Librarian librarian = Librarian::findLibrarianByID(stoi(options[1]));
            vector<Member>& members= Librarian::getMembers();

            string name = options[2];
            string type = options[3];
            int id = stoi(options[4]);
            members.push_back(Member(name, id, type));
            break;
        }
        case 5: {
            Librarian librarian = Librarian::findLibrarianByID(stoi(options[1]));
            vector<Member>& members= Librarian::getMembers();

            int id = stoi(options[2]);

            for (auto it = members.begin(); it != members.end() ; ++it) {
                if (it->getID() == id) {
                    members.erase(it);
                    break;
                }
            }

            break;
        }
        case 6: {
            /*librarian.displayRequests();
            int choice;
            cin >> choice;
            vector<Loan>& requests = Librarian::getBorrowRequests();
            Loan loan = requests[choice - 1];
            librarian.approveBorrowRequest(loan);
            //to add approve request in gui*/
            break;
        }
        case 7: {
            Member member = Librarian::findMemberByID(stoi(options[1]));

            string isbn = (options[2]);

            Book book = Book::findByISBN(isbn);
            member.requestBorrow(book);
            break;
        }
        case 8:
            /*member.displayloaned();
            cout << "\n Choose a book to return: ";
            int choice;
            cin >> choice;
            vector<Loan> loanedbooks = member.getCheckedOutBooks();
            Book loanedbook = Book::findByISBN(loanedbooks[choice - 1].getBookID());
            member.returnBook(loanedbook);
            //to add return book*/
            break;
        default:
            break;
    }

    saveFiles();

    // Convert response vector to array
    for (size_t i = 0; i < response.size(); ++i) {
        response_array[i] = {response[i]};
    }
    return response_array;
}

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
void LoadFiles()
{
    Book::loadlibrary();
    Loan::loadLoans();
    Librarian::loadMembers();
    Librarian::loadLibrarian();
}
void SaveFiles()
{
    Book::savelibrary();
    Loan::saveLoans();
    Librarian::saveMembers();
    Librarian::saveLibrarian();
}
void diplayMenuMember(){
    cout << "\nSelect an option:\n";
    cout << "1. Request to borrow a book\n";
    cout << "2. Return a book\n";
    cout << "3. Display loaned books\n";
    cout << "4. Display your information\n";
    cout << "5. Display book list\n";
    cout << "6. Find a book\n";
    cout << "7. Logout\n";
    cout << "8. Exit\n";
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
    cout << "7. Return book\n";      //ana shayef nsheel de
    cout << "8. Display all members\n";
    cout << "9. Display all books\n";
    cout << "10. Display borrow requests\n";
    cout << "11. Display all loans\n";
    cout << "12. Find a book\n";
    cout << "13. Find a member\n";
    cout << "14. Find a librarian\n";
    cout << "15. Logout\n";
    cout << "16. Exit\n";
}

void displayMenuFindBook(){
    cout << "\nSelect an option:\n";
    cout << "1. Find the book by ISBN\n";
    cout << "2. Find the book by name\n";
    cout << "3. Find the book by author\n";
}

void displayMenuFindMember(){
    cout << "\nSelect an option:\n";
    cout << "1. Find the member by name\n";
    cout << "2. Find the member by ID\n";
}

void displayMenuFindlibrarian(){
    cout << "\nSelect an option:\n";
    cout << "1. Find the librarian by name\n";
    cout << "2. Find the librarian by ID\n";
}

void implementMemberChoice(Member& member, int memberOption){

    cin.ignore();
  switch (memberOption) {
      case 1: {
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
          member.displayloaned();
          break;
      }
      case 4: {
          member.display();
          break;
      }
      case 5: {
          Book::displaylist();
          break;
      }
      case 6: {
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

void implementLibrarianChoice(Librarian& librarian, int librarianOption){
    cin.ignore();
  switch (librarianOption) {
      case 1:
          librarian.addBook();
          break;
      case 2: {
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
          librarian.registerNewMember();
          break;
      case 4: {
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
          Book::displaylist();
          int choice;
          cout << "\n Enter you choice: ";
          cin >> choice;
          Book& book = Book::getBookList()[choice - 1];
          librarian.editBook(book);
          break;
      }
      case 6: {
          librarian.displayRequests();
          int choice;
          cin >> choice;
          vector<Loan>& requests = Librarian::getBorrowRequests();
          Loan loan = requests[choice - 1];
          librarian.approveBorrowRequest(loan);
          break;
      }
      case 7: {
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
          librarian.displayAllMembers();
          break;
      case 9:
          Book::displaylist();
          break;
      case 10:
          librarian.displayRequests();
          break;
      case 11:
          Loan::displaylist();
          break;
      case 12: {
          displayMenuFindBook();
          int findOptions;
          cin >> findOptions;
          implementFindBookChoice(findOptions);
          break;
      }
      case 13: {
          displayMenuFindMember();
          int findOptions;
          cin >> findOptions;
          implementFindMemberChoice(findOptions);
          break;
      }
      case 14: {
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

void implementFindBookChoice(int option){
  switch (option) {
      case 1: {
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

void implementFindMemberChoice(int option){
  switch (option) {
      case 1: {
          cout << "enter the name of the member you want to find" << endl;
          Custom_String_Class name;
          cin.ignore();
          cin >> name;
          Member member = Librarian::findMemberByName(name);
          if (!(member.getName() == Member().getName()))
              member.display();
          break;
      }
      case 2: {
          cout << "enter the ID of the member you want to find" << endl;
          int id;
          cin >> id;
          Member member = Librarian::findMemberByID(id);
          if (!(member.getName() == Member().getName()))
              member.display();
          break;
      }
      default: {
          break;
      }
  }

}

void implementFindLibrarianChoice(int option){
  switch (option) {
      case 1: {
          cout << "enter the name of the librarian you want to find" << endl;
          Custom_String_Class name;
          cin.ignore();
          cin >> name;
          Librarian librarian = Librarian::findLibrarianByName(name);
          if (!(librarian.getName() == Librarian().getName()))
              librarian.display();
          break;
      }
      case 2: {
          cout << "enter the ID of the librarian you want to find" << endl;
          int id;
          cin >> id;
          Librarian librarian = Librarian::findLibrarianByID(id);
          if (!(librarian.getName() == Librarian().getName()))
              librarian.display();
          break;
      }
      default: {
          break;
      }
  }

}
