# Restaurant Management System in C++

## Project Overview
The Restaurant Management System is an interactive console-based application designed for a restaurant, leveraging object-oriented software development principles using C++. The system is built using advanced concepts, including Templates & STL, Class Templates, Function Templates, Inheritance, and Polymorphism. It provides a user-friendly interface that allows customers to view menus, place orders, customize selections, and manage billing. The system is also designed for administrators to manage orders and edit drink and meal lists. 

### Key Actors
- **Customer**: Interacts with the system to view menus, place orders, and manage billing. The customer can view the main menu, select items including appetizers, entrees, desserts, drinks, and combos, add a tip, and proceed to checkout. The system provides a detailed bill including the total amount, tip, and applicable taxes.
- **Administrator**: Manages orders and maintains the menu by editing the list of drinks and meals.

### Key Features
- **Object-Oriented Programming**: Utilizes classes, inheritance, and polymorphism to create a robust system architecture. Class and function templates are implemented for flexible and reusable code.
- **Menu Interaction**: Customers can explore various menu categories, place orders, customize selections, and view detailed billing information.
- **Admin Management**: Administrators can manage orders and edit the menu items.

### Data Management
- **Data Storage**: Uses STL vectors, maps, and linked lists to store and manage menu items efficiently.

## Program Flow
The `main()` function manages user interactions by displaying available options and invoking corresponding functions based on user choices. The application operates in a loop until the user opts to exit.

## How to Set Up and Run the Project
1. **Clone the Repository**  
   Clone the repository from GitHub to your local machine:
    ```bash
    git clone https://github.com/akin11235/Restaurant-Management-System.git
    ```

2. **Navigate to the Project Directory**  
   Change your working directory to the project directory:
    ```bash
    cd Restaurant-Management-System
    ```

3. **Compile the Program**  
   Use the `make` command to compile the source files:
    ```bash
    make
    ```

4. **Run the Program**  
   After successful compilation, run the program:
    ```bash
    ./Restaurant-Management-System
    ```

5. **Change Git Remote URL**  
    To avoid accidental pushes to the base project, change the Git remote URL:
    ```bash
    git remote set-url origin https://github.com/yourusername/Restaurant-Management-System.git
    git remote -v # confirm the changes
    ```

6. **Clean Up Build Files**  
   To remove the compiled object files and executable, use the `make clean` command:
    ```bash
    make clean
    ```


