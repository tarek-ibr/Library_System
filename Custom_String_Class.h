//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_CUSTOM_STRING_CLASS_H
#define PROJECT_CUSTOM_STRING_CLASS_H

#include <iostream>


using namespace std;

class Custom_String_Class {
private:
    char *str;
public:
    Custom_String_Class();
    Custom_String_Class(char * s);
    Custom_String_Class(const string& s);
    Custom_String_Class operator+(const Custom_String_Class& s);
    Custom_String_Class& operator=(const char *);

    bool operator==(const Custom_String_Class& s2) const;
    bool operator!=(const Custom_String_Class& s2) const;
    char operator[](int x) const;
    friend ostream& operator<<(std::ostream& out, const Custom_String_Class& c){
        out << c.str;
        return out;
    }
    friend istream& operator>>(istream& is, Custom_String_Class& obj) {
        char* buffer = new char[256];
        is.getline(buffer, 256);
        obj = Custom_String_Class(buffer);
        delete[] buffer;
        return is;
    }

    char * getSTR() const;

    char reverseCase(char c);
    void display() const;
    bool find(Custom_String_Class& s);
    int strlength () const;
    int strcompare (const Custom_String_Class& s) const;
    char* strcpy(char*,const char*);
    char* strcat(char*,const char*);
    static int strlen(const char*);
    string toString();

    ~Custom_String_Class();
};


#endif //PROJECT_CUSTOM_STRING_CLASS_H
