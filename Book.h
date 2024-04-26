// Created by tarek on 4/5/2024.

#ifndef PROJECT_BOOK_H
#define PROJECT_BOOK_H

#include <iostream>
#include <vector>
#include "Custom_String_Class.h"
#include "json.h"
#include <fstream>

using namespace std;
using json = nlohmann::json;

// Book class definition
class Book {
private:
    // Private member variables for book details
    Custom_String_Class Title;
    Custom_String_Class Author;
    Custom_String_Class ISBN;
    Custom_String_Class Genre;
    unsigned int Quantity;
    unsigned int Publication_Year;
    bool Available;

    // Static vector to hold the list of books in the library
    static vector<Book> Book_List;

public:
    // Default constructor
    Book();

    // Parameterized constructor
    Book(const Custom_String_Class& , const Custom_String_Class& , const Custom_String_Class& ,const Custom_String_Class&, int , int);

    // Getters for book attributes
    Custom_String_Class& getTitle() ;
    Custom_String_Class& getAuthor();
    Custom_String_Class& getISBN();
    Custom_String_Class& getGenre();
    unsigned int& getQuantity();
    unsigned int& getPubYear();

    // Getter for the book list
    static vector<Book>& getBookList();

    // Setters for book attributes
    void setTitle(const Custom_String_Class&);
    void setAuthor(const Custom_String_Class&);
    void setISBN(const Custom_String_Class&);
    void setGenre(const Custom_String_Class&);
    void setQuantity(unsigned int);
    void setPubYear(unsigned int);
    void setAvailability(bool);

    // Static functions to find books by name, ISBN, or author
    static Book findByName(Custom_String_Class);
    static Book findByISBN(Custom_String_Class);
    static Book findByAuthor(Custom_String_Class);

    // Static functions to load and save the library
    static bool loadlibrary();
    static bool savelibrary();

    // Function to check if a book is available
    bool checkAvailability() const;

    // Static function to display the list of all books
    static void displaylist();

    // Function to display a book's details
    void displayBook() const;
};

#endif //PROJECT_BOOK_H
