//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_BOOK_H
#define PROJECT_BOOK_H
#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    string Title;
    string Author;
    string ISBN;
    string Genre;
    int Publication_Year;
    bool Available;


    // Default constructor
    Book();
    Book(const std::string& t, const std::string& a, const std::string& i, int y);


};


#endif //PROJECT_BOOK_H
