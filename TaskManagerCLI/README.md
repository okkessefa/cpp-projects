# TaskManagerCLI

A simple, educational command‑line **Task Manager** implemented in modern C++ (C++17).  
The project demonstrates clean separation of concerns, singly linked‑list fundamentals, and robust user I/O for a small CLI application.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Build & Run](#build--run)
- [Usage](#usage)
- [Sample Session](#sample-session)
- [Design & Data Structures](#design--data-structures)
- [Complexity](#complexity)
- [Error Handling](#error-handling)
- [Testing Tips](#testing-tips)
- [Future Improvements](#future-improvements)
- [License](#license)

---

## Overview

**TaskManagerCLI** maintains a list of user tasks in memory. Tasks can be **added** at a specified position, **listed** in numbered order, and **removed** by index. Internally, the task list is implemented as a **singly linked list** to practice manual memory management and pointer manipulation.

This project is intended for learning purposes (OOP design + DS&A) and is small enough to read end‑to‑end.

---

## Features

- Add a task at any position (insertion at head or in the middle/end).
- List all tasks with indices (1‑based).
- Remove a task by its index.
- Existence check to validate successful insertion.
- Clear, menu‑driven CLI.
- Basic input sanitization for robust console interaction.

---

## Project Structure

```
OOP-PROJECTS/
├─ TaskManagerCLI/                # (optional workspace folder)
├─ main.cpp                       # Program entry point (menu loop)
├─ Node.h                         # Node definition for singly linked list
├─ TaskList.h                     # TaskList class interface
├─ TaskList.cpp                   # TaskList implementation (add / remove / display / exist)
├─ TaskManager.h                  # TaskManager interface (UI/controller)
├─ TaskManager.cpp                # TaskManager implementation (I/O, commands)
├─ README.md                      # This file
```

> If your repository uses a subfolder like `TaskManagerCLI/`, keep the same filenames under that folder and adjust compilation commands accordingly.

---

## Build & Run

### Requirements
- A C++17‑capable compiler (GCC, Clang, or MSVC)
- Windows, Linux, or macOS terminal

### Windows (MSYS2 / MinGW or similar)

```bash
g++ -std=c++17 -Wall -Wextra -O2 -o taskManagerCLI.exe \
    main.cpp TaskManager.cpp TaskList.cpp
.\taskManagerCLI.exe
```

### Linux / macOS (Clang or GCC)

```bash
g++ -std=c++17 -Wall -Wextra -O2 -o taskManagerCLI \
    main.cpp TaskManager.cpp TaskList.cpp
./taskManagerCLI
```

> If your files are inside `TaskManagerCLI/`, prepend the path: `TaskManagerCLI/main.cpp` etc.

---

## Usage

On launch, you will see a menu like:

// task manager commend lines
/*
| Command  | Description                                                                |
| -------- | -------------------------------------------------------------------------- |
| `add`    | Prompts the user to enter a new task and adds it to the task list.         |
| `list`   | Displays all current tasks in the list with numbered order.                |
| `remove` | Prompts the user to enter the number of a task to remove it from the list. |
| `exit`   | Exits the task manager application.                                        |
| `help`   | Displays a list of available commands with brief descriptions.             |

*/

- **Add task**: You will be prompted for the task **description** (free text) and the **position** (1‑based index).
- **Remove task**: Enter the task number shown in the list.
- **List tasks**: Displays tasks in numbered order.

---

## Sample Session

```
Welcome to Task Manager

| Command  | Description                                                                |
| -------- | -------------------------------------------------------------------------- |
| `add`    | Prompts the user to enter a new task and adds it to the task list.         |
| `list`   | Displays all current tasks in the list with numbered order.                |
| `remove` | Prompts the user to enter the number of a task to remove it from the list. |
| `exit`   | Exits the task manager application.                                        |
| `help`   | Displays a list of available commands with brief descriptions.             |
> add
Enter the task you want to add: Buy groceries
Enter the order you want to insert: 1
Task added successfully

> list
1. Buy groceries

> add
Enter the task you want to add: Finish C++ homework
Enter the order you want to insert: 1
Task added successfully

> list
1. Finish C++ homework
2. Buy groceries

> remove
Enter the task order you want to delete: 2
Task removed successfully

> list
1. Finish C++ homework

> exit
Goodbye!
```

---

## Design & Data Structures

- **Node** (`Node.h`)
  ```cpp
  struct Node {
      std::string description;
      Node* next{nullptr};
      explicit Node(const std::string& d) : description(d) {}
  };
  ```

- **TaskList** (`TaskList.h/.cpp`): encapsulates `head` pointer and list operations:
  - `void add(const std::string& task, const int& position)`
  - `bool remove(int index)`
  - `void display() const`
  - `bool exist(const std::string& task) const`
  - `int size() const`
  - `bool isEmpty() const`

- **TaskManager** (`TaskManager.h/.cpp`): user‑facing controller
  - Prompts, reads input, calls `TaskList` methods, prints results.

- **main** (`main.cpp`): minimal loop delegating to `TaskManager`.

---

## Complexity

Let *n* be the number of tasks.

- **Insert at head**: `O(1)`  
- **Insert at position k**: `O(k)` (worst case `O(n)`)  
- **Remove by index k**: `O(k)` (worst case `O(n)`)  
- **Exist / Display**: `O(n)`

A linked list is chosen for pointer practice and predictable insert/remove costs without shifting elements (as in vectors).

---

## Error Handling

- **Positions**: Insertion validates `position >= 1`; out‑of‑bounds positions are rejected with an error message.
- **Empty list**: Safe checks for operations on an empty list.
- **Input mix (`>>` with `getline`)**: After reading integers, the program clears the newline:
  ```cpp
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  ```
- **Memory safety**: All `new` allocations are paired with ownership in the list; removals delete nodes to avoid leaks.

---

## Testing Tips

- Insert at:
  - position `1` on an empty list (head insertion).
  - middle positions (e.g., insert at 2 when size is 3).
  - `position > size + 1` (expect rejection).
- Remove:
  - head, middle, and last elements.
  - from an empty list (expect graceful message).
- Robustness:
  - Provide non‑numeric input for positions.
  - Add duplicate descriptions and verify `exist()` semantics.

---

## Future Improvements

- Persist tasks to a file (save/load between runs).
- Edit task descriptions by index.
- Mark tasks as done / undone; filter by status.
- Replace raw pointers with `std::unique_ptr` for safer ownership.
- Add unit tests (e.g., with Catch2 / GoogleTest).
- Internationalization of CLI strings.
- Colorized terminal output and nicer command prompts.

---

## License

This project is released under the **MIT License**. See `LICENSE` for details.
