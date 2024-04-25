//
// Created by tarek on 4/22/2024.
//

#ifndef PROJECT_FUNCTIONALITIES_H
#define PROJECT_FUNCTIONALITIES_H

#include "Custom_String_Class.h"
#include "User.h"

void loadFiles();
void saveFiles();

//Custom_String_Class *executeGUIOption(Custom_String_Class *options, size_t num_options);

Custom_String_Class login(int);

void diplayMenuMember();
void displayMenuLibrarian();
void displayMenuFindBook();
void displayMenuFindMember();
void displayMenuFindlibrarian();

void implementMemberChoice(Member&, int);
void implementLibrarianChoice(Librarian&, int);
void implementFindBookChoice(int);           //all finds has logical errors does not cin
void implementFindMemberChoice(int);
void implementFindLibrarianChoice(int);


#endif //PROJECT_FUNCTIONALITIES_H
