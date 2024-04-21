//
// Created by tarek on 4/5/2024.
//

#include "Member.h"
using namespace std;

using json = nlohmann::json;


vector<Member> Member::members={};
Member::Member():Name(""),Type(""),ID(0),Fines(0) {}
Member::Member(const Custom_String_Class& N,int I,const Custom_String_Class& T): Name(N),ID(I),Type(T){
    Fines=0;
}
Custom_String_Class Member::getName() {
    return Name;
}

int Member::getID() const {
    return ID;
}

Custom_String_Class Member::getType() {
    return Type;
}

int Member::getFines() {
    Fines=calculateTotalFines();
    return Fines;
}

void Member::setName(const Custom_String_Class& name) {
    Name = name;
}

void Member::setID(int id) {
    ID = id;
}

void Member::setType(const Custom_String_Class& type) {
    Type = type;
}
int Member::calculateTotalFines (){
    Fines=0;
    for(auto it: checkedOutBooks){
        Fines+=it.calculateFines();
    }
    return Fines;
}
void Member::display(){
    std::cout << "Name: " << Name << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "Number of Checked Out Books: " << checkedOutBooks.size() << std::endl;
    std::cout << "Overdue Fines: " << calculateTotalFines() << std::endl;
}
void Member::displayloaned() const{
    for(auto it =this->checkedOutBooks.begin(); it != this->checkedOutBooks.end() + 1; ++it) {
        if (it->getMemberID() == ID) {
            cout << "you have borrowed a book with ID " <<it->getBookID();
        }
    }
}
void Member::borrowBook(Book b){
    vector<Book> bkList= Book::getBookList();
    int i;
    for(i=0; bkList[i].getISBN() != b.getISBN(); i++);
    if(bkList[i].getQuantity()>0) {
        Date dueDate;
        if (bkList[i].getQuantity()==1){
            bkList[i].setAvailability(false);
        }
        bkList[i].setQuantity(bkList[i].getQuantity()-1);
        if(Type==Custom_String_Class("Member"))
            dueDate = Date::getCrrentDate() + 7;
        else if(Type==Custom_String_Class("Staff"))
            dueDate = Date::getCrrentDate() + 10;
        else if(Type==Custom_String_Class("Faculty"))
            dueDate = Date::getCrrentDate() + 14;
        Loan newloan(ID, bkList[i].getISBN(), dueDate);
        this->checkedOutBooks.push_back(newloan);
        Loan::Loans_List.push_back(newloan);
    }
    else{
        cout << "there is no copies of the book available"<<endl;
    }
}
void Member::returnBook(Book b) {
    vector<Book> bkList= Book::getBookList();
    int i;
    for(i=0; bkList[i].getISBN() != bkList[i].getISBN(); i++);
    if(bkList[i].getQuantity()==0)
        bkList[i].setAvailability(true);
    bkList[i].setQuantity(bkList[i].getQuantity()+1);
    for(auto it =this->checkedOutBooks.begin(); it != this->checkedOutBooks.end() + 1; ) {
        if(it->getBookID() == bkList[i].getISBN() && it->getMemberID()==ID) {
            //
// Created by tarek on 4/5/2024.
//

#include "Member.h"
            using namespace std;

            using json = nlohmann::json;


            vector<Member> Member::members={};
            Member::Member():Name(""),Type(""),ID(0),Fines(0) {}
            Member::Member(const Custom_String_Class& N,int I,const Custom_String_Class& T): Name(N),ID(I),Type(T){
                Fines=0;
            }
            Custom_String_Class Member::getName() {
                return Name;
            }

            int Member::getID() const {
                return ID;
            }

            Custom_String_Class Member::getType() {
                return Type;
            }

            int Member::getFines() {
                Fines=calculateTotalFines();
                return Fines;
            }

            vector<Loan>& Member::getCheckedOutBooks(){
                return checkedOutBooks;
            }

            void Member::setName(const Custom_String_Class& name) {
                Name = name;
            }

            void Member::setID(int id) {
                ID = id;
            }

            void Member::setType(const Custom_String_Class& type) {
                Type = type;
            }
            int Member::calculateTotalFines (){
                Fines=0;
                for(auto it: checkedOutBooks){
                    Fines+=it.calculateFines();
                }
                return Fines;
            }
            void Member::display(){
                std::cout << "Name: " << Name << std::endl;
                std::cout << "ID: " << ID << std::endl;
                std::cout << "Type: " << Type << std::endl;
                std::cout << "Number of Checked Out Books: " << checkedOutBooks.size() << std::endl;
                std::cout << "Overdue Fines: " << calculateTotalFines() << std::endl;
            }
            void Member::displayloaned() const{
                for(auto it =this->checkedOutBooks.begin(); it != this->checkedOutBooks.end() + 1; ++it) {
                    if (it->getMemberID() == ID) {
                        cout << "you have borrowed a book with ID " <<it->getBookID();
                    }
                }
            }
            void Member::requestBorrow(Book& book) {
                Loan ln(ID, book.getISBN());
                Librarian::addBorrowRequest(ln);
            }
            void Member::returnBook(Book book) {
                Librarian::returnBook(this, book);
            }
            bool Member::loadMembers() {
                std::ifstream file("members.json");
                if (!file.is_open()) {
                    std::cerr << "Failed to open file." << std::endl;
                    return false;
                }

                json j;
                file >> j;

                for (const auto& member_json : j) {
                    Member m;

                    m.Name = (member_json["Name"].get<string>());
                    m.ID = member_json["ID"].get<int>();
                    m.Type = member_json["Type"].get<string>();
                    m.Fines = member_json["Fines"].get<int>();
                    members.push_back(m);
                }
                file.close();
                return true;
            }
            bool Member::saveMembers() {
                std::ofstream file("members.json");
                if (!file.is_open()) {
                    std::cerr << "Failed to open file." << endl;
                    return false;
                }
                json OUTPUT;
                for(const auto& member : members)
                {
                    json bookJson;

                    bookJson["Name"] = member.Name.str;
                    bookJson["ID"] = member.ID;
                    bookJson["Type"] = member.Type.str;
                    bookJson["Fines"] = member.Fines;

                    OUTPUT.push_back(bookJson);
                }
                file<<setw(4)<<OUTPUT<<endl;// what is the meaning of setw(4) ya ziad
                file.close();
                return true;
            }

            Member Member::findByID(int id){
                for(auto it:members)
                {
                    if(it.getID()==id)
                    {
                        return it;
                    }
                }
                cout<<"Couldn't Find a Book"<<endl;
            }

            void Member::displayAllMembers() {
                std::cout << "List of Members:\n";
                for (auto &member: members) {
                    member.display();
                    std::cout << "-------------------------\n";
                }
            } cout << "Now Iam removing \n";
            checkedOutBooks.erase(it);
            return;
        } else {
            ++it;
        }
    }
    for(auto it =Loan::Loans_List.begin(); it != Loan::Loans_List.end() + 1; ) {
        if(it->getBookID() == bkList[i].getISBN() && it->getMemberID()==ID) {
            cout << "Now Iam removing \n";
            Loan::Loans_List.erase(it);
            return;
        } else {
            ++it;
        }
    }
}
bool Member::loadMembers() {
    std::ifstream file("members.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return false;
    }

    json j;
    file >> j;

    for (const auto& member_json : j) {
        Member m;

        m.Name = (member_json["Name"].get<string>());
        m.ID = member_json["ID"].get<int>();
        m.Type = member_json["Type"].get<string>();
        m.Fines = member_json["Fines"].get<int>();
        members.push_back(m);
    }
    file.close();
    return true;
}
bool Member::savelibrary() {
    std::ofstream file("members.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << endl;
        return false;
    }
    json OUTPUT;
    for(const auto& member : members)
    {
        json bookJson;

        bookJson["Name"] = member.Name.str;
        bookJson["ID"] = member.ID;
        bookJson["Type"] = member.Type.str;
        bookJson["Fines"] = member.Fines;

        OUTPUT.push_back(bookJson);
    }
    file<<setw(4)<<OUTPUT<<endl;// what is the meaning of setw(4) ya ziad
    file.close();
    return true;
}
void Member::displayAllMembers() {
    std::cout << "List of Members:\n";
    for (auto &member: members) {
        member.display();
        std::cout << "-------------------------\n";
    }
}