//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_BOOK_H
#define PROJECT_BOOK_H
#include <iostream>

using namespace std;

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;
    int publication_year;

    Book();
    Book(const std::string&, const std::string&, const std::string&, int);

    // Default constructor

};


#endif //PROJECT_BOOK_H
