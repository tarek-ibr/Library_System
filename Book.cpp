//
// Created by tarek on 4/5/2024.
//

#include "Book.h"

Book::Book() : Publication_Year(0) {}
Book::Book(const std::string& t, const std::string& a, const std::string& i, int y)
        : Title(t), Author(a), ISBN(i), Publication_Year(y) {}