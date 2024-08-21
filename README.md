# Library Management System in C

## Overview

This project is a simple Library Management System implemented in the C programming language. It uses linked lists to manage books in a library and includes functionalities such as adding, sorting, displaying, and storing book data in files.

## Features

- **Add Book**: Add a new book to the library.
- **Display Books**: Display all books in the library.
- **Sort Books**: Sort books based on title or author.
- **Save to File**: Save the current list of books to a file.
- **Load from File**: Load books from a file into the library system.

## Structure

The system is built using the following components:

- **Book Structure**: Stores information about a book, including its ID, title, author, and a pointer to the next book in the list.
- **Linked List**: Each book is a node in a linked list, allowing for dynamic management of the library's contents.

## Files

- `main.c`: The main file that contains the implementation of the library management system.
- `books.txt`: A file where book data is stored persistently.

## How to Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/library-management-system.git
   cd library-management-system
