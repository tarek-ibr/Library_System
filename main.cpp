#include <iostream>
#include <fstream>
#include <vector>
#include "json.h"
#include "Book.h"
#include "User.h"
#include "Loan.h"
#include "Custom_String_Class.h"
//Ammar
using namespace std;
using json = nlohmann::json;

int main() {

    Book::loadlibrary();
    Loan::loadLoans();
    Librarian::loadMembers();
    Librarian::loadLibrarian();

    Member m1= Member::findByID(66666);
    Librarian l1= Librarian::findByID(11111);
    Book b1= Book::findByISBN("978-0-7475-3269-6");
    b1.display();
    Loan ln(66666, "978-0-7475-3269-6");
    Book::displaylist();
    Loan::displaylist();
    Member::displayAllMembers();

    m1.requestBorrow(b1);
    l1.displayRequests();
    l1.approveBorrowRequest(ln);
    l1.displayRequests();
    cout<<"\n**********************************\n";
    m1.displayloaned();


    Librarian::saveMembers();
    Loan::saveLoans();
    Librarian::saveLibrarian();
    Book::savelibrary();



    return 0;
}
