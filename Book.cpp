//
// Created by tarek on 4/5/2024.
//

#include "Book.h"
#include "json.h"
#include <fstream>
using json = nlohmann::json;
Book::Book() : Publication_Year(0) {}
Book::Book(const Custom_String_Class& tit  , const Custom_String_Class& Auth = "", const Custom_String_Class& ISB = "", int Pub_yr = 0,bool Avail = false)
        : Title(tit), Author(Auth), ISBN(ISB), Publication_Year(Pub_yr),Available(Avail) {}
void Book::display() const {
    cout << "Title: " << Title << endl;
    cout << "Author: " << Author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Publication Year: " << Publication_Year << endl;
    cout << "Genre: " << Genre << endl;
    cout << "Availability: " << (Available ? "Available" : "Checked out") << endl;
    if (!Available) {
        cout << "Due Date: " << duedate << endl;
    }
}
bool Book::loadlibrary() {
    std::ifstream file("books.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    json j;
    file >> j;

    std::vector<Book> books;
    for (const auto& book_json : j["books"]) {


       Book bk(book_json["title"],book_json["author"],book_json["isbn"],book_json["publication_year"])


    }
}
Custom_String_Class Book::getISBN() {
    return ISBN;
}
