//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_MEMBER_H
#define PROJECT_MEMBER_H

#include <iostream>
#include "Custom_String_Class.h"

using namespace std;

class Member {
    Custom_String_Class name;
    int id;
    bool type;
    Custom_String_Class Checked_books[50];
    int fines;
};


#endif //PROJECT_MEMBER_H
