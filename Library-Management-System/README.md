# Library Management System in C++

## Project Overview
The Library Management System is a console-based application developed as part of the "Object Oriented Programming" course using C++. The system leverages advanced concepts, including Templates & STL, Class Templates, Function Templates, Inheritance, and Polymorphism. It manages a collection of books, performing various operations on the library’s catalog using STL containers and algorithms.

## Key Features
### Object Oriented Programming
- **Classes**: Utilizes Inheritance and Polymorphism to create a robust system architecture.
- **Class and Function Templates**: Implements templates to create flexible and reusable code.

### Search and Sort Functions
- **View entire catalog sorted by title**: Allows users to view the catalog, filtered by various categories such as title or genre.
- **Search for an item**: Provides functionality to search for specific books within the catalog.
  
### Edit Catalog Functions
- **Add and Remove items**: Enables users to add new books to the catalog or remove existing ones.

### Data Storage
The system uses STL vectors and maps to store and manage the catalog of books efficiently.

## Program Flow
The `main()` function manages user interactions by displaying available options and invoking the corresponding functions based on the user's choice. The application continues to operate in a loop until the user opts to exit.

## How to Set Up and Run the Project
1. **Clone the Repository**  
   Clone the repository from GitHub to your local machine using the following command:
    https://github.com/akin11235/Library-Management-System.git

2. **Navigate to the Project Directory**  
   Change your working directory to the project directory:
    ```
    cd Library-Management-System
    ```

3. **Compile the Program**  
   Use the `make` command to compile the source files. This command will use the Makefile provided in the repository to build the executable.
    ```
    make
    ```

4. **Run the Program**  
   After a successful compilation, run the program using:
    ```
    ./Library-Management-System
    ```

5. **Change Git Remote URL**  
    To avoid accidental pushes to the base project, change the Git remote URL:
    ```
    git remote set-url origin https://github.com/yourusername/Library-Management-System.git
    git remote -v # confirm the changes
    ```

6. **Clean Up Build Files**  
   To remove the compiled object files and the executable, use the `make clean` command. This is useful for cleaning up your directory and preparing for a fresh build.
    ```
    make clean
    ```

