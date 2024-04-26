// Created by tarek on 4/5/2024.

#include "Book.h"

// Static vector to hold the list of books in the library
vector<Book> Book::Book_List = {};

// Default constructor initializing an empty book
Book::Book() : Title(""), Author(""), ISBN(""), Genre(""), Publication_Year(0), Quantity(0), Available(false) {}

// Parameterized constructor to create a book with given details
Book::Book(const Custom_String_Class& tit, const Custom_String_Class& Auth, const Custom_String_Class& ISB, const Custom_String_Class& Gen, int Pub_yr, int Quant)
        : Title(tit), Author(Auth), ISBN(ISB), Genre(Gen), Publication_Year(Pub_yr), Quantity(Quant) {
    Available = Quantity > 0; // Set availability based on quantity
}

// Function to display book details
void Book::displayBook() const {
    cout << "--------------------\n";
    // Output book details
    cout << "Title: " << Title << endl;
    cout << "Author: " << Author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Publication Year: " << Publication_Year << endl;
    cout << "Genre: " << Genre << endl;
    cout << "Availability: " << (Quantity > 0 ? "Available" : "Checked out") << endl;
    cout << "--------------------\n";
}

// Function to display the list of all books
void Book::displaylist() {
    int i = 1;
    cout << "--------------------\n";
    // Iterate through the list of books and display each one
    for (const auto& it : Book::Book_List) {
        cout<<i++<<" ";
        cout << "Title: " << it.Title << endl;
        cout << "Author: " << it.Author << endl;
        cout << "ISBN: " << it.ISBN << endl;
        cout << "Publication Year: " << it.Publication_Year << endl;
        cout << "Genre: " << it.Genre << endl;
        cout << "Availability: " << ((it.Quantity) > 0 ? "Available" : "Checked out") << endl;
        cout << "Quantity: " << it.Quantity << endl;
        cout<< "--------------------\n";
    }
}

// Function to load the library from a JSON file
bool Book::loadlibrary() {
    Book_List.clear(); // Clear the existing book list
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
        bk.Quantity = book_json["quantity"];
        Book_List.push_back(bk);
    }
    file.close();
    return true;
}

// Function to save the library to a JSON file
bool Book::savelibrary() {
    std::ofstream file("books.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << endl;
        return false;
    }

    json OUTPUT;
    for (const auto& book : Book_List) {
        json bookJson;
        bookJson["title"] = book.Title.getSTR();
        bookJson["author"] = book.Author.getSTR();
        bookJson["publication_year"] = book.Publication_Year;
        bookJson["isbn"] = book.ISBN.getSTR();
        bookJson["genre"] = book.Genre.getSTR();
        bookJson["quantity"] = book.Quantity;
        OUTPUT.push_back(bookJson);
    }
    file << setw(4) << OUTPUT << endl;
    file.close();
    return true;
}

// Getters and setters for book attributes
Custom_String_Class& Book::getISBN() { return ISBN; }
Custom_String_Class& Book::getTitle() { return Title; }
Custom_String_Class& Book::getAuthor() { return Author; }
Custom_String_Class& Book::getGenre() { return Genre; }
unsigned int& Book::getPubYear() { return Publication_Year; }
unsigned int& Book::getQuantity() { return Quantity; }
vector<Book>& Book::getBookList() { return Book_List; }

void Book::setAuthor(const Custom_String_Class& AuthorName) { Author = AuthorName; }
void Book::setTitle(const Custom_String_Class& newTitle) { Title = newTitle; }
void Book::setGenre(const Custom_String_Class& newGenre) { Author = newGenre; }
void Book::setISBN(const Custom_String_Class& newISBN) { ISBN = newISBN; }
void Book::setPubYear(unsigned int newPubYear) { Publication_Year = newPubYear; }
void Book::setQuantity(unsigned int newQuantity) { Quantity = newQuantity; }

// Function to check if a book is available
bool Book::checkAvailability() const { return (Quantity > 0); }

// Function to set the availability of a book
void Book::setAvailability(bool X) { Available = X; }

// Function to find a book by author
Book Book::findByAuthor(Custom_String_Class name) {
    vector<Book> results;
    int found = 0;
    cout << "found :" << endl;
    for (auto it : Book_List) {
        if (it.getAuthor().find(name)) {
            found++;
            cout << found << ":" << it.getTitle() << endl;
            results.push_back(it);
        }
    }
    if (!found) {
        cout << "Couldnt Find Any Results For : " << name << endl;
        return Book();
    }

    pick:
    cout << "Pick a Book by Number :";
    int choice;
    cin >> choice;
    if (choice <= found)
        return results[choice - 1];
    else
        goto pick;
}

// Function to find a book by name
Book Book::findByName(Custom_String_Class name) {
    vector<Book> results;
    int found = 0;
    cout << "found :" << endl;
    for (auto it : Book_List) {
        if (it.getTitle().find(name)) {
            found++;
            cout << found << ":" << it.getTitle() << endl;
            results.push_back(it);
        }
    }
    if (!found) {
        cout << "couldnt find a book \n";
        return Book();
    }

    pick:
    cout << "Pick a Book by Number :";
    int choice;
    cin >> choice;
    if (choice <= found)
        return results[choice - 1];
    else
        goto pick;
}

// Function to find a book by ISBN
Book Book::findByISBN(Custom_String_Class ID) {
    for (auto it : Book_List) {
        if (it.getISBN() == ID) {
            return it;
        }
    }
    cout << "Couldnt Find a Book" << endl;
    return Book();
}
