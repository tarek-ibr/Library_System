//
// Created by tarek on 4/5/2024.
//

#include "Book.h"

Book::Book() : Publication_Year(0) {}
Book::Book(const Custom_String_Class& t, const Custom_String_Class& a, const Custom_String_Class& i, int y)
        : Title(t), Author(a), ISBN(i), Publication_Year(y) {}