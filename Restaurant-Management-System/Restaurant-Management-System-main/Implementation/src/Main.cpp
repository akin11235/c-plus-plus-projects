#include<iostream>

#include "RestaurantItem.h"
#include "SideDishItem.h"
#include "LinkedList.h"
#include "userMenus.h"
#include "DrinkItem.h"
#include "MenuManager.h"
#include "Customer.h"
#include "DessertItem.h"

#include "StringInputValidation.h"
#include "IntegerInputValidation.h"
#include "CharInputValidation.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


// Main function starts here
int main() {

	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t***   Welcome to the Restaurant Management System   ***  " << endl;
	cout << "------------------------------------------------------------------------------------------------------------\n" << endl;

	// ***   LOG INTO SYSTEM ***   //////////
	//=======================================
	bool exitCondition = false;

	// Take user input to initialize the MenuManager class
	string adminLogin = "Enter Admin code (minimum three character) to log into the inventory system (or 'x' to exit): ";
	string userName = getStringInput(adminLogin, exitCondition);

	if (exitCondition)
	{
		cout << "Exiting..." << endl;
		return 0;
	}

	cout << "\nUpdating database..." << endl;


	// ***   LOAD DATABASE ***   ////////////
	//=======================================
	MenuManager* menuManager = nullptr; // Pointer to store the MenuManager object
	menuManager = new MenuManager(userName); // Create a MenuManager object

	// Create some EntreeItem objects
	RestaurantItem* pasta = new EntreeItem(400, "**Pasta Primavera**", 16.50,
		"A delightful mix of seasonal vegetables tossed with penne pasta in a light olive oil and garlic sauce", "pasta", true);
	RestaurantItem* chicken = new EntreeItem(300, "**Lemon Herb Chicken**", 18.95,
		"Grilled chicken breast marinated in lemon and herbs, served with wild rice and sautéed green beans", "chicken", false);
	RestaurantItem* ribEye = new EntreeItem(100, "**Classic Ribeye Steak**", 24.95,
		"12 oz. ribeye steak cooked to perfection, served with garlic mashed potatoes and steamed vegetables.", "ribeye", true);

	// Create some SideDishItems objects
	RestaurantItem* gardenSalad = new SideDishItem(300, "**Harvest Garden Salad**", 7.50,
		"Mixed greens with cucumbers, cherry tomatoes, red onions, and croutons, served with your choice of dressing", 
		"garden", true, "Greek dressing", false);
	RestaurantItem* ceaserSalad = new SideDishItem(200, "**Caesar Supreme Salad**", 9.00,
		"Crisp romaine lettuce, parmesan cheese, and croutons tossed in a creamy Caesar dressing", 
		"ceaser", false, "Thousand Island dressing", false);
	RestaurantItem* greekSalad = new SideDishItem(100, "**Greek Salad**", 10.95,
		"Mixed greens with kalamata olives, feta cheese, red onions, and cucumbers, served with a Greek dressing",
		"greek", true, "Ranch dressing", true);

	// Create some DessertItem objects
	RestaurantItem* chocolateCake = new DessertItem(500, "**Chocolate Lava Cake** ", 7.95,
		"Warm chocolate cake with a molten center, served with vanilla ice cream", "chocolate", false);
	RestaurantItem* cheeseCake = new DessertItem(400, "**Tropical Cheesecake**", 6.95,
		"Creamy cheesecake topped with a mango-pineapple glaze","cheese", true);
	RestaurantItem* tiramisu = new DessertItem(300, "**Tiramisu**", 8.50,
		"Classic Italian dessert with layers of espresso-soaked ladyfingers and mascarpone cheese","tiramisu", false);

	// Create some DrinkItem objects
	RestaurantItem* lemonade = new DrinkItem(1000, "**House Lemonade**", 3.50, 
		"Freshly squeezed lemonade with a hint of mint", "lemonade", false);
	RestaurantItem* tea = new DrinkItem(1001, "**Iced Herbal Tea**", 3.00, 
		"A refreshing blend of herbal tea served over ice","tea", false);
	RestaurantItem* beer = new DrinkItem(1001, "**Craft Beers**", 5.50, 
		"A rotating selection of local craft beers.","beer", true);

	// load all meals to meals list
	cout << "	***Meal items Loading..." << endl;
	menuManager->addNewMeals(
		pasta, chicken, ribEye, 
		gardenSalad, ceaserSalad, greekSalad,
		chocolateCake, cheeseCake, tiramisu);
	
	
	// load all drinks to drinksList
	cout << "	***Drink items loading..." << endl;
	menuManager->addNewDrinks(lemonade, tea, beer);





	// ***   CREATING FOOD MENUS ***   ////////////
	//=======================================
	cout << "\nCreating Menus..." << endl;
	//cout << "============================================" << endl;


	// create entreeMenu
	cout << "	***Entree menu loading..." << endl;
	menuManager->addItemToMenu(chicken, pasta, ribEye);


	// create dessertMenu
	cout << "	***Dessert menu loading..." << endl;
	menuManager->addItemToMenu(chocolateCake, cheeseCake, tiramisu);
	
	// create sideDishMenu
	cout << "	***Sides menu loading..." << endl;
	menuManager->addItemToMenu(gardenSalad, ceaserSalad, greekSalad);

	// create drinksMenu
	cout << "	***Drinks menu loading..." << endl;
	menuManager->addItemToMenu(lemonade, tea, beer);
	cout << "\nDatabase update complete. Menus created." << endl;

	cout << "\n------------------------------------------------------------------------------------------------------------\n" << endl;


	// ***   GET USER CHOICE FOR ADMIN OR CUSTOMER FUNCTIONALITY ***   ////////////
   //=======================================
	/*cout << "Navigation Options" << endl;
	cout << "----------------------------" << endl;*/
	cout << "'A' - Administrator access \n'M' - Menus \n'X' - Exit" << endl;
	string promptLogin = "\nSelect an option: ";
	exitCondition = false;
	char ch = getCharInput(promptLogin, exitCondition);
	ch = toupper(ch);

	if (exitCondition) {
		cout << "Exiting program..." << endl;
		delete menuManager; // Free allocated memory
		return 0;
	}

	while (ch != 'x') {
		// ***   ADMIN FUNCTIONALITY ***   ////////////
		//=============================================
		if (ch == 'A') {
			string adminLogin = "Enter Admin code (minimum three character) to log into the inventory system (or 'x' to exit): ";
			string userName = getStringInput(adminLogin, exitCondition);

			cout << endl;
			if (exitCondition) {
				cout << "Exiting administrator access." << endl;
				break;
			}

			int managerChoice = menuAdmin();

			while (managerChoice != 0) {
				switch (managerChoice) {
				case 1: // Add Meal Items
				{
					cout << "Existing Meals in the Retaurant: " << endl;
					menuManager->displayAllEntrees();
					break;
				}

				case 2: // Add Drink Items
				{
					menuManager->displayAllDrinks();

					break;
				}
				case 3: // View All Invoices
				{
					cout << "Add new meals" << endl;

					RestaurantItem* burger = new MealItem(1, "Burger", 5.99, "A tasty burger", "burger");
					RestaurantItem* fries = new MealItem(2, "Fries", 2.99, "Crispy french fries", "fries");
					RestaurantItem* soda = new MealItem(3, "Soda", 1.50, "Refreshing soda", "soda");
					menuManager->addNewMeals(soda);
					menuManager->addNewMeals(burger, fries);
					menuManager->displayAllEntrees();

					break;
				}
				case 0:
					cout << "Exit" << endl;
					break;

				default:
					cout << "Invalid choice. Please enter a valid option." << endl;
					break;
				}
				managerChoice = menuAdmin();
			}
			cout << "Exiting administrator access." << endl;
		}
		// ***   CUSTOMER FUNCTIONALITY ***   ////////////
		//=============================================
		else if (ch == 'M') {

			string customerLogin = "\nEnter Customer Name (minimum three character) to place an order (or 'x' to exit): ";
			string customerName = getStringInput(customerLogin, exitCondition);
			Customer* customer = new Customer(customerName, menuManager); // Create a Customer object
			cout << endl;
			int customerChoice = menuCustomer();
			//cin.ignore();
			exitCondition = false;

			while (customerChoice != 0) {
				switch (customerChoice) {
				case 1: // View and choose entree
				{

					menuManager->displayEntreeMenu();
					string addEntree = "Select an entree to add to your order (or 'x' to exit): ";
					string entreeChoice = getStringInput(addEntree, exitCondition);
				
					if (exitCondition) {
						break; // Exit the loop if 'x' is chosen
					}
					RestaurantItem* item = customer->getItemByOrderId(entreeChoice);
					if (item) {
						
						cout << endl << item->getName() << " added to your order.\n" << endl;
						customer->addItemToOrder(item);
					}
					else {
						cout << "Item not found in menu." << endl;
					}
					customer->displayOrder();
					break;
				}

				case 2: // View and choose side dish
				{
					menuManager->displaySidesMenu();
					string sideDishChoice;

						string addSideDish = "Select a side dish to add to your order (or 'x' to exit): ";
						sideDishChoice = getStringInput(addSideDish, exitCondition);
				
						if (exitCondition) {
							break; // Exit the loop if 'x' is chosen
						}

						RestaurantItem* item = customer->getItemByOrderId(sideDishChoice);
						if (item) {
							cout << endl << item->getName() << " added to your order.\n" << endl;
							customer->addItemToOrder(item);
						}
						else {
							cout << "Item not found in order." << endl;
						}
						customer->displayOrder();
					break;
				}

				case 3: // View and choose dessert
				{
					menuManager->displayDessertMenu();
					string dessertChoice;

		
						string addDessert = "Select a dessert to add to your order (or 'x' to exit): ";
						dessertChoice = getStringInput(addDessert, exitCondition);

						if (exitCondition) {
							break; // Exit the loop if 'x' is chosen
						}

						RestaurantItem* item = customer->getItemByOrderId(dessertChoice);
						if (item) {
							cout << item->getName() << " added to your order.\n" << endl;
							customer->addItemToOrder(item);
						}
						else {
							cout << "Item not found in order." << endl;
						}
						customer->displayOrder();
				
					break;
				}

				case 4: // View and choose drinks
				{
					menuManager->displayDrinksMenu();
					string drinkChoice;

			
						string addDrink = "Select a drink to add to your order (or 'x' to exit): ";
						drinkChoice = getStringInput(addDrink, exitCondition);

						if (exitCondition) {
							break; // Exit the loop if 'x' is chosen
						}

						RestaurantItem* item = customer->getItemByOrderId(drinkChoice);
						if (item) {
							cout << item->getName() <<" added to your order.\n" << endl;
							customer->addItemToOrder(item);
						}
						else {
							cout << "Item not found in order." << endl;
						}
						customer->displayOrder();
				
					break;
				}

				case 5: 
					cout << "\nInvoice" << endl;
					cout << "--------------------------------------------------------------------------------------------------------" << endl;
					customer->displayOrder();
					customer->getUserInputForTip();
					cout << endl;
					customer->displayInvoice();

					cout << "Order successfully placed. Proceed to checkout...\n" << endl;
					cout << "THANKS FOR VISITING\n" << endl;
					customerChoice = 0;
					break;

				case 0:
					cout << "Exiting customer functionality." << endl;
					break;

				default:
					cout << "Invalid choice. Please enter a valid option." << endl;
					break;
				}
				if (customerChoice != 0) {
					customerChoice = menuCustomer(); // Prompt for the next choice
				}
			}

			delete customer; // Free memory
		}
		// ***   CHECK FOR INVALID INPUT ***   /////////
		//=============================================
		else {
			cout << "\nInvalid option. Please enter 'A' for Administrator access, 'M' for Menus, or 'X' to exit.\n" << endl;
		}

		/*cout << "Navigation Options" << endl;
		cout << "----------------------------" << endl;*/
		cout << "'A' - Administrator access \n'M' - Menus \n'X' - Exit" << endl;
		string promptLogin = "\nSelect an option: ";
		ch = getCharInput(promptLogin, exitCondition);
		ch = toupper(ch);

		if (exitCondition) {
			cout << "Exiting program..." << endl;
			delete menuManager; // Free allocated memory
			return 0;
		}
	}

	delete menuManager; // Free memory
	cout << "Program exited." << endl;
	return 0;

	
}
