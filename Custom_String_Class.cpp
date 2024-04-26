// Created by tarek on 4/5/2024.

#include "Custom_String_Class.h"

// Default constructor
Custom_String_Class::Custom_String_Class()
{
    str = new char[50]; // Allocate memory for the string
}

// Constructor that takes a C-style string
Custom_String_Class::Custom_String_Class(char * s){
    int len = strlen(s); // Get the length of the input string
    str = new char[len+1]; // Allocate memory for the string
    strcpy(str,s); // Copy the input string to the member string
}

// Constructor that takes a C++ string
Custom_String_Class::Custom_String_Class(const string& s){
    int m_length = s.length(); // Get the length of the input string
    str = new char[m_length + 1]; // Allocate memory for the string
    strcpy(str, s.c_str()); // Copy the input string to the member string
}

// Overloaded assignment operator for C-style strings
Custom_String_Class& Custom_String_Class::operator=(const char * str2) {
    int len = strlen(str2); // Get the length of the input string
    str = new char[len+1]; // Allocate memory for the string
    strcpy(str,str2); // Copy the input string to the member string
    return *this; // Return a reference to the current object
}

// Overloaded addition operator for concatenating two strings
Custom_String_Class Custom_String_Class::operator+(const Custom_String_Class& s)
{
    int len = this->strlength()+s.strlength()+1; // Calculate the length of the new string
    char * newstr = new char[len]; // Allocate memory for the new string
    strcpy(newstr,str); // Copy the current string to the new string
    strcat(newstr,s.str); // Append the input string to the new string
    return newstr; // Return the new string
}

// Overloaded equality operator for comparing two strings
bool Custom_String_Class::operator==(const Custom_String_Class& str2) const {
    if(this->strlength()!=str2.strlength()) // If the lengths are not equal, the strings are not equal
        return 0;
    for(int i=0;i<str2.strlength();i++) // Compare each character
    {
        if(str[i]!=str2[i]) // If any character is not equal, the strings are not equal
            return false;
    }
    return true; // If all characters are equal, the strings are equal
}

// Overloaded inequality operator for comparing two strings
bool Custom_String_Class::operator!=(const Custom_String_Class& s2) const
{
    return !(*this==s2); // Use the equality operator to determine inequality
}

// Overloaded subscript operator for accessing characters in the string
char Custom_String_Class::operator const
{
    return *(this->str+x); // Return the character at the given index
}

// Function to copy a string
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

// Function to concatenate a string
char* Custom_String_Class::strcat(char* destination, const char* source) {
    char *ptr = destination;
    while (*ptr != '\0') {
        ++ptr;
    }
    while (*source != '\0') {
        *ptr = *source;
        ++ptr;
        ++source;
    }
    *ptr = '\0';
    return destination;
}

// Function to compare two strings
int Custom_String_Class::strcompare(const Custom_String_Class& s) const{
    if(this->strlength()!=s.strlength()) // If the lengths are not equal, the strings are not equal
        return 0;
    for(int i=0;i<s.strlength();i++) // Compare each character
    {
        if(str[i]!=s[i]) // If any character is not equal, the strings are not equal
            return 0;
    }
    return 1; // If all characters are equal, the strings are equal
}

// Function to get the length of the string
int Custom_String_Class::strlength () const{
    int c=0;
    while(str[c]!='\0') // Count the number of characters until the null terminator
        c++;
    return c;
}

// Function to get the length of a C-style string
int Custom_String_Class::strlen(const char* s) {
    int c=0;
    while(s[c]!='\0') // Count the number of characters until the null terminator
        c++;
    return c;
}

// Function to change the case of a character
char Custom_String_Class::reverseCase(char c) {
    if (c >= 'a' && c <= 'z') // If the character is lowercase, make it uppercase
        return c - 32;
    else if (c >= 'A' && c <= 'Z') // If the character is uppercase, make it lowercase
        return c + 32;
    else // If the character is not a letter, return it unchanged
        return c;
}

// Function to find a substring in the string
bool Custom_String_Class::find(Custom_String_Class& s)  {
    for(int i=0;i<this->strlength();i++) // Iterate through each character in the string
    {
        bool found=true;
        for(int j=i; j<i+s.strlength();j++) // Compare each character in the substring
        {
            if(s[j-i] != this->str[j] && reverseCase(s[j-i]) != this->str[j]) { // If any character is not equal, the substring is not found
                found=false;
                break;
            }
        }
        if(found) // If all characters are equal, the substring is found
            return true;
    }
    return false; // If no matching substring is found, return false
}

// Function to display the string
void Custom_String_Class::display() const
{
    cout<<str;
}

// Function to get the C-style string
char * Custom_String_Class::getSTR() const {
    return str;
}

// Function to convert the C-style string to a C++ string
string Custom_String_Class::toString() {
    string s = str;
    return s;
}

// Destructor
Custom_String_Class::~Custom_String_Class()=default;
