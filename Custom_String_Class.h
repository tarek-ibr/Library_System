//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_CUSTOM_STRING_CLASS_H
#define PROJECT_CUSTOM_STRING_CLASS_H

#include <iostream>
#include <cstring>

using namespace std;

class Custom_String_Class {
private:char *str;
public:
    Custom_String_Class();
    Custom_String_Class(char * s);
    Custom_String_Class(string s);
    Custom_String_Class operator+(Custom_String_Class s);
    Custom_String_Class& operator=(const char *);
    bool operator==(Custom_String_Class s2);
    bool operator!=(Custom_String_Class s2);
    char operator[](int x);
    friend ostream& operator<<(std::ostream& out, const Custom_String_Class& c){
        out << c.str;
        return out;
    }
    friend istream& operator>>(std::istream& in, const Custom_String_Class& c){

        in >> c.str;
        return in;
    }
    void display();
    bool find(Custom_String_Class s);
    int strlength ();
    int strcompare (Custom_String_Class s);
    ~Custom_String_Class();
};


#endif //PROJECT_CUSTOM_STRING_CLASS_H
