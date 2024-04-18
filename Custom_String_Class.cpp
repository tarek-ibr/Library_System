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
    strcpy(str, s.c_str());
}
Custom_String_Class Custom_String_Class::operator+(const Custom_String_Class& s)
{
    int len = this->strlength()+s.strlength()+1;
    char * newstr = new char[len];
    strcpy(newstr,str);
    strcat(newstr,s.str);
    return newstr;
}
char* Custom_String_Class::strcpy(char* destination, const char* source) {
    char* start = destination;
    while (*source != '\0') {
        *destination = *source;
        ++destination;
        ++source;
    }
    *destination = '\0';
    return start;
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
    bool found=true;
    for(int i=0;i<s.strlength();i++)
    {
        for(int j=0; j<i+this->strlength();j++)
        {
            if(s[j] != this->str[j])
                found=false;
            break;
        }
        if(found)
            return true;
    }
    return false;
}
int Custom_String_Class::strlength () const{
    int c=0;
    while(str[c]!='\0')
        c++;
    return c;
}

int Custom_String_Class::strcompare(const Custom_String_Class& s) const{
   if(this->strlength()!=s.strlength())
       return 0;
   for(int i=0;i<s.strlength();i++)
   {
       if(str[i]!=s[i])
           return 0;
   }
   return 1;
}
Custom_String_Class::~Custom_String_Class()= default;
Custom_String_Class& Custom_String_Class::operator=(const char * str2) {
  int len = strlen(str2);
  str = new char[len+1];
  strcpy(str,str2);
  return *this;
}
bool Custom_String_Class::operator==(const Custom_String_Class& str2) const {
    if(this->strlength()!=str2.strlength())
        return 0;
    for(int i=0;i<str2.strlength();i++)
    {
        if(str[i]!=str2[i])
            return false;
    }
    return true;
}
int Custom_String_Class::strlen(const char* s) {
    int c=0;
    while(s[c]!='\0')
        c++;
    return c;
}
char* Custom_String_Class::strcat(char* destination, const char* source) {
    char *ptr = destination;

    // Move the pointer to the end of the destination string
    while (*ptr != '\0') {
        ++ptr;
    }

    // Copy characters from source to the end of destination
    while (*source != '\0') {
        *ptr = *source;
        ++ptr;
        ++source;
    }

    // Null-terminate the concatenated string
    *ptr = '\0';

    return destination;

}