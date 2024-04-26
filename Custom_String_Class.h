// Created by tarek on 4/5/2024.

#ifndef PROJECT_CUSTOM_STRING_CLASS_H
#define PROJECT_CUSTOM_STRING_CLASS_H

#include <iostream>

using namespace std;

// Custom_String_Class definition
class Custom_String_Class {
private:
    char *str; // Pointer to the character array that holds the string

public:
    // Default constructor
    Custom_String_Class();

    // Constructor that takes a C-style string
    Custom_String_Class(char * s);

    // Constructor that takes a C++ string
    Custom_String_Class(const string& s);

    // Overloaded addition operator for concatenating two strings
    Custom_String_Class operator+(const Custom_String_Class& s);

    // Overloaded assignment operator for C-style strings
    Custom_String_Class& operator=(const char *);

    // Overloaded equality operator for comparing two strings
    bool operator==(const Custom_String_Class& s2) const;

    // Overloaded inequality operator for comparing two strings
    bool operator!=(const Custom_String_Class& s2) const;

    // Overloaded subscript operator for accessing characters in the string
    char operator[](int) const;

    // Overloaded stream insertion operator for outputting the string
    friend ostream& operator<<(std::ostream& out, const Custom_String_Class& c){
        out << c.str;
        return out;
    }

    // Overloaded stream extraction operator for inputting the string
    friend istream& operator>>(istream& is, Custom_String_Class& obj) {
        char* buffer = new char[256];
        is.getline(buffer, 256);
        obj = Custom_String_Class(buffer);
        delete[] buffer;
        return is;
    }

    // Function to get the C-style string
    char * getSTR() const;

    // Function to change the case of a character
    char reverseCase(char c);

    // Function to display the string
    void display() const;

    // Function to find a substring in the string
    bool find(Custom_String_Class& s);

    // Function to get the length of the string
    int strlength () const;

    // Function to compare two strings
    int strcompare (const Custom_String_Class& s) const;

    // Function to copy a string
    char* strcpy(char*,const char*);

    // Function to concatenate a string
    char* strcat(char*,const char*);

    // Function to get the length of a C-style string
    static int strlen(const char*);

    // Function to convert the C-style string to a C++ string
    string toString();

    // Destructor
    ~Custom_String_Class();
};

#endif //PROJECT_CUSTOM_STRING_CLASS_H
