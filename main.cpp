#ifdef _WIN32
#  ifdef USE_ASIO
//     Set the proper SDK version before including boost/Asio
#      include <SDKDDKVer.h>
//     Note boost/ASIO includes Windows.h.
#      include <boost/asio.hpp>
#   else //  USE_ASIO
#      include <Windows.h>
#   endif //  USE_ASIO
#else // _WIN32
#  ifdef USE_ASIO
#     include <boost/asio.hpp>
#  endif // USE_ASIO
#endif //_WIN32

#include <iostream>
#include <fstream>
#include <vector>
#include "json.h"
#include "Book.h"
#include "User.h"
#include "Loan.h"
#include "Custom_String_Class.h"
#include "Functionalities.h"
#include <thread>


using namespace std;
using json = nlohmann::json;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void displayLibraryName();


int main() {


    cout << "\e[8;200;150t";



    Login:

    displayLibraryName();

    LoadFiles();

    SetConsoleTextAttribute(hConsole, 8);

    cout<<"Enter your ID: ";
    int id;
    cin>>id;

    system("cls");

    Custom_String_Class type = login(id);

    SetConsoleTextAttribute(hConsole, 3);
    if(type=="member"){
        Member member = Librarian::findMemberByID(id);




        while(true){

            displayLibraryName();
            cout<<endl <<"\t\t\t\t\t\t\tWelcome " <<member.getName() <<" to our library " <<endl;

            diplayMenuMember();
      
            int memberOption;
            Member_Choose_Option:
            cin>>memberOption;

            if(memberOption==7) {
                SaveFiles();
                system("cls");
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



        while(true){

            displayLibraryName();
            cout<<endl <<"\t\t\t\t\t\t\tWelcome back " <<librarian.getName() <<endl;

            displayMenuLibrarian();

            int librarianOption;
            Librarian_Choose_Option:
            cin >> librarianOption;

            if (librarianOption == 15) {
                SaveFiles();
                system("cls");
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

void displayLibraryName(){
    SetConsoleTextAttribute(hConsole, 6);
    cout<<"\t\t\t    ________         ___   _____ ____  ____    ___    ___       __    ________  ____  ___    ______  __\n"
          "\t\t\t   / ____/ /        /   | / ___// __ \\/ __ \\  /   |  /   |     / /   /  _/ __ )/ __ \\/   |  / __ \\ \\/ /\n"
          "\t\t\t  / __/ / /  ______/ /| | \\__ \\/ / / / / / / / /| | / /| |    / /    / // __  / /_/ / /| | / /_/ /\\  / \n"
          "\t\t\t / /___/ /__/_____/ ___ |___/ / /_/ / /_/ / / ___ |/ ___ |   / /____/ // /_/ / _, _/ ___ |/ _, _/ / /  \n"
          "\t\t\t/_____/_____/    /_/  |_/____/_____/\\___\\_\\/_/  |_/_/  |_|  /_____/___/_____/_/ |_/_/  |_/_/ |_| /_/   \n"
          "\t\t\t                                                                                                       ";
    cout<<"\n\n\n";
}

void diplayMenuMember(){
    SetConsoleTextAttribute(hConsole, 3);
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
    SetConsoleTextAttribute(hConsole, 3);
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
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\nSelect an option:\n";
    cout << "1. Find the book by ISBN\n";
    cout << "2. Find the book by name\n";
    cout << "3. Find the book by author\n";
}

void displayMenuFindMember(){
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\nSelect an option:\n";
    cout << "1. Find the member by name\n";
    cout << "2. Find the member by ID\n";
}

void displayMenuFindlibrarian(){
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\nSelect an option:\n";
    cout << "1. Find the librarian by name\n";
    cout << "2. Find the librarian by ID\n";
}

void playSound(const char* wavPath) {

    PlaySoundA(wavPath, NULL, SND_FILENAME);
}

const char* wavPath = "music.wav";

std::thread soundThread(playSound, wavPath);