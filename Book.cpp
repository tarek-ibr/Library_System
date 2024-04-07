//
// Created by tarek on 4/5/2024.
//

#include "Book.h"
#include "json.h"
#include <fstream>
vector<Book>Book::Book_List = {};
using json = nlohmann::json;
Book::Book() {}
Book::Book(const Custom_String_Class& tit  , const Custom_String_Class& Auth , const Custom_String_Class& ISB ,const Custom_String_Class& Gen,const Custom_String_Class& Due, int Pub_yr,bool Avail )
        : Title(tit), Author(Auth), ISBN(ISB),Genre(Gen),duedate(Due),Publication_Year(Pub_yr),Available(Avail) {}
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
void Book::displaylist() {
    for (const auto &it: (Book::Book_List)) {
        cout << "Title: " << it.Title << endl;
        cout << "Author: " << it.Author << endl;
        cout << "ISBN: " << it.ISBN << endl;
        cout << "Publication Year: " << it.Publication_Year << endl;
        cout << "Genre: " << it.Genre << endl;
        cout << "Availability: " << (it.Available ? "Available" : "Checked out") << endl;
        if (!it.Available) {
            cout << "Due Date: " << it.duedate << endl;
        }
    }
}
bool Book::loadlibrary() {
    std::ifstream file("books.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return false;
    }

    json j;
    file >> j;

    for (const auto& book_json : j["books"]) {
        Book bk;

        bk.Title = (book_json["title"].get<string>());
        cout<< (book_json["title"].get<string>());
        bk.Author = book_json["author"].get<string>();
        bk.ISBN = book_json["isbn"].get<string>();
        bk.Publication_Year = book_json["publication_year"];
        bk.Available=false;
        Book_List.push_back(bk);
    }
    return true;
}
Custom_String_Class Book::getISBN() {
    return ISBN;
}
