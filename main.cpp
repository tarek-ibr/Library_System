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

    cout<<"\t\t\t\tNos far5a men ebn el sham library" <<endl;

    int id;
    cout<<"Enter your ID: ";
    cin>>id;



    Custom_String_Class type = login(id);

    if(type=="member"){
        Member member = Librarian::findMemberByID(id);

        cout<<endl <<"\t\t\t\tWelcome " <<member.getName() <<" to our library " <<endl;

        while(true){
            diplayMenuMember();

            int memberOption;
            cin>>memberOption;

            if(memberOption==7)
                break;

            implementMemberChoice(member, memberOption);

        }
    }
    else if(type=="librarian"){
        Librarian librarian = Librarian::findLibrarianByID(id);

        cout<<endl <<"\t\t\t\tWelcome back " <<librarian.getName() <<endl;

        while(true){
            displayMenuLibrarian();

            int librarianOption;
            cin >> librarianOption;

            if (librarianOption == 15) {
                break;
            }

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
