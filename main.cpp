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

    Member m1("Seif", 1234, "student");
    Librarian l1("Ammar", 5678);

    Book b1= Book::findByName("1984");

    m1.requestBorrow(b1);



    Member::saveMembers();
    Loan::saveLoans();
    Librarian::saveLibrarian();
    Book::loadlibrary();



    return 0;
}
