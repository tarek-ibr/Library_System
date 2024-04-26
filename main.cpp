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

    
    cout<<"\t\t\t\tNos far5a men ebn el sham library" <<endl;
    
    int id;
Login:
    LoadFiles();
    cout<<"Enter your ID: ";
    cin>>id;


    Custom_String_Class type = login(id);

    if(type=="member"){
        Member member = Librarian::findMemberByID(id);

        cout<<endl <<"\t\t\t\tWelcome " <<member.getName() <<" to our library " <<endl;

        while(true){
            diplayMenuMember();
      
            int memberOption;
            Member_Choose_Option:
            cin>>memberOption;

            if(memberOption==7) {
                SaveFiles();
                goto Login;
            }
            else if(memberOption==8)
                break;
            else if (memberOption <1 || memberOption > 8){
                cout<<"Invalid choice" <<endl;
                goto Member_Choose_Option;
            }
            system("cls");
            implementMemberChoice(member, memberOption);
            system("pause");
            system("cls");


        }
    }
    else if(type=="librarian"){
        Librarian librarian = Librarian::findLibrarianByID(id);

        cout<<endl <<"\t\t\t\tWelcome back " <<librarian.getName() <<endl;

        while(true){
            displayMenuLibrarian();

            int librarianOption;
            Librarian_Choose_Option:
            cin >> librarianOption;

            if (librarianOption == 15) {
                SaveFiles();
                goto Login;
            }
            else if (librarianOption == 16) {
                break;
            }
             else if (librarianOption <1 || librarianOption > 16){
                cout<<"Invalid choice" <<endl;
                goto Librarian_Choose_Option;
            }
            system("cls");
            implementLibrarianChoice(librarian, librarianOption);
            system("pause");
            system("cls");

        }
    }
    else if(type=="not found"){
        cout<<"You are not registered in our system, Please check your ID again!!"<<endl<<endl;
        goto Login;
    }

    SaveFiles();

    system("pause");

    return 0;
}
