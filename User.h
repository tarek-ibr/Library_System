#ifndef PROJECT_LIBRARIAN_H
#define PROJECT_LIBRARIAN_H

#include <iostream>
#include "Custom_String_Class.h"
#include <vector>
#include "Book.h"
#include "Loan.h"
#include <fstream>
#include "json.h"

// Use nlohmann's json library
using json = nlohmann::json;
using namespace std;

// Member class definition
class Member {
private:
    // Private member variables
    vector<Loan> checkedOutBooks; // List of checked out books
    int Fines; // Fines owed by the member
protected:
    // Protected member variables
    Custom_String_Class Name; // Name of the member
    int ID; // ID of the member
    Custom_String_Class Type; // Type of the member
    static vector<Member> members; // Static list of all members
public:
    // Public member functions

    // Constructors
    Member(); // Default constructor
    Member(const Custom_String_Class& ,int ,const Custom_String_Class& ); // Constructor with name, ID, and type

    // Getters
    Custom_String_Class getName() const; // Getter for name
    int getID() const; // Getter for ID
    Custom_String_Class getType() const; // Getter for type
    int getFines() const; // Getter for fines
    static vector<Member>& getMembers(); // Getter for list of members
    vector<Loan>& getCheckedOutBooks(); // Getter for checked out books

    // Setters
    void setName(const Custom_String_Class&); // Setter for name
    void setID(int); // Setter for ID
    void setType(const Custom_String_Class&); // Setter for type
    void setFines(int f); // Setter for fines

    // Other member functions
    int calculateTotalFines (); // Function to calculate total fines
    void updateTotalFines (); // Function to update total fines
    void display(); // Function to display member details
    void displayloaned() const; // Function to display loaned books
    void requestBorrow(Book&); // Function to request to borrow a book
    void returnBook(Book) ; // Function to return a book
};

// Librarian class definition
class Librarian : public Member{
private:
    // Private member variables
    static std::vector<Loan> borrowRequests; // Static list of borrow requests
    static std::vector<Librarian> librarians; // Static list of librarians
public:
    // Public member functions

    // Constructors
    Librarian(); // Default constructor
    Librarian(const Custom_String_Class& name, int ID); // Constructor with name and ID

    // Getters
    static vector<Librarian>& getLibrarians(); // Getter for list of librarians
    static vector<Loan>& getBorrowRequests(); // Getter for list of borrow requests

    // Other member functions
    void addBook(); // Function to add a book
    void removeBook(const Custom_String_Class& ISBN); // Function to remove a book
    void editBook( Book& book); // Function to edit a book
    static void addBorrowRequest(Loan&); // Function to add a borrow request
    bool borrowBook(Book, Member); // Function to borrow a book
    void approveBorrowRequest(Loan); // Function to approve a borrow request
    static void returnBook(Member& member, Book& book); // Function to return a book
    void registerNewMember(); // Function to register a new member
    void removeMember(int); // Function to remove a member
    void displayAllMembers(); // Function to display all members
    void display(); // Function to display librarian details
    static bool loadLibrarian(); // Function to load librarians from a file
    static bool saveLibrarian(); // Function to save librarians to a file
    static Librarian findLibrarianByName(Custom_String_Class); // Function to find a librarian by name
    static Librarian findLibrarianByID(int); // Function to find a librarian by ID
    static Member findMemberByName(Custom_String_Class); // Function to find a member by name
    static Member findMemberByID(int); // Function to find a member by ID
    static bool loadMembers(); // Function to load members from a file
    static bool saveMembers(); // Function to save members to a file
    void displayRequests(); // Function to display requests
};

#endif //PROJECT_LIBRARIAN_H
