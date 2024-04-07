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
Custom_String_Class Custom_String_Class::operator+(Custom_String_Class s)
{
    int len = strlen(this->str)+strlen(s.str)+1;
    char * newstr = new char[len];
    strcpy(newstr,str);
    strcat(newstr,s.str);
    return newstr;
}
bool Custom_String_Class::operator==(Custom_String_Class s2)
{
    return !strcmp(str,s2.str);
}
bool Custom_String_Class::operator!=(Custom_String_Class s2)
{
    return strcmp(str,s2.str);
}
char Custom_String_Class::operator[](int x)
{
    return *(this->str+x);
}

void Custom_String_Class::display()
{
    cout<<*this;
}
Custom_String_Class::~Custom_String_Class(){
    delete str;
    cout<<"string destructor called";

}