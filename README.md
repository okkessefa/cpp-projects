# 📚 C++ Management Systems Collection

This repository contains three beginner-to-intermediate level C++ console-based projects that apply fundamental Object-Oriented Programming principles, file handling, and data structure techniques.

---

## 🗂️ Projects Overview

### 1. 📖 Library Book Management System

**Purpose**: Manage a small library by storing book information (title, author, ID, year), allowing search, sorting, and additions.

**Features**:
- Add new books to the collection
- Display all stored books
- Search by **Book ID** or **Title**
- Sort by **publication year** (Selection Sort)
- Operator overloading (`<<`) for streamlined display
- *(Optional Extension)*: Stack to track last borrowed books or file I/O

**Technologies**:  
- `std::vector`, `std::string`, manual string sanitization  
- Input validation and robust menu loop  
- Sorting algorithms implemented manually  

📁 File: `LibraryBookManagemantSystem.cpp`

---

### 2. 👨‍🎓 Student Management System

**Purpose**: Maintain student records with names, IDs, and GPA, supporting insertion, display, and ID-based search.

**Features**:
- Display all student records
- Add new students
- Search for a student by **ID**
- Overloaded `<<` operator for clean display formatting

**Technologies**:
- OOP with encapsulation
- `std::vector`, linear search
- Console-based interaction

📁 File: `StudentManagementSystem.cpp`

---

### 3. 🧱 Practice – OOP Inheritance & Polymorphism

**Purpose**: Practice inheritance, encapsulation, abstract classes, and virtual functions through an **Employee System** simulation.

**Features**:
- Abstract base class: `AbstractEmployee`
- Concrete base class: `Employee`  
- Derived classes: `Developer`, `Teacher`
- Runtime polymorphism via virtual functions (`Work()`, `AskForPromotion()`)
- Demonstrates constructors, access modifiers, function overriding

**Technologies**:
- OOP best practices (encapsulation, inheritance, polymorphism)
- Runtime dynamic binding via base class pointers

📁 File: `practice_oop.cpp`

---

## 💡 How to Compile & Run

```bash
g++ -std=c++11 -o library LibraryBookManagemantSystem.cpp
./library

g++ -std=c++11 -o student StudentManagementSystem.cpp
./student

g++ -std=c++11 -o oop practice_oop.cpp
./oop
