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


    Loan::loadLoans();
    Member::loadMembers();
    Librarian::loadLibrarian();
    Book::loadlibrary();

    Book b1= Book::findByName("1984");
    Member m1= Member::findByID(66666);
    Librarian l1= Librarian::findByID(11111);

    m1.displayloaned();

    m1.requestBorrow(b1);
    l1.displayRequests();

    Loan ln(77777, "978-0-451-52493-5");
    l1.approveBorrowRequest(ln);



    Member::saveMembers();
    Loan::saveLoans();
    Librarian::saveLibrarian();
    Book::loadlibrary();



    return 0;
}
