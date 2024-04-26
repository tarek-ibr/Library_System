// Created by tarek on 4/22/2024.

#ifndef PROJECT_FUNCTIONALITIES_H
#define PROJECT_FUNCTIONALITIES_H

#include "Custom_String_Class.h"
#include "User.h"
#include <string>

// Function to load all data from files
void loadFiles();

// Function to save all data to files
void saveFiles();

// Function to login a user
Custom_String_Class login(int);

// Function to load all data from files
void LoadFiles();

// Function to save all data to files
void SaveFiles();

// Function to display the menu for a member
void diplayMenuMember();

// Function to display the menu for a librarian
void displayMenuLibrarian();

// Function to display the menu for finding a book
void displayMenuFindBook();

// Function to display the menu for finding a member
void displayMenuFindMember();

// Function to display the menu for finding a librarian
void displayMenuFindlibrarian();

// Function to implement the choice of a member
void implementMemberChoice(Member&, int);

// Function to implement the choice of a librarian
void implementLibrarianChoice(Librarian&, int);

// Function to implement the choice of finding a book
void implementFindBookChoice(int);

// Function to implement the choice of finding a member
void implementFindMemberChoice(int);

// Function to implement the choice of finding a librarian
void implementFindLibrarianChoice(int);

#endif //PROJECT_FUNCTIONALITIES_H
