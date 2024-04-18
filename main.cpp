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
 Book::loadlibrary();
 Custom_String_Class s;
 cin>>s;
 Book::findByName(s).display();
   /* Book::loadlibrary();
    Librarian L1;
    L1.addBook();
    Book::displaylist();
    Book::savelibrary();

    Date d1(Custom_String_Class("05/04/2024"));
    Loan l1(22123, Custom_String_Class("23424"), d1);
    l1.displayDetails();
    cout<<l1.calculateFines()<<endl;
    Date d2=Date::getCrrentDate();
    cout<<d2.getDate()<<endl;

    Member::loadMembers();
    Member::displayAllMembers();*/


    return 0;
}
