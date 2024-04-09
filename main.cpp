#include <iostream>
#include <fstream>
#include <vector>
#include "json.h"
#include "Book.h"
#include "Member.h"
#include "Librarian.h"
#include "Loan.h"
#include "Custom_String_Class.h"

using namespace std;
using json = nlohmann::json;


int main() {

Book::loadlibrary();
Librarian L1;
L1.addBook();
Book::displaylist();
Book::savelibrary();

    return 0;
}
