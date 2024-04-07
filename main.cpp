#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>

#include "json.h"

#include "Book.h"
#include "Member.h"
#include "Librarian.h"
#include "Loan.h"
#include "Custom_String_Class.h"

using namespace std;
using json = nlohmann::json;

void findbook(vector<Book> books,string s){
    bool found = 0;
    for(auto it:books)
    {
        if(it.title.find(s)!=string::npos)
        {
            found =1;
            cout<<"found :"<<it.title<<endl;
        }
    }
    if(!found)
    {
        cout<<"couldnt find a book";
    }

    return;
}

int main() {
    std::ifstream file("books.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    json j;
    file >> j;

    std::vector<Book> books;
    for (const auto& book_json : j["books"]) {
        Book bk;
        bk.title = book_json["title"];
        bk.author = book_json["author"];
        bk.isbn = book_json["isbn"];
        bk.publication_year = book_json["publication_year"];

        books.push_back(bk);
    }
    string n;
    cout<<"type book name:";
    cin>>n;
    findbook(books,n);
    json new_book_json = {
            {"title", "practical a7a"},
            {"author", "practical a7a"},
            {"isbn", "practical a7a"},
            {"publication_year", "practical a7a"}
    };

    j["books"].push_back(new_book_json);




    return 0;
}
