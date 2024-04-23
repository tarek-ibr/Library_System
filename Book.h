//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_BOOK_H
#define PROJECT_BOOK_H
#include <iostream>
#include <vector>
#include "Custom_String_Class.h"
#include "json.h"
#include <fstream>

using namespace std;
using json = nlohmann::json;
class Book {
private:
    Custom_String_Class Title;
    Custom_String_Class Author;
    Custom_String_Class ISBN;
    Custom_String_Class Genre;
    unsigned int Quantity;
    unsigned int Publication_Year;
    bool Available;
    static vector<Book> Book_List;
public:

    Book();
    Book(const Custom_String_Class& , const Custom_String_Class& , const Custom_String_Class& ,const Custom_String_Class&, int , int);

    Custom_String_Class& getTitle() ;
    Custom_String_Class& getAuthor();
    Custom_String_Class& getISBN();
    Custom_String_Class& getGenre();
    unsigned int& getQuantity();
    unsigned int& getPubYear();
    static vector<Book>& getBookList();

    void setTitle(const Custom_String_Class&);
    void setAuthor(const Custom_String_Class&);
    void setISBN(const Custom_String_Class&);
    void setGenre(const Custom_String_Class&);
    void setQuantity(unsigned int);
    void setPubYear(unsigned int);
    void setAvailability(bool);

    static Book findByName(Custom_String_Class);
    static Book findByISBN(Custom_String_Class);
    static Book findByAuthor(Custom_String_Class);

    static bool loadlibrary();
    static bool savelibrary();

    bool checkAvailability() const;
    static void displaylist();
    void displayBook() const;
};


#endif //PROJECT_BOOK_H
