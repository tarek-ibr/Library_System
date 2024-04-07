//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_BOOK_H
#define PROJECT_BOOK_H
#include <iostream>
#include <vector>
#include "Custom_String_Class.h"

using namespace std;

class Book {
public:
    Custom_String_Class Title;
    Custom_String_Class Author;
    Custom_String_Class ISBN;
    Custom_String_Class Genre;
    int Publication_Year;
    bool Available;



    // Default constructor
    Book();
    Book(const Custom_String_Class& t, const Custom_String_Class& a, const Custom_String_Class& i, int y);


};


#endif //PROJECT_BOOK_H
