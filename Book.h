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
    unsigned int Quantity;
    int Publication_Year;
    bool Available;
    static vector<Book> Book_List;
    Book();
    Book(const Custom_String_Class& , const Custom_String_Class& , const Custom_String_Class& ,const Custom_String_Class&, int , int);
    static bool loadlibrary();
    static bool savelibrary();
    static void displaylist();
    void display() const;
    Custom_String_Class getISBN();
    bool checkAvailability();
};


#endif //PROJECT_BOOK_H
