//
// Created by tarek on 4/5/2024.
//

#include "Book.h"
#include "json.h"
#include <fstream>
vector<Book>Book::Book_List = {};
using json = nlohmann::json;
Book::Book() {}
Book::Book(const Custom_String_Class& tit  , const Custom_String_Class& Auth , const Custom_String_Class& ISB ,const Custom_String_Class& Gen, int Pub_yr,bool Avail=true , int Quant=1 )
        : Title(tit), Author(Auth), ISBN(ISB),Genre(Gen),Publication_Year(Pub_yr),Available(Avail),Quantity(Quant) {}
void Book::display() const {
    cout << "Title: " << Title << endl;
    cout << "Author: " << Author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Publication Year: " << Publication_Year << endl;
    cout << "Genre: " << Genre << endl;
    cout << "Availability: " << (Available ? "Available" : "Checked out") << endl;

}
void Book::displaylist() {
    for (const auto &it: (Book::Book_List)) {
        cout << "Title: " << it.Title << endl;
        cout << "Author: " << it.Author << endl;
        cout << "ISBN: " << it.ISBN << endl;
        cout << "Publication Year: " << it.Publication_Year << endl;
        cout << "Genre: " << it.Genre << endl;
        cout << "Availability: " << (it.Available ? "Available" : "Checked out") << endl;
        cout << "Quantity: " << it.Quantity<< endl;
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

    for (const auto& book_json : j) {
        Book bk;

        bk.Title = (book_json["title"].get<string>());
        bk.Author = book_json["author"].get<string>();
        bk.ISBN = book_json["isbn"].get<string>();
        bk.Genre = book_json["genre"].get<string>();
        bk.Publication_Year = book_json["publication_year"];
        bk.Available=book_json["available"].get<bool>();
        bk.Quantity=book_json["quantity"];
        Book_List.push_back(bk);
    }
    file.close();
    return true;
}
bool Book::savelibrary() {
    std::ofstream file("books.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << endl;
        return false;
    }
    json OUTPUT;
    for(auto book : Book_List)
    {
        json bookJson;
        bookJson["title"] = book.Title.str;
        bookJson["author"] = book.Author.str;
        bookJson["publication_year"] = book.Publication_Year;
        bookJson["isbn"] = book.ISBN.str;
        bookJson["genre"] = book.Genre.str;
        bookJson["available"] = book.Available;
        bookJson["quantity"] = book.Quantity;
        OUTPUT.push_back(bookJson);
    }
    file<<setw(4)<<OUTPUT<<endl;
    file.close();
    return true;

}
Custom_String_Class Book::getISBN() {
    return ISBN;
}
