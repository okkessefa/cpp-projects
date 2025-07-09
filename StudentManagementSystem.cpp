#include <iostream>
#include <vector>
#include <algorithm>

// ---------------------
// 🧑 Student Class
// ---------------------
class Student {
private:
    std::string Name;   // Student's name
    std::string ID;     // Student's ID
    double GPA;         // Student's Grade Point Average

public:
    // Constructor with parameters
    Student(std::string name, std::string id, double gpa) 
        : Name(name), ID(id), GPA(gpa) {}

    // Getter for Name
    std::string getName() const { return Name; }

    // Getter for ID
    std::string getID() const { return ID; }

    // Getter for GPA
    double getGPA() const { return GPA; }

    // Display student info (not used in this version, but useful)
    void displayInfo() const {
        std::cout << "- Name: " << Name;
        std::cout << " ID: " << ID;
        std::cout << " - GPA: " << GPA;
    }
};

// ---------------------
// 📤 Overload << Operator for Student
// Allows printing Student objects using std::cout << student
// ---------------------
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Name: " << student.getName()
       << " - ID: " << student.getID()
       << " - GPA: " << student.getGPA();
    return os;
    
}

// ---------------------
// 🔍 Function Prototypes
// ---------------------
void SearchStudentID(std::vector<Student>& StudentList);
void AddStudentIntoSystem(std::vector<Student>& StudentList);

// ---------------------
// 🧠 Main Function
// ---------------------
int main() {
    // Create a dynamic list of students
    std::vector<Student> StudentList;

    // Add some initial students to the system
    Student s1("Sefa", "ST001", 3.8);
    Student s2("Betul", "ST002", 3.2);
    Student s3("Cinar", "ST003", 2.9);

    StudentList.push_back(s1);
    StudentList.push_back(s2);
    StudentList.push_back(s3);

    int option;

    // ---------------------
    // 📋 Menu Loop
    // ---------------------
    do {
        // Show menu options
        std::cout << "There are 4 options:\n";
        std::cout << "1 - Display all students\n";
        std::cout << "2 - Search student by ID\n";
        std::cout << "3 - Add a new student\n";
        std::cout << "4 - Quit the system\n";
        std::cout << "Enter a number: ";
        std::cin >> option;

        // Option 1: Display all students
        if (option == 1) {
            for (std::size_t i = 0; i < StudentList.size(); i++) {
                std::cout << StudentList[i] << std::endl;
            }
            std::cout << "There are " << StudentList.size() << " students in the school.\n";
        }

        // Option 2: Search by ID
        else if (option == 2) {
            SearchStudentID(StudentList);
        }

        // Option 3: Add a new student
        else if (option == 3) {
            AddStudentIntoSystem(StudentList);
        }

        // Option 4: Quit
        else if (option == 4) {
            break;
        }

    } while (option != 4);

    return 0;
}

// ---------------------
// 🔍 Search Student by ID
// ---------------------
void SearchStudentID(std::vector<Student>& StudentList) {
    std::string inputID;
    std::cout << "Enter ID to search: ";
    std::cin >> inputID;

    // Linear search through the list
    for (const Student& s : StudentList) {
        if (s.getID() == inputID) {
            std::cout << "The student with ID " << s.getID() << " was found.\n";
            return;
        }
    }

    std::cout << "The student you searched for is not in the system.\n";
}

// ---------------------
// ➕ Add Student to the System
// ---------------------
void AddStudentIntoSystem(std::vector<Student>& StudentList){
    std::string new_Name;
    std::string new_ID;
    double new_GPA;
    
    // Get input from user
    std::cout << "Enter a student name: ";
    std::cin >> new_Name ;
    std::cout << "Enter a student ID: ";
    std::cin >> new_ID ; ; 
    std::cout << "Enter a student GPA: ";
    std::cin >> new_GPA;

    // Create a new student object and add to list
    Student s(new_Name, new_ID, new_GPA);
    std::cout << "Process is complated successfuly" << std::endl;
    
    return StudentList.push_back(s);             
}