#include <iostream>
#include <fstream>
#include <vector>
#include "json.h"
#include "Book.h"
#include "Member.h"
#include "Librarian.h"
#include "Loan.h"
#include "Custom_String_Class.h"
//Ammar
using namespace std;
using json = nlohmann::json;

int main() {

    Member::loadMembers();
    Loan::loadLoans();
    Librarian::loadLibrarian();
    Book::loadlibrary();

    Member m1("tamer", 77777, "Student");
    Librarian l1("elgayar", 88888);

    Book b1= Book::findByName("1984");

    m1.requestBorrow(b1);
    l1.displayRequests();

    //vector<Loan>& ln= Member::getCheckedOutBooks();
    //l1.approveBorrowRequest();



    Member::saveMembers();
    Loan::saveLoans();
    Librarian::saveLibrarian();
    Book::loadlibrary();



    return 0;
}
