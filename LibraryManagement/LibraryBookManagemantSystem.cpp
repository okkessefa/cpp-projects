// Goal: Manage a library’s book records — title, author, ID, and year.
// The system should allow users to:

// Add new books

// Display all books

// Search by book ID or title

// Sort books by title or year (using Bubble/Selection Sort)

// Track the last borrowed books using a stack

// (Optional) Save and load from file



#include <iostream>     // cout, cin, getline
#include <fstream>      // ifstream, ofstream
#include <string>       // string, stoi, to_string
#include <vector>       // vector
#include <array>        // array
#include <utility>      // swap
#include <algorithm>    // remove (if you use it)
#include <limits>       // numeric_limits<streamsize>::max()
#include <climits>      // INT_MAX (if you use INT_MAX)
#include <cstdlib>      // exit, EXIT_FAILURE
#include <stdexcept>    // invalid_argument, out_of_range (if you catch them)


class Library{
    private:
    // some attributes
    std::string Title;
    std::string Author; 
    std::string ID;
    std::string Year;

    //Return Book Count
    int BookCount();

    public:

    // Display all books
    void DisplayBooks();
    // Search by book by ID 
    void SearchBooksBYID();
    // Search by book by  title
    void SearchBooksBYTitle();
    // Add new books
    std::vector<std::array<std::string, 4>> Bookimp();
    // Sort books by title or year (using Bubble/Selection Sort)
    void ShortBooks();

    // some attributes
    Library(std::string title, std::string author, std::string id, std::string year) 
        : Title(title), Author(author), ID(id), Year(year) {}
};
          
// ##############################################################################################################################################################################
    int Library::BookCount(){
        int numLines = 0;
        std::ifstream in("books.txt");
        std::string unused;
        while ( std::getline(in, unused) )
        {
            ++numLines;
        }        
        return numLines;
}
//✅

// Display all books
    void Library::DisplayBooks(){
        std::ifstream inFile("books.txt");
        if (!inFile) {
            std::cerr << "Error opening file for reading.\n";
            std::exit(EXIT_FAILURE); // or return EXIT_FAILURE;
        }
        std::string line;
        int order = 0;
        std::cout << "#######################################################################################" << std::endl;
        while (std::getline(inFile, line)) { // Reads one line at a time
            ++order;
            std::cout<< order <<" -> " << line << std::endl;
        }
        std::cout << "#######################################################################################" << std::endl;
        std::cout<< "There are "<< BookCount() << " books in this library.\n";
        std::cout << "#######################################################################################" << std::endl;

    }
//✅

