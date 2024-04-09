//
// Created by tarek on 4/5/2024.
//

#include "Member.h"
using namespace std;

Member::Member():Name(""),Type(""),ID(0),fines(0) {}
Member::Member(Custom_String_Class N,int I,Custom_String_Class T): Name(N),ID(I),Type(T){
    fines=0;
}
int Member::calculateTotalFines (){
    fines=0;
    for(auto it: checkedOutBooks){
        fines+=it.calculateFines();
    }
}

void Member::display() {
    std::cout << "Name: " << Name << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "Number of Checked Out Books: " << checkedOutBooks.size() << std::endl;
    std::cout << "Overdue Fines: " << calculateTotalFines() << std::endl;
}