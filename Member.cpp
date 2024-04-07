//
// Created by tarek on 4/5/2024.
//

#include "Member.h"
using namespace std;

Member::Member():Name(""),ID(0) {}
Member::Member(Custom_String_Class A,int B): Name(A),ID(B) {}
vector<Custom_String_Class> Member::SearchByTitle(Custom_String_Class Title) {
    vector<Custom_String_Class> result;
}