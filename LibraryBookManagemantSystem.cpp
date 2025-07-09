// Goal: Manage a library’s book records — title, author, ID, and year.
// The system should allow users to:

// Add new books

// Display all books

// Search by book ID or title

// Sort books by title or year (using Bubble/Selection Sort)

// Track the last borrowed books using a stack

// (Optional) Save and load from file




#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>



class Library{
    private:
    // some attributes
    std::string Title;
    std::string Author; 
    std::string ID;
    int Year;
    public:
    // some attributes
    Library(std::string title, std::string author, std::string id, int year) 
        : Title(title), Author(author), ID(id), Year(year) {}

    std::string getTitle() const { return Title;}
    std::string getAuthor() const { return Author;}
    std::string getID() const { return ID;}
    int getYear() const { return Year;}
    
};
// do not forget to use operate os function to enhencing the useability of class objects
std::ostream& operator<<(std::ostream& os, const Library& book){
    os << "Name: "   << book.getTitle()
       << "- Author: " <<  book.getAuthor()
       << "- ID: "     <<  book.getID()
       << "- Year: "   <<  book.getYear(); 
    return os;
}

// Display all books
void DisplayBooks(std::vector<Library>& BookInfoList);
// Search by book by ID 
void SearchBooksBYID(std::vector<Library>& BookInfoList, std::string inputID);
// Search by book by  title
void SearchBooksBYTitle(std::vector<Library>& BookInfoList, std::string inputtITitle);
// Add new books
void AddNewBook(std::vector<Library>& BookInfoList);
// Sort books by title or year (using Bubble/Selection Sort)
void ShortBooks(std::vector<Library>& BookInfoList);

// Track the last borrowed books using a sta-ck
int main(){
    std::vector<Library> BookInfoList;

    // Name, Author, ID, year 
    Library b1("Pride and Prejudice", "Jane Austen", "BN001", 1813);
    Library b2("The Great Gatsby", "F. Scott Fitzgerald", "BN002", 1925);
    Library b3("To Kill a Mockingbird", "Harper Lee", "BN003", 1960);
    Library b4("Moby-Dick", "Herman Melville", "BN004", 1851);
    
    BookInfoList.push_back(b1);
    BookInfoList.push_back(b2);
    BookInfoList.push_back(b3);
    BookInfoList.push_back(b4);

    int option;
    
    do{
        std::cout << "#######################################################################################" << std::endl;
        std::cout << "There are 4 options:\n";
        std::cout << "1 - Display all books\n";
        std::cout << "2 - ID search\n";
        std::cout << "3 - Title search\n";
        std::cout << "4 - Add a new Book\n";
        std::cout << "5 - Short book in published year\n";
        std::cout << "6 - Quit the system\n";
        std::cout << "#######################################################################################" << std::endl;
        std::cout << "Enter a number: ";
        std::cin >> option;
        
        if(option == 1){
            DisplayBooks(BookInfoList);    
        }
        else if(option == 2){
            std::string inputID;
            std::cout << "#######################################################################################" << std::endl;
            std::cout << "Enter ID to search: ";
            std::cin>>inputID;
            SearchBooksBYID(BookInfoList, inputID);
        }
        else if(option == 3){
            std::string inputtITitle;
            std::cout << "#######################################################################################" << std::endl;
            std::cout << "Enter Title to search: ";
            std::cin.ignore(); // flush leftover newline
            std::getline(std::cin, inputtITitle);

            inputtITitle.erase(std::remove(inputtITitle.begin(), inputtITitle.end(), ' '), inputtITitle.end());
            std::cout << "#######################################################################################" << std::endl;
            SearchBooksBYTitle(BookInfoList, inputtITitle);
            std::cout << "#######################################################################################" << std::endl;
        }
        else if(option == 4){
            std::cout << "#######################################################################################" << std::endl;
            AddNewBook(BookInfoList);
            std::cout << "#######################################################################################" << std::endl;
        }
        else if(option == 5){
            std::cout << "#######################################################################################" << std::endl;
            ShortBooks(BookInfoList);
            std::cout << "#######################################################################################" << std::endl;
        }
        else if(option == 6){
            break;
        }
        else{
            std::cout << "#######################################################################################" << std::endl;
            std::cout<<"Invalid Choice"<< std::endl;
            std::cout << "#######################################################################################" << std::endl;
        }

    }while(option != 6);

    return 0;
}


