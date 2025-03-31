#include<iostream>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<iomanip>
#include<limits>

#include "Book.h"
#include "Catalog.h"
#include "LibraryItem.h"
#include "Magazine.h"

using std::string;
using std::vector;
using std::list;
using std::sort;
using std::cout;
using std::cin;
using std::endl;


// get and validate integer input
int getIntInput(const string& promptUser, bool& exitCondition);

// get and validate string input
string getStringInput(const string& prompt, bool& exitCondition);


// Main function starts here

int main() {

	cout << "======================================================" << endl;
	cout << "  ***   Welcome to the Library Management System   ***  " << endl;
	cout << "======================================================" << endl << endl;

	string userName; // user name input for Inventory Constructor

	// Take user input to initialize the Catalog class
	cout << "Enter any character to log into the inventory system: ";
	getline(cin, userName);
	cout << endl;

	// Create the library catalog and populate with fake data (for testing)
	Catalog<LibraryItem> allbooks(userName);

	// create seed data with 4 items
	Book* b1 = new Book(100, "The Great Gatsby", "F. Scott Fitzgerald", "123456789", "Fiction", 1925);
	Book* b2 = new Book(200, "1984", "George Orwell", "9780140817744", "Dystopian", 1949);
	Book* b3 = new Book(300, "To Kill a Mockingbird", "Harper Lee", "9781846572562", "Classic", 1960);
	Magazine* m1 = new Magazine(400, "Sports Illustrated", "ABG", "985123456789", "Sport", 2024);

	// add seed data to vector in the catalog class
	cout << "Loading seed data... " << endl << endl;
	allbooks.addItemToMainList(b1, b2, b3, m1);

	// take user input for choice of action
	int choice{ 0 };
	
	// Main while loop for program navigation
	while (choice != 8)
	{
		cout << "-----------------------------------------------------------" << endl;
		cout << "Main menu" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "1 - View entire catalog (Sorted by Title)" << endl;
		cout << "2 - View entire catalog (Sorted by Genre)" << endl;
		cout << "3 - View catalog by publication type (Books and Magazines)" << endl;
		cout << "4 - Menu for other view options (authors, genres etc)" << endl;
		cout << "5 - Search for an item" << endl;
		cout << "6 - Add a new item" << endl;
		cout << "7 - Remove an item" << endl;
		cout << "8 - Exit" << endl << endl;

		cout << "Select an option from the menu above to proceed: ";
		cin >> choice;
		cout << endl;
		
		// Display all items in the catalog - sorted by title
		if (choice == 1) 
		{
			cout << "-----------------------------------------------------------" << endl;
			cout << "Current menu selection: " << endl <<   "Main menu - Option 1 (View entire collection sorted by title)" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "Displaying entire collection sorted by title..." << endl<< endl;
			allbooks.sortByTitle();
			allbooks.displayAll();
			allbooks.totalItemsInList();
			cout << endl;
		}
		// Endif - catalog sorted by title

		// Display all items in the catalog - sorted by genre
		if (choice == 2) 
		{
			cout << "-----------------------------------------------------------" << endl;
			cout << "Current menu selection: " << endl << "Main menu - Option 2 (View entire collection sorted by genre)" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "Displaying entire collection sorted by genre..." << endl << endl;
			allbooks.sortByGenre();
			allbooks.displayAll();
			allbooks.totalItemsInList();
			cout << endl;
		} 
		// Endif - sorted by genre

		// Display items by publication type
		if (choice == 3) 
		{
			cout << "-----------------------------------------------------------" << endl;
			cout << "Current menu selection: " << endl << "Main menu - Option 3 (View by publication type)" << endl;
			cout << "-----------------------------------------------------------" << endl;

			// int viewOptionsChoice{ 0 };

			int collectionChoice{ 0 };
			while (collectionChoice != 3)
			{
				cout << "1 - View books in the catalog" << endl;
				cout << "2 - View magazines in the catalog" << endl;
				cout << "3 - Return to main menu" << endl;

				cout << endl << "Select an option from the menu above: ";

				cin >> collectionChoice;
				cout << endl;

				switch (collectionChoice)
				{
				case 1: // Display books only
					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 1: View books collection" << endl;
					cout << "-----------------------------------------------------------" << endl;
					cout << "In progress... " << endl << endl;
					break;

				case 2: // Display magazines only
					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 2: View magazine collection" << endl;
					cout << "-----------------------------------------------------------" << endl;
					cout << "In progress... " << endl << endl;
					break;

				case 3:
					cout << "Return to main menu" << endl;
					break;

				default:
					cout << "Wrong choice. Please select the correct option" << endl;
					break;
				}
			}
		} // Endif - Display items by publication type


		if (choice == 4) // Display available genres, authors and other combinations
		{
			

			int collectionChoice{ 0 };
			while (collectionChoice != 4)
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Current menu selection: " << endl << "Main menu - Option 4 (Other view choices)" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "1 - View available genres" << endl;
				cout << "2 - View available authors" << endl;
				cout << "3 - View Titles with author details" << endl;
				cout << "4 - Return to main menu" << endl;

				cout << endl << "Select an option from the menu above: ";

				cin >> collectionChoice;
				cout << endl;

				switch (collectionChoice)
				{
				case 1: // Display genres only
					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 1: Available genres" << endl;
					cout << "-----------------------------------------------------------" << endl;
					allbooks.displayAllGenres();
					cout << endl;
					break;

				case 2: // Display authors only
					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 2: Available authors" << endl;
					cout << "-----------------------------------------------------------" << endl;
					allbooks.displayAuthors();
					cout << endl;
					break;

				case 3: // Display by title and author // Display collection by genre
					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 3: Available titles with author details" << endl;
					cout << "-----------------------------------------------------------" << endl;
			
					allbooks.displayTitleAndAuthor();
					break;

				case 4:
					cout << "Return to main menu" << endl;
					break;

				default:
					cout << "Wrong choice. Please select the correct option" << endl;
					break;
				}
			}
		} // EndIf - Display available genres // Endif - Display available authors


		if (choice == 5) //Search for an item
		{

			int searchChoice{ 0 };

			while (searchChoice != 3)
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Current menu selection: " << endl << "Main menu - Option 5 (Search for an item)" << endl;
				cout << "-----------------------------------------------------------" << endl;

				cout << "1 - Search item by title" << endl;
				cout << "2 - Search item by Id" << endl;
				cout << "3 - Return to main menu" << endl;

				cout << endl << "Select an option from the menu above: ";

				while (!(cin >> searchChoice) || searchChoice < 1 || searchChoice > 3) {
					cout << "Invalid input. Please enter a number between 1 and 3: ";
					cin.clear(); // clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
				}
				cout << endl;

				switch (searchChoice)
				{
				case 1:
				{
					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 1: Search item by title" << endl;
					cout << "-----------------------------------------------------------" << endl;

					cout << "Enter the title of the item ('Enter x' to exit): ";

					string title;
					cin.ignore(); // Clear the buffer before taking a new line input
					getline(cin, title);
					if (title == "x") {
						break;
					}
					try {
						const LibraryItem* found = allbooks.searchItem(title);
						if (found) {
							cout << endl << ">>>>>> Found item with title: " << found->getTitle() << endl << endl;

							found->displayDetails();
						}
						else {
							cout << "Item not found." << endl << endl;
						}
					}
					catch (const runtime_error& e) {
						cerr << e.what() << endl;
					}
				}
					break;

				case 2:

					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 1: Search item by ID" << endl;
					cout << "-----------------------------------------------------------" << endl << endl;

					cout << "Enter the ID of the item ('Enter -1' to exit): ";

					int id;
					while (!(cin >> id) || id < -1) {
						cout << "Invalid input. Please enter a valid ID (or -1 to exit): ";
						cin.clear(); // clear the error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
					}

					if (id == -1) {
						break;
					}


					try {
						const LibraryItem* found = allbooks.searchItem(id);
						if (found) {
							cout << endl << ">>>>>> Found item with id: " << found->getId() << endl << endl;

							found->displayDetails();
						}
						else {
							cout << "Item not found." << endl << endl;
						}		
					}
					catch (const runtime_error& e) {
						cerr << e.what() << endl;
					}
					break;

				case 3:
					cout << "Return to main menu" << endl;
					break;

				default:
					cout << "Wrong choice. Please select the correct option" << endl;
					break;
				}
			}	
		} //Endif - Search for an item


		if (choice == 6) //Add a new item
		{
			cout << "-----------------------------------------------------------" << endl;
			cout << "Current menu selection: " << endl << "Main menu - Option 4 (Add Items to catalog)" << endl;
			cout << "-----------------------------------------------------------" << endl << endl;

			int addItemsChoice{ 0 };

			while (addItemsChoice != 3)
			{
				cout << "1 - Load additional seed data into the current catalog" << endl;
				cout << "2 - Add a new item to the catalog" << endl;
				cout << "3 - Return to main menu" << endl;
			
			cout << endl << "Select an option from the menu above: ";

			cin >> addItemsChoice;
			cout << endl;

			switch (addItemsChoice)
			{
			case 1: // sub menu 1 - add additional seed data for testing
				{
					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 1: Load additional seed data" << endl;
					cout << "-----------------------------------------------------------" << endl << endl;

					cout << "Loading 3 new items..." << endl << endl;

					Book* b4 = new Book(500, "Pride and Prejudice", "Jane Austen", "9780140434262", "Romance", 1813);
					Book* b5 = new Book(600, "Moby-Dick", "Herman Melville", "9780140434262", "Adventure", 1851);
					Book* b6 = new Book(700, "The Lord of the Rings", "J.R.R. Tolkien", "9788445071793", "Fantasy / Adventure", 1954);

					allbooks.addItemToMainList(b4, b5, b6);

					b4->displayDetails();
					b5->displayDetails();
					b6->displayDetails();
				}
				break; // End of case 1

			case 2: // sub menu 2 - Add a new item to the catalog
				{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Sub-menu 2: Add a new item to the catalog" << endl;
				cout << "-----------------------------------------------------------" << endl << endl;

					cout << "Enter the following details for the item ('Enter -1' to exit): " << endl << endl;

					bool exitCondition = false;

					while (!exitCondition)
					{
						int id = getIntInput("ID: ", exitCondition);
						if (exitCondition) {
							cout << "Exiting..." << endl << endl;
							break;
						}
						string title = getStringInput("Title: ", exitCondition);
						if (exitCondition) {
							cout << "Exiting..." << endl << endl;
							break;
						}
						string author = getStringInput("Author: ", exitCondition);
						if (exitCondition) {
							cout << "Exiting..." << endl << endl;
							break;
						}
						string ISBN = getStringInput("ISBN: ", exitCondition);
						if (exitCondition) {
							cout << "Exiting..." << endl << endl;
							break;
						}
						string genre = getStringInput("Genre: ", exitCondition);
						if (exitCondition) {
							cout << "Exiting..." << endl << endl;
							break;
						}
						int year = getIntInput("Year: ", exitCondition);
						if (exitCondition) {
							cout << "Exiting..."<< endl << endl;
							break;
						}	
						Book* B = new Book(id, title, author, ISBN, genre, year);
						cout << endl << "Adding \"" << title << "\" to the catalog... " << endl << endl;
				
						B->displayDetails();
				
						allbooks.addItemToMainList(B);
					} // end while loop
				}
				break; // End of case 2

			case 3:
				cout << "Return to main menu" << endl;
				break;

			default:
				cout << "Wrong choice. Please select the correct option" << endl;
				break;
			} // End Switch

			} // End while loop

		} //Endif - Add a new item


		if (choice == 7) // Remove an item
		{
			cout << "-----------------------------------------------------------" << endl;
			cout << "Current menu selection: " << endl << "Main menu - Option 4 (Remove an item)" << endl;
			cout << "-----------------------------------------------------------" << endl << endl;

			int removeItemsChoice{ 0 };

			while (removeItemsChoice != 3)
			{
				cout << "1 - Remove last item added" << endl;
				cout << "2 - Remove all items" << endl;
				cout << "3 - Return to main menu" << endl;

				cout << endl << "Select an option from the menu above: ";

				cin >> removeItemsChoice;
				cout << endl;

				switch (removeItemsChoice)
				{
				case 1:
					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 1: Remove last item added" << endl;
					cout << "-----------------------------------------------------------" << endl << endl;

					cout << "Removing last item added \"";
					allbooks.getLastAdded();
					cout << "\" from the catalog..." << endl<<endl;

					allbooks.removeLastItem();

					cout << "Here are the items remaining in the catalog: " << endl;
					allbooks.displayAll();

					break;

				case 2:
					cout << "-----------------------------------------------------------" << endl;
					cout << "Sub-menu 2: Remove all items" << endl;
					cout << "-----------------------------------------------------------" << endl << endl;

					cout << "All items have been removed... " << endl;
					allbooks.removeAllItems();
					allbooks.displayAll();
					cout << endl << endl;
					break;

				case 3:
					cout << "Return to main menu" << endl;
					break;

				default:
					break;
				}
			}

			


			
			
			
		} // Endif - Remove an item

		if (choice == 8) // Exit the program
		{
			cout << "Good bye!" << endl;
		} // Endif - Exit the program

	}
	// End of main while loop for program navigation

	cout << endl;

	return 0;
}
// End of function main


//=============================================================
//////////// ** FUNCTION DEFINITIONS ** /////////////
//=============================================================

int getIntInput(const string& promptUser, bool &exitCondition) {
	int input;
	while (true) {
		
		cout << promptUser;
		cin >> input;
		if (input == -1)
		{
			exitCondition = true;
			return -1;
		}
		if (cin.fail()) {
			cin.clear(); // clear the error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			cout << "Invalid input... Enter an integer value." << endl;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard remaining input
			return input;
		}
	}
}

// get and validate string input
string getStringInput(const string& promptUser, bool& exitCondition) {
	string input;
	cout << promptUser;
	getline(cin, input);
	if (input == "x")
	{
		exitCondition = true;
		return "";
	}
	return input;
}