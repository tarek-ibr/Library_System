//
// Created by tarek on 4/5/2024.
//

#include "Custom_String_Class.h"

Custom_String_Class::Custom_String_Class()
{
    str = new char[50];
}

Custom_String_Class::Custom_String_Class(char * s){
    int len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
}
Custom_String_Class::Custom_String_Class(const string& s){
   int m_length = s.length();
    str = new char[m_length + 1];
    std::strcpy(str, s.c_str());
}
Custom_String_Class Custom_String_Class::operator+(const Custom_String_Class& s) const
{
    int len = this->strlength()+s.strlength()+1;
    char * newstr = new char[len];
    strcpy(newstr,str);
    strcat(newstr,s.str);
    return newstr;
}
bool Custom_String_Class::operator==(const Custom_String_Class& s2) const
{
    return !this->strcompare(s2.str);
}
bool Custom_String_Class::operator!=(const Custom_String_Class& s2) const
{
    return this->strcompare(s2.str);
}
char Custom_String_Class::operator[](int x) const
{
    return *(this->str+x);
}

void Custom_String_Class::display() const
{
    cout<<str;
}
bool Custom_String_Class::find(const Custom_String_Class& s) const {
    return strstr(str,s.str);
}
int Custom_String_Class::strlength () const{
    return strlen(str);
}
int Custom_String_Class::strcompare (const Custom_String_Class& s) const{
    return strcmp(str, s.str);
}
Custom_String_Class::~Custom_String_Class()= default;

Custom_String_Class& Custom_String_Class::operator=(const char * str2) {
  int len = strlen(str2);
  str = new char[len+1];
  strcpy(str,str2);
  return *this;
}
