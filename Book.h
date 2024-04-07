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
    Custom_String_Class duedate;
    int Publication_Year;
    bool Available;
    static vector<Book> Book_List;

    Book();
    Book(const Custom_String_Class& , const Custom_String_Class& , const Custom_String_Class& ,const Custom_String_Class&,const Custom_String_Class&, int ,bool);
    static bool loadlibrary();
    void display() const;
    static void displaylist();
    Custom_String_Class getISBN();


};


#endif //PROJECT_BOOK_H
