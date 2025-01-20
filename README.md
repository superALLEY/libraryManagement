
# Library Management System in C

## Overview

This project is a simple Library Management System implemented in the C programming language. It utilizes linked lists to manage books in a library and includes functionalities such as adding books, adding users, handling book borrowing (emprunt), sorting, displaying, and storing book data in files.

## Features

- **Add Book**: Add a new book to the library.
- **Add User**: Add a new user (adherent) to the system.
- **Borrow Book (Emprunt)**: Allow a user to borrow a book from the library.
- **Return Book**: Allow a user to return a borrowed book to the library.
- **Display Books**: Display all books in the library.
- **Sort Books**: Sort books based on title or author.
- **Save to File**: Save the current list of books and users to files.
- **Load from File**: Load books and users from files into the system.

## Structure

The system is built using the following components:

- **Book Structure**: Stores information about a book, including its ID, title, author, and a pointer to the next book in the list.
- **User Structure**: Stores information about a user (adherent), including their ID, name, and borrowed books.
- **Emprunt (Borrowing) Structure**: Stores information about a borrowed book, including the user ID, book ID, and borrowing date.
- **Linked List**: Each book and user is a node in the respective linked lists, allowing dynamic memory allocation and efficient insertion and deletion operations.

## Files

- `main.c`: Contains the main function and the implementation of all functionalities.
- `list_adherent.txt`: Stores the list of adherents (users).
- `liste_emprunt.txt`: Stores the list of borrowed books (emprunt).
- `liste_livre.txt`: Stores the list of books in the library.

## Compilation and Execution

To compile and run the program, follow these steps:

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/superALLEY/LibraryManagement.git

2. **Navigate to the Project Directory**:
   
   ```bash
   cd LibraryManagement

3. **Compile the Code**:

To compile the code, use the following command:

   
   gcc -o library_management main.c

4. **Run the Program**:

After compiling, run the program using the following command:

  ```bash
  ./library_management
