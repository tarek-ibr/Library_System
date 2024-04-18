#include <iostream>
#include <fstream>
#include <vector>
#include "json.h"
#include "Book.h"
#include "Member.h"
#include "Librarian.h"
#include "Loan.h"
#include "Custom_String_Class.h"
//Ammar
using namespace std;
using json = nlohmann::json;

void findbook(vector<Book> books,string s){
    bool found = 0;
    for(auto it:books)
    {
        if(it.getTitle().find(s)!=string::npos)
        {
            found =1;
            cout<<"found :"<<it.getTitle()<<endl;
        }
    }
    if(!found)
    {
        cout<<"couldnt find a book ";
    }

    return;
}

int main() {

    return 0;
}
