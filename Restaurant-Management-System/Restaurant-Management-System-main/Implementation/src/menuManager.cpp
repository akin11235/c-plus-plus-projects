#include"MenuManager.h"
#include"RestaurantItem.h"
#include"MealItem.h"
#include"DrinkItem.h"
#include"SideDishItem.h"
#include"DessertItem.h"


LinkedList MenuManager::mealsList; // initialize static meals list

void MenuManager::displayAllEntrees() {
    mealsList.displayList(); 
}

void MenuManager::displayAllDrinks() {
    drinksList.displayList();
}

vector<RestaurantItem*>& MenuManager::getEntreeMenu() {
    return entreeMenu;
}

vector<RestaurantItem*>& MenuManager::getDessertMenu() {
    return dessertMenu;
}

vector<RestaurantItem*>& MenuManager::getSidesMenu() {
    return sidesMenu;
}

vector<RestaurantItem*>& MenuManager::getDrinksMenu() {
    return drinksMenu;
}

void MenuManager::displayEntreeMenu() {
    cout << "\nDisplaying Entree Menu:" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

    if (entreeMenu.empty()) {
        cout << "Entree menu is empty!" << std::endl;
    }
    else
    {
        for (const auto& item : entreeMenu) {
            if (item) {
                item->displayDetails();
                cout << "     ---------------------------------------\n" << endl;
            }
    }
       /* cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << "End of Entree Menu\n" << endl;*/
        
    }
}


void MenuManager::displayDrinksMenu()
{
    cout << "\nDisplaying Drinks Menu:" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    if (drinksMenu.empty()) {
        cout << "Drinks menu is empty!" << std::endl;
    }
    else
    {
        for (const auto& item : drinksMenu) {
            if (item) {
                item->displayDetails();
                cout << "       ---------------------------------------\n" << endl;
            }
        }
    }
}


void MenuManager::displaySidesMenu()
{
    cout << "\nDisplaying Sides Menu:" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    if (sidesMenu.empty()) {
        cout << "Sides menu is empty!" << std::endl;
    }
    else
    {
        for (const auto& item : sidesMenu) {
            if (item) {
                item->displayDetails();
                cout << "       ---------------------------------------\n" << endl;
            }
        }
    }
}
void MenuManager::displayDessertMenu()
{
    cout << "\nDisplaying Desserts Menu:" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    if (dessertMenu.empty()) {
        cout << "Desserts menu is empty!" << std::endl;
    }
    else
    {
        for (const auto& item : dessertMenu) {
            if (item) {
                item->displayDetails();
                cout << "       ---------------------------------------\n" << endl;
            }
        }
    }
}