// Search by book ID or title
    void Library::SearchBooksBYID()
    {
        std::ifstream file("books.txt");
        if(!file)
        {
            std::cerr<<"Error openning file.\n";
            std::exit(EXIT_FAILURE);
        }

        
        std::string title;
        std::string author; 
        std::string id;
        std::string year;
        std::string tempid;
        std::cout<<"Enter the Book id you want to search: ";
        std::getline(std::cin, tempid);

        while(
            std::getline(file,title,'|') &&
            std::getline(file,author,'|') &&
            std::getline(file,id,'|') &&
            std::getline(file,year))
        {
            if(id == tempid)
            {
                std::cout << "Found match: " << title << " (" << id << ")\n";
                return;
            }
        
        }
        std::cout << "#######################################################################################" << std::endl;
        std::cout<< "THe book that you searched was not recorded in the system."<< std::endl;
        std::cout << "#######################################################################################" << std::endl;
    }
    // ✅
 
    void Library::SearchBooksBYTitle(){
        std::ifstream file("books.txt");
        if (!file) {
            std::cerr << "Error openning file.\n";
            std::exit(EXIT_FAILURE);
        }

        std::string title, author, id, year, temptitle;
        std::cout << "Enter the Book title you want to search: ";
        std::getline(std::cin, temptitle);            // <-- only getline

        while ( std::getline(file, title,  '|') &&
                std::getline(file, author, '|') &&
                std::getline(file, id,     '|') &&
                std::getline(file, year) ) {          // <-- last field: no '|'
            if (title == temptitle) {
                std::cout << "Found match: " << title << " (" << id << ")\n";
                return;
            }
        }

        std::cout << "#######################################################################################\n";
        std::cout << "The book that you searched was not recorded in the system.\n";
        std::cout << "#######################################################################################\n";
    }  
    // ✅

    std::vector<std::array<std::string, 4>> Library::Bookimp() {
        bool isRunning;
        char add;
        std::vector<std::array<std::string, 4>> books;

        std::cout << "Do you wanna add book into Library (Y/N): ";
        std::cin >> add;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        isRunning = (add == 'y' || add == 'Y');

        while (isRunning) 
        {
            std::string tempTitle, tempAuthor, tempId, tempYear;

            std::cout << "Enter Book Name: ";
            std::getline(std::cin, tempTitle);

            std::cout << "Enter Author Name: ";
            std::getline(std::cin, tempAuthor);

            // auto ID by count
            int numLines = 0;
            std::ifstream in("books.txt");
            std::string unused;
            while (std::getline(in, unused)) ++numLines;
            tempId = "BN" + std::to_string(numLines + 1);

            std::cout << "Enter Book Year: ";
            std::getline(std::cin, tempYear);        // <-- keep as string
            // (no extra ignore here)

            books.push_back({tempTitle, tempAuthor, tempId, tempYear});

            char choice;
            std::cout << "Add another book(y/n): ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice != 'y' && choice != 'Y') isRunning = false;
        }

        return books;
    }
    // ✅

    // Sort books by title or year (using Selection Short)
    void Library::ShortBooks(){

        int BOOKcount = BookCount();

        std::ifstream file("books.txt");
        if(!file)
        {
            std::cerr<<"Error openning file.\n";
            std::exit(EXIT_FAILURE);
        }
        std::vector<Library> books;
        std::string title, author, id, yearSTR;
        while(
            std::getline(file,title,'|')  &&
            std::getline(file,author,'|') &&
            std::getline(file,id,'|')     &&
            std::getline(file,yearSTR))
            {
                books.push_back({title, author, id, yearSTR});
            }
        for(std::size_t i=0; i+1<books.size(); ++i)
        {
            std::size_t min_pos = i;
            for(std::size_t j = i+1; j< books.size(); ++j)
            {
                int yj, ymin;
                try
                {
                    yj= std::stoi(books[j].Year);
                }
                catch(...)
                {
                    yj= INT_MAX;
                }
                try
                {
                    ymin = std::stoi(books[min_pos].Year);
                }
                catch(...)
                {
                    ymin = INT_MAX;
                }
                if(yj<ymin)
                {
                    min_pos = j;
                }
            }
            if(min_pos != i)
            {
                std::swap(books[i], books[min_pos]);
            }
        }
        std::cout << "######## Sorted by Year (ascending) ########\n";
        for(const auto& b : books)
        {
            std::cout << b.Title << " | " << b.Author << " | "<< b.ID << " | " << b.Year << '\n';
        }
    }
    // ✅
    
int main(){

    Library lib("", "", "", "");  // dummy fields (your methods use the file)
    int option;
    
    do{
        std::cout << "1-Display  2-ID search  3-Title search  4-Add  5-Sort by year  6-Quit\n";
        std::cout << "Enter a number: ";
        if (!(std::cin >> option)) return 0;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (option) {
            case 1: lib.DisplayBooks(); break;
            case 2: lib.SearchBooksBYID(); break;
            case 3: lib.SearchBooksBYTitle(); break;
            case 4: {
                auto books = lib.Bookimp();
                std::ofstream out("books.txt", std::ios::app);
                if (!out) { std::cerr << "Error opening file for writing.\n"; break; }
                for (const auto& b : books) {
                    out << b[0] << '|' << b[1] << '|' << b[2] << '|' << b[3] << '\n';
                }
                break;
            }
            case 5: lib.ShortBooks(); break;
            case 6: break;
            default:
                std::cout << "Invalid choice\n";
        }

    }while(option != 6);

    return 0;
}