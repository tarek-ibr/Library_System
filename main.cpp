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

// Include necessary libraries and files
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

// Get the standard output handle
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Function declarations
void displayLibraryName();
void playSound(const char* wavPath);

// Main function
int main() {
    // Path to the sound file
    const char* wavPath = "music.wav";

    // Start a new thread to play the sound
    std::thread soundThread(playSound, wavPath);

    // Set the console size
    cout << "\e[8;200;150t";

    // Login label for goto statement
    Login:

    // Display the library name
    displayLibraryName();

    // Load the files
    LoadFiles();

    // Set the console text attribute
    SetConsoleTextAttribute(hConsole, 8);

    // Prompt the user to enter their ID
    cout<<"Enter your ID: ";
    int id;
    cin>>id;

    // Clear the console
    system("cls");

    // Login with the entered ID
    Custom_String_Class type = login(id);

    // Set the console text attribute
    SetConsoleTextAttribute(hConsole, 3);

    // If the user is a member
    if(type=="member"){
        // Find the member by ID
        Member member = Librarian::findMemberByID(id);

        // Infinite loop for the member menu
        while(true){

            // Display the library name
            displayLibraryName();

            // Welcome the member
            cout<<endl <<"\t\t\t\t\t\t\tWelcome " <<member.getName() <<" to our library " <<endl;

            // Display the member menu
            diplayMenuMember();

            // Prompt the user to choose an option
            int memberOption;
            Member_Choose_Option:
            cin>>memberOption;

            // If the user chooses to logout
            if(memberOption==7) {
                // Save the files
                SaveFiles();

                // Clear the console
                system("cls");

                // Go to the login label
                goto Login;
            }
            // If the user chooses to exit
            else if(memberOption==8)
                break;
            // If the user enters an invalid choice
            else if (memberOption <1 || memberOption > 8){
                cout<<"Invalid choice" <<endl;
                goto Member_Choose_Option;
            }

            // Clear the console
            system("cls");

            // Implement the chosen option
            implementMemberChoice(member, memberOption);

            // Pause the console
            system("pause");

            // Clear the console
            system("cls");
        }
    }
    // If the user is a librarian
    else if(type=="librarian"){
        // Find the librarian by ID
        Librarian librarian = Librarian::findLibrarianByID(id);

        // Infinite loop for the librarian menu
        while(true){

            // Display the library name
            displayLibraryName();

            // Welcome the librarian
            cout<<endl <<"\t\t\t\t\t\t\tWelcome back " <<librarian.getName() <<endl;

            // Display the librarian menu
            displayMenuLibrarian();

            // Prompt the user to choose an option
            int librarianOption;
            Librarian_Choose_Option:
            cin >> librarianOption;

            // If the user chooses to logout
            if (librarianOption == 15) {
                // Save the files
                SaveFiles();

                // Clear the console
                system("cls");

                // Go to the login label
                goto Login;
            }
            // If the user chooses to exit
            else if (librarianOption == 16) {
                break;
            }
            // If the user enters an invalid choice
            else if (librarianOption <1 || librarianOption > 16){
                cout<<"Invalid choice" <<endl;
                goto Librarian_Choose_Option;
            }

            // Clear the console
            system("cls");

            // Implement the chosen option
            implementLibrarianChoice(librarian, librarianOption);

            // Pause the console
            system("pause");

            // Clear the console
            system("cls");
        }
    }
    // If the user is not found
    else if(type=="not found"){
        cout<<"You are not registered in our system, Please check your ID again!!"<<endl<<endl;
        goto Login;
    }

    // Save the files
    SaveFiles();

    // Pause the console
    system("pause");

    // Join the sound thread
    soundThread.join();

    return 0;
}

// Function to display the library name
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

// Function to display the member menu
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

// Function to display the librarian menu
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

// Function to display the find book menu
void displayMenuFindBook(){
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\nSelect an option:\n";
    cout << "1. Find the book by ISBN\n";
    cout << "2. Find the book by name\n";
    cout << "3. Find the book by author\n";
}

// Function to display the find member menu
void displayMenuFindMember(){
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\nSelect an option:\n";
    cout << "1. Find the member by name\n";
    cout << "2. Find the member by ID\n";
}

// Function to display the find librarian menu
void displayMenuFindlibrarian(){
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\nSelect an option:\n";
    cout << "1. Find the librarian by name\n";
    cout << "2. Find the librarian by ID\n";
}

// Function to play a sound
void playSound(const char* wavPath) {

    PlaySoundA(wavPath, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
