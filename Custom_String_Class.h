//
// Created by tarek on 4/5/2024.
//

#ifndef PROJECT_CUSTOM_STRING_CLASS_H
#define PROJECT_CUSTOM_STRING_CLASS_H

#include <iostream>


using namespace std;

class Custom_String_Class {
private:
public:
    char *str;
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
    friend istream& operator>>(std::istream& in, const Custom_String_Class& c){

        in >> c.str;
        return in;
    }
    void display() const;
    bool find(const Custom_String_Class& s) const;
    int strlength () const;
    int strcompare (const Custom_String_Class& s) const;
    char* strcpy(char*,const char*);
    char* strcat(char*,const char*);
    static int strlen(const char*);
    ~Custom_String_Class();
};


#endif //PROJECT_CUSTOM_STRING_CLASS_H
