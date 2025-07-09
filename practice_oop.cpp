#include <iostream>

// 🟦 Abstract Class – Shows Inheritance and Polymorphism
class AbstractEmployee {
    // Pure virtual function – used to enforce implementation in derived classes
    virtual void AskForPromotion() = 0;
};

// 🟦 Class Declaration: Employee
class Employee : AbstractEmployee {
    // 🟩 Private attributes (Encapsulation)
private:
    std::string Company;
    int Age;

protected:
    std::string Name; // Accessible by derived classes

public:
    // 🟩 Setters and Getters – Encapsulation
    void setname(std::string name){
        this->Name = name;
    }

    std::string getname(){
        return Name;
    }

    void setcompany(std::string company){
        this->Company = company;
    }

    std::string getcompany(){
        return Company;
    }

    void setage(int age){
        if(age >= 18){
            this->Age = age;
        }
    }

    int getage(){
        return Age;
    }

    // Member function to introduce the employee
    void IntroduceYourSelf(){
        std::cout << "Name -> " << Name << std::endl;
        std::cout << "Company -> " << Company << std::endl;
        std::cout << "Age -> " << Age << std::endl;
    }

    // 🟨 Constructor – Called when creating object
    Employee(std::string name, std::string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }

    // Overridden virtual function from AbstractEmployee
    void AskForPromotion(){
        if(Age >= 30){
            std::cout << Name << " got promoted!" << std::endl;
        } else {
            std::cout << Name << ", sorry no promotion for you yet!" << std::endl;
        }
    }

    // 🟧 Virtual function – enables runtime polymorphism
    virtual void Work(){
        std::cout << Name << " is checking emails, task backlog, performing tasks." << std::endl; 
    }
};

// 🟦 Derived Class: Developer (inherits Employee)
class Developer : public Employee {
public:
    std::string FavProgramingLanguage;

    // 🟨 Constructor – Uses base class constructor too
    Developer(std::string name, std::string company, int age, std::string favprograminglanguage)
        : Employee(name, company, age) {
        FavProgramingLanguage = favprograminglanguage;
    }

    void Fixbug(){
        std::cout << Name << " fixed bug using " << FavProgramingLanguage << std::endl;
    }

    // 🟧 Overridden Work function (Polymorphism)
    void Work(){
        std::cout << Name << " is writing code in " << FavProgramingLanguage << std::endl;
    }
};

// 🟦 Derived Class: Teacher (inherits Employee)
class Teacher : public Employee {
public:
    std::string Subject;

    void PrepareLesson(){
        std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
    }

    // 🟨 Constructor
    Teacher(std::string name, std::string company, int age, std::string subject)
        : Employee(name, company, age) {
        Subject = subject;
    }

    // 🟧 Overridden Work function
    void Work(){
        std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
    }
};

// 🟦 Main function (Objects are created here)
int main() {
    // 🟦 Object of Developer – Uses constructor
    Developer d = Developer("Sefa", "Metay", 37, "C++");

    // 🟦 Object of Teacher – Uses constructor
    Teacher t = Teacher("Cinar", "Good School", 19, "History of English");

    // 🟧 Demonstrating runtime polymorphism using base class pointer
    Employee* e1 = &d;
    Employee* e2 = &t;

    // 🟧 Calls overridden Work() functions based on object type
    e1->Work();
    e2->Work();

    return 0;
}
