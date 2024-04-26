#include "User.h" // Include the User header file

std::vector<Loan> Librarian::borrowRequests= {}; // Static vector to store borrow requests
std::vector<Librarian> Librarian::librarians={}; // Static vector to store librarians

// Default constructor for Librarian class
Librarian::Librarian():Member() {}

// Parameterized constructor for Librarian class
Librarian::Librarian(const Custom_String_Class& name, int ID) : Member(name, ID, Custom_String_Class("Librarian")) {}

// Function to add a book to the library inventory
void Librarian::addBook() {
    Custom_String_Class title;
    cout << "Enter book's title: " << endl;
    cin >> title;

    Custom_String_Class isbn;
    cout << "Enter book's ISBN: " << endl;
    cin >> isbn;

    Custom_String_Class author;
    cout << "Enter author's name: " << endl;
    cin >> author;

    Custom_String_Class genre;
    cout << "Enter book's genre: " << endl;
    cin >> genre;

    int publicationYear;
    cout << "Enter book's publication year: " << endl;
    cin >> publicationYear;

    int Quantity;
    cout<<"Enter Book's Quantity:";
    cin>>Quantity;

    Book newBook(title,author,isbn,genre,publicationYear,Quantity);
    Book::getBookList().push_back(newBook); // Add the new book to the book list
}

// Function to remove a book from the library inventory
void Librarian::removeBook(const Custom_String_Class& ISBN) {
    // Check if the book is currently loaned out
    for(auto it:Loan::Loans_List){
        if(ISBN==it.getBookID()){
            cout<<"the book is loaned by someone you can't remove it";
            return;
        }
    }

    // Remove the book if it's not loaned out
    for(auto it = Book::getBookList().begin(); it != Book::getBookList().end(); ) {
        if(it->getISBN() == ISBN) {
            cout << "Now I am removing \n";
            Book::getBookList().erase(it); // Erase the book from the book list
            return;
        } else {
            ++it; // Move to the next element
        }
    }
}

// Function to add a borrow request to the list
void Librarian::addBorrowRequest(Loan& ln) {
    borrowRequests.push_back(ln); // Add the loan to the borrow requests list
}

// Function to display all pending borrow requests
void Librarian::displayRequests() {
    if (borrowRequests.empty()) {
        cout << "No pending borrow requests." << std::endl;
        return;
    }

    cout << "Pending Borrow Requests:\n";
    for (size_t i = 0; i < borrowRequests.size(); ++i) {
        const auto& request = borrowRequests[i];
        cout << i + 1 << ". Member ID: " << request.getMemberID()
             << ", Book ISBN: " << request.getBookID() << std::endl;
    }
}

// Function to process a borrow request for a book
bool Librarian::borrowBook(Book b, Member member){
    vector<Book>& bkList= Book::getBookList(); // Get the list of all books
    vector<Loan>& checkedBooks= member.getCheckedOutBooks(); // Get the list of books checked out by the member
    vector<Loan>& loansList= Loan::getLoans_List(); // Get the list of all loans

    // Find the index of the book in the book list

    int i;
    for(i=0; !(bkList[i].getISBN() == b.getISBN()); i++);

    // Check if the book is available
    if(bkList[i].getQuantity()>0) {
        Date dueDate;
        // If only one copy is left, set the book as unavailable
        if (bkList[i].getQuantity()==1){
            bkList[i].setAvailability(false);
        }
        // Decrease the quantity of the book
        bkList[i].setQuantity(bkList[i].getQuantity()-1);

        // Set the due date based on the member type
        if(member.getType()==Custom_String_Class("Member")||member.getType()==Custom_String_Class("Student")) {
            dueDate = Date::getCrrentDate() + 7;
            cout<<dueDate.getDate();
        }
        else if(member.getType()==Custom_String_Class("Staff"))
            dueDate = Date::getCrrentDate() + 10;
        else if(member.getType()==Custom_String_Class("Faculty"))
            dueDate = Date::getCrrentDate() + 14;

        Loan newloan(member.getID(), bkList[i].getISBN(), dueDate, Date::getCrrentDate());         // Create a new loan
        checkedBooks.push_back(newloan);         // Add the loan to the member's checked out books
        cout<<checkedBooks.back().getBookID();
        loansList.push_back(newloan);         // Add the loan to the list of all loans
        return true;
    }
    else{ // If the book is not available
        cout << "there are no copies of the book available"<<endl;
        return false;
    }
}

// Function to approve a borrow request and issue the book
void Librarian::approveBorrowRequest(Loan ln) {
    Book bk = Book::findByISBN(ln.getBookID());
    Member member = Librarian::findMemberByID(ln.getMemberID());

    for(auto it =borrowRequests.begin(); it != borrowRequests.end(); ) {
        if(it->getBookID() == ln.getBookID() && it->getMemberID() ==ln.getMemberID()) {
            borrowRequests.erase(it); // Remove the request from the borrow requests list
            break;
        } else {
            ++it;
        }
    }

    if(borrowBook(bk, member))
        cout << "Borrow request approved and book issued." << endl;
}

// Function to return a borrowed book to the library
void Librarian::returnBook(Member& member, Book& book) {
    vector<Book>& bkList= Book::getBookList();
    vector<Loan>& checkedBooks= member.getCheckedOutBooks();
    vector<Loan>& loansList= Loan::getLoans_List();

    int i;
    for(i=0; !(book.getISBN() == bkList[i].getISBN()); i++);
    if(bkList[i].getQuantity()==0)
        bkList[i].setAvailability(true);
    bkList[i].setQuantity(bkList[i].getQuantity()+1);
    for(auto it = checkedBooks.begin(); it != checkedBooks.end(); ) {
        if((it->getBookID() == bkList[i].getISBN()) && (it->getMemberID()==member.getID())) {
            checkedBooks.erase(it); // Remove the book from the checked out books list
            break;
        } else {
            ++it;
        }
    }
    for(auto it =loansList.begin(); it != loansList.end() ; ) {
        if((it->getBookID() == bkList[i].getISBN()) && (it->getMemberID()==member.getID())) {
            loansList.erase(it); // Remove the loan from the loans list
            cout<<"\nRemoved Book With ISBN("<<it->getBookID()<<")\n";
            break;
        } else {
            ++it;
        }
    }
}

// Function to edit the details of a book in the library inventory
void Librarian::editBook(Book& book)
{
    char answer;
    cout << "Do you want to edit the title ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin.ignore();
        cout << "Enter book's title: " << endl;
        cin >> book.getTitle();
    }
    cout << "Do you want to edit the ISBN ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin.ignore();
        cout << "Enter book's ISBN: " << endl;
        cin >> book.getISBN();
    }

    cout << "Do you want to edit the author ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin.ignore();
        cout << "Enter author's name: " << endl;
        cin >> book.getAuthor();
    }

    cout << "Do you want to edit the genre ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin.ignore();
        cout << "Enter book's genre: " << endl;
        cin >> book.getGenre();
    }

    cout << "Do you want to edit the publication year ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin.ignore();
        cout << "Enter book's publication year: " << endl;
        cin >> book.getPubYear();
    }
    cout << "Do you want to edit the quantity ?(Y/N)" << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        cin.ignore();
        cout<<"Enter Book's Quantity:";
        cin>>book.getQuantity();
        cin.ignore();
    }
    book.setAvailability(book.getQuantity()>0); // Update the availability of the book based on the quantity
}

// Function to register a new member in the library system
void Librarian::registerNewMember(){
    Custom_String_Class name, type;
    int id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter type: ";
    cin >> type;
    members.push_back(Member(name, id, type)); // Add the new member to the members list
    cout << "New member registered successfully.\n";
}


// Function to remove a member from the library
void Librarian::removeMember(int id)
{
    // Loop through all loans
    for(auto it:Loan::Loans_List)
    {
        // If the member has not returned a loaned book yet
        if(it.getMemberID()==id)
        {
            cout<<"This Member Has Not Returned A Loaned Book Yet!\n";
            return;
        }
    }
    bool found = false;
    // Loop through all members
    for (auto it = members.begin(); it != members.end() ; ++it) {
        // If the member is found
        if (it->getID() == id) {
            // Remove the member
            members.erase(it);
            cout << "Member with ID " << id << " removed successfully.\n";
            found = true;
            break;
        }
    }
    // If the member is not found
    if (!found) {
        cout << "Member not found.\n";
    }
}

// Function to display all members
void Librarian::displayAllMembers() {
    int i=1;

    std::cout << "List of Members:\n";

    cout<< "--------------------\n";
    // Loop through all members
    for (auto& member : members) {
        cout<<i++<<" ";
        // Display each member
        member.display();
    }

}

// Function to display the librarian
void Librarian::display(){
    cout<< "--------------------\n";
    cout<<"Name: "<<getName()<<endl;
    cout<<"ID: "<<getID()<<endl;
    cout<< "--------------------\n";
}

// Function to load the librarian
bool Librarian::loadLibrarian() {
    // Clear all borrow requests
    borrowRequests.clear();
    std::ifstream file("borrowRequests.json");
    // If the file is not open
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return false;
    }

    json j;
    file >> j;

    // Loop through all requests
    for (const auto& Requests_json : j) {
        // Create a new loan
        Loan ln(Requests_json["memberID"], Custom_String_Class(Requests_json["bookID"].get<string>()), Date(Custom_String_Class(Requests_json["dueDate"].get<string>())), Date(Custom_String_Class(Requests_json["borrowDate"].get<string>())));
        // Add the loan to the borrow requests
        borrowRequests.push_back(ln);
    }
    file.close();
    return true;
}

// Function to save the librarian
bool Librarian::saveLibrarian() {
    std::ofstream file("borrowRequests.json");
    // If the file is not open
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << endl;
        return false;
    }
    json OUTPUT;
    // Loop through all borrow requests
    for(const auto& ln : borrowRequests)
    {
        json bookJson;

        // Save the member ID, book ID, due date, and borrow date
        bookJson["memberID"] = ln.getMemberID();
        bookJson["bookID"] = ln.getBookID().getSTR();
        bookJson["dueDate"] = ln.getDueDate().getDate().getSTR();
        bookJson["borrowDate"] = ln.getBorrowDate().getDate().getSTR();

        // Add the book to the output
        OUTPUT.push_back(bookJson);
    }
    // Write the output to the file
    file<<setw(4)<<OUTPUT<<endl;// setw(4) sets the width of the output field to 4
    file.close();
    return true;
}

// Function to find a librarian by name
Librarian Librarian::findLibrarianByName(Custom_String_Class name){
    vector<Librarian> results;
    int found = 0;
    cout << "found :" << endl;
    // Loop through all librarians
    for (auto it : librarians) {
        // If the librarian is found
        if (it.getName().find(name)) {
            found++;
            cout << found << ":" << it.getName() << endl;
            // Add the librarian to the results
            results.push_back(it);
        }
    }
    // If the librarian is not found
    if (!found) {
        cout << "Couldn't Find Any Results For : " << name << endl;
        return Librarian();
    }

    pick:
    cout << "Pick a librarian by Number :";
    int choice;
    cin >> choice;
    // If the choice is valid
    if (choice <= found)
        return results[choice - 1];
    else
        goto pick;
}

// Function to find a librarian by ID
Librarian Librarian::findLibrarianByID(int id){
    // Loop through all librarians
    for(auto it:librarians)
    {
        // If the librarian is found
        if(it.getID()==id)
        {
            return it;
        }
    }
    cout<<"Couldn't Find librarian"<<endl;

    return Librarian();
}

// Function to find a member by name
Member Librarian::findMemberByName(Custom_String_Class name){
    vector<Member> results;
    int found = 0;
    cout << "found :" << endl;
    // Loop through all members
    for (auto it : members) {
        // If the member is found
        if (it.getName().find(name)) {
            found++;
            cout << found << ":" << it.getName() << endl;
            // Add the member to the results
            results.push_back(it);
        }
    }
    // If the member is not found
    if (!found) {
        cout << "Couldn't Find Any Results For : " << name << endl;
        return Member();
    }

    pick:
    cout << "Pick a member by Number :";
    int choice;
    cin >> choice;
    // If the choice is valid
    if (choice <= found)
        return results[choice - 1];
    else
        goto pick;
}

// Function to find a member by ID
Member Librarian::findMemberByID(int id){
    // Loop through all members
    for(auto it:members)
    {
        // If the member is found
        if(it.getID()==id)
        {
            return it;
        }
    }
    cout<<"Couldn't Find member"<<endl;

    return Member();
}

// Function to load members
bool Librarian::loadMembers() {
    // Clear all checked out books for each member
    for(auto it:members)
    {
        it.getCheckedOutBooks().clear();
    }
    // Clear all members and librarians
    members.clear();
    librarians.clear();

    std::ifstream file("users.json");    // If the file is not open
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return false;
    }

    json j;
    file >> j;

    // Loop through all members
    for (const auto& member_json : j) {
        // If the member is not a librarian
        if(member_json["Type"].get<string>()!="Librarian") {
            Member m;

            // Set the name, ID, type, and fines of the member
            m.setName(member_json["Name"].get<string>());
            m.setID(member_json["ID"].get<int>());
            m.setType(member_json["Type"].get<string>());
            m.setFines(member_json["Fines"].get<int>());

            // Loop through all loans
            for (auto &it: Loan::getLoans_List()) {
                // If the member has a loan
                if (m.getID() == it.getMemberID()) {
                    // Add the loan to the checked out books
                    m.getCheckedOutBooks().push_back(it);
                }
            }
            // Add the member to the members
            members.push_back(m);
        }
        else{
            Librarian l;

            // Set the name, ID, type, and fines of the librarian
            l.setName(member_json["Name"].get<string>());
            l.setID(member_json["ID"].get<int>());
            l.setType(member_json["Type"].get<string>());
            l.setFines(member_json["Fines"].get<int>());

            // Add the librarian to the librarians
            librarians.push_back(l);
        }
    }
    file.close();
    return true;
}

// Function to save members
bool Librarian::saveMembers() {
    std::ofstream file("users.json");
    // If the file is not open
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << endl;
        return false;
    }
    json OUTPUT;
    // Update the total fines for each member
    for(auto& member : members){
        member.updateTotalFines();
    }
    // Loop through all members
    for(const auto& member : members)
    {
        json bookJson;

        // Save the name, ID, type, and fines of the member
        bookJson["Name"] = member.getName().getSTR();
        bookJson["ID"] = member.getID();
        bookJson["Type"] = member.getType().getSTR();
        bookJson["Fines"] = member.getFines();

        // Add the member to the output
        OUTPUT.push_back(bookJson);
    }
    // Loop through all librarians
    for(const auto& librarian : librarians)
    {
        json bookJson;

        // Save the name, ID, type, and fines of the librarian

        bookJson["Name"] = librarian.getName().getSTR();
        bookJson["ID"] = librarian.getID();
        bookJson["Type"] = librarian.getType().getSTR();
        bookJson["Fines"] = librarian.getFines();

        OUTPUT.push_back(bookJson);
    }
    file<<setw(4)<<OUTPUT<<endl;// what is the meaning of setw(4) ya ziad
    file.close();
    return true;
}

vector<Librarian>& Librarian::getLibrarians(){
    return librarians;
}

vector<Loan>& Librarian::getBorrowRequests(){
    return borrowRequests;
}
