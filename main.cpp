#include <iostream>
#include <fstream>
#include <vector>
#include "json.h"
#include "Book.h"
#include "User.h"
#include "Loan.h"
#include "Custom_String_Class.h"
#include "Functionalities.h"

using namespace std;
using json = nlohmann::json;

int main() {
    Book::loadlibrary();
    Loan::loadLoans();
    Librarian::loadMembers();
    Librarian::loadLibrarian();

    int id;
    cout<<"Enter your ID: ";
    cin>>id;

    Custom_String_Class type = login(id);

    if(type=="member"){
        Member member = Member::findByID(id);
        while(true){
            diplayMenuMember();

            int memberOption;
            cin>>memberOption;

            if(memberOption==6)
                break;
            system("cls");
            implementMemberChoice(member, memberOption);

        }
    }
    else if(type=="librarian"){
        Librarian librarian = Librarian::findByID(id);

        while(true){
            displayMenuLibrarian();

            int librarianOption;
            cin >> librarianOption;

            if (librarianOption == 11) {
                break;
            }
            system("cls");
            implementLibrarianChoice(librarian, librarianOption);

        }
    }
    else if(type=="not found"){
        cout<<"You are not registered in our system, Please check your ID again!!"<<endl;
    }

    Librarian::saveMembers();
    Loan::saveLoans();
    Librarian::saveLibrarian();
    Book::savelibrary();

    system("pause");

    return 0;
}