// Display all books
void DisplayBooks(std::vector<Library>& BookInfoList){
    for(std::size_t i = 0; i<BookInfoList.size(); i++){
        std::cout<< BookInfoList[i] << std::endl;
    }
    std::cout << "#######################################################################################" << std::endl;
    std::cout<< "There are "<< BookInfoList.size() << " books in this library.\n";
    std::cout << "#######################################################################################" << std::endl;
}

// Search by book ID or title
void SearchBooksBYID(std::vector<Library>& BookInfoList, std::string inputID){
    for(const Library& b :BookInfoList){
        if(b.getID() == inputID){
            std::cout << "#######################################################################################" << std::endl;
            std::cout << "The book with this ID " << b.getID()<< " "<< "found."<< std::endl;
            std::cout << "The book ID matched with this book: "<< " " << b.getTitle()<< std::endl;
            std::cout << "#######################################################################################" << std::endl;
            return;
        }
    }
    std::cout << "#######################################################################################" << std::endl;
    std::cout<< "THe book that you searched was not recorded in the system."<< std::endl;
    std::cout << "#######################################################################################" << std::endl;
}    
    
void SearchBooksBYTitle(std::vector<Library>& BookInfoList, std::string inputtITitle){
    bool IsItOkey = false;
    for(const Library& b : BookInfoList){
        std::string anti_text = b.getTitle();
        std::string text = b.getTitle();
        text.erase(std::remove(text.begin(), text.end(), ' '), text.end());
        if(text == inputtITitle){
            std::cout << "#######################################################################################" << std::endl;
            std::cout << "The book with this name " << anti_text<< "found.\n";
            std::cout << "#######################################################################################" << std::endl;
            IsItOkey = true;
            return;
        }
    }
    if(IsItOkey == false){
        std::cout << "#######################################################################################" << std::endl;
        std::cout<< "THe book that you searched was not recorded in the system.\n";
        std::cout << "#######################################################################################" << std::endl;
    }    
}    

// Add new books
void AddNewBook(std::vector<Library>& BookInfoList){
    std::string new_Title;
    std::string new_Author; 
    std::string new_ID;
    int new_Year;

    // Get input from user
    std::cout << "#######################################################################################" << std::endl;
    std::cout << "Enter a book name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, new_Title);
    std::cout<<"###########################################"<<std::endl;
    std::cout << "Enter a author name: ";
    std::getline(std::cin, new_Author);
    std::cout<<"###########################################"<<std::endl;
    std::cout << "Enter a book id: ";
    std::getline(std::cin, new_ID);
    std::cout<<"###########################################"<<std::endl;
    std::cout << "Enter a publishing year: ";
    std::cin>>new_Year;
    
    Library b(new_Title, new_Author, new_ID, new_Year);
    std::cout<<"###########################################"<<std::endl;
    std::cout << "Process is complated successfuly" << std::endl; 
    std::cout << "#######################################################################################" << std::endl;

    return BookInfoList.push_back(b);             
}

// Sort books by title or year (using Selection Short)
void ShortBooks(std::vector<Library>& BookInfoList){
    
    for(std::size_t i = 0; i<BookInfoList.size(); i++)
    {
        int min_pos = i;
        for(int j = i+1; j<BookInfoList.size(); j++)
        { 
            if(BookInfoList[j].getYear() < BookInfoList[min_pos].getYear())
            {
                min_pos = j;
            }
        }
        if(min_pos != i)
        {
            std::swap(BookInfoList[i], BookInfoList[min_pos]);            
        }
    }
    for(const Library& book : BookInfoList)
    {
        std::cout<< book <<std::endl;
    }
}