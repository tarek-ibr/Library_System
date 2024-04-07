#include <iostream>
#include <fstream>
#include <vector>
#include "json.h"
#include "Book.h"
#include "Member.h"
#include "Librarian.h"
#include "Loan.h"
#include "Custom_String_Class.h"

using namespace std;
using json = nlohmann::json;

void findbook(vector<Book> books,Custom_String_Class s){
    bool found = 0;
    for(auto it:books)
    {
        if(it.Title.find(s)!=string::npos)
        {
            found =1;
            cout<<"found :"<<it.Title<<endl;
        }
    }
    if(!found)
    {
        cout<<"couldnt find a book";
    }

    return;
}
class String {
private:
    char* m_data; // Pointer to C-style string
    size_t m_length; // Length of string

public:
    // Default constructor
    String() : m_data(nullptr), m_length(0) {}

    // Constructor from C-style string
    String(const char* str) {
        m_length = std::strlen(str);
        m_data = new char[m_length + 1];
        std::strcpy(m_data, str);
    }

    // Constructor from std::string
    String(const std::string& str) {
        m_length = str.length();
        m_data = new char[m_length + 1];
        std::strcpy(m_data, str.c_str());
    }

    // Copy constructor
    String(const String& other) : m_length(other.m_length) {
        m_data = new char[m_length + 1];
        std::strcpy(m_data, other.m_data);
    }

    // Destructor
    ~String() {
        delete[] m_data;
    }

    // Assignment operator from C-style string
    String& operator=(const char* str) {
        if (this ->m_data != str) {
            delete[] m_data;
            m_length = std::strlen(str);
            m_data = new char[m_length + 1];
            std::strcpy(m_data, str);
        }
        return *this;
    }

    // Assignment operator from std::string
    String& operator=(const std::string& str) {
        if (this->m_data != str) {
            delete[] m_data;
            m_length = str.length();
            m_data = new char[m_length + 1];
            std::strcpy(m_data, str.c_str());
        }
        return *this;
    }

    // Copy assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] m_data;
            m_length = other.m_length;
            m_data = new char[m_length + 1];
            std::strcpy(m_data, other.m_data);
        }
        return *this;
    }

    // Function to get C-style string
    const char* c_str() const {
        return m_data;
    }
    void display()
    {
        cout<<m_data;
    }
};

    // Other member functions as needed


int main() {

Book::loadlibrary();
Book::displaylist();
Book::Book_List.front().Title = "zepy";
Book::savelibrary();




    return 0;
}
