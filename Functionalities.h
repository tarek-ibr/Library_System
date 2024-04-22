//
// Created by tarek on 4/22/2024.
//

#ifndef PROJECT_FUNCTIONALITIES_H
#define PROJECT_FUNCTIONALITIES_H

#include "Custom_String_Class.h"
#include "User.h"

Custom_String_Class login(int);

void diplayMenuMember();
void displayMenuLibrarian();

void implementMemberChoice(Member&, int);
void implementLibrarianChoice(Librarian&, int);


#endif //PROJECT_FUNCTIONALITIES_H
