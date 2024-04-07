//
// Created by tarek on 4/5/2024.
//

#include "Book.h"

Book::Book() : publication_year(0) {}
Book::Book(const std::string& t, const std::string& a, const std::string& i, int y)
        : title(t), author(a), isbn(i), publication_year(y) {}