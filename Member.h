//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_MEMBER_H
#define PROJECT_MEMBER_H

#include <iostream>
#include "Custom_String_Class.h"
#include <vector>
using namespace std;

class Member {
private:
    Custom_String_Class Name;
    int ID;
    vector<Custom_String_Class> Checked_Books;
    int Fines;
public:
    Member();
    Member(Custom_String_Class N,int I);
    vector<Custom_String_Class> SearchByTitle(Custom_String_Class Title);
};


#endif //PROJECT_MEMBER_H
