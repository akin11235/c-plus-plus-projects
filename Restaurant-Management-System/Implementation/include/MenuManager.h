#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<string>

#include "RestaurantItem.h"
#include "LinkedList.h"
#include "EntreeItem.h"
#include "MealItem.h"
#include "DrinkItem.h"
#include "DessertItem.h"
#include "SideDishItem.h"


using namespace std;

using std::string;
using std::cout;
using std::cin;


class MenuManager {

public:
    MenuManager(string& nameInput) : managerName(nameInput) {}
    MenuManager(){}


    //=============================================================
    ///////////// ** MANAGES LINKEDLIST OF MENUITEMS ** ///////////
    //=============================================================

    void displayAllEntrees();
    void displayAllDrinks();
    void addNewMeals() {};
    template<typename... Args>
    void addNewMeals(RestaurantItem* first, Args... args);
    void addNewDrinks() {};
    template<typename... Args>
    void addNewDrinks(RestaurantItem* first, Args... args);


    //=============================================================
    ///////////// ** MANAGES ENTREE/DRINKS MENU ** ///////////
    //=============================================================
    vector<RestaurantItem*>& getEntreeMenu();
    vector<RestaurantItem*>& getDrinksMenu();
    vector<RestaurantItem*>& getSidesMenu();
    vector<RestaurantItem*>& getDessertMenu();

    
    void displayEntreeMenu();
    void displaySidesMenu();
    void displayDessertMenu();
    void addItemToMenu() {};

    template<typename... Args>
    void addItemToMenu(RestaurantItem* item, Args... args);
    void displayDrinksMenu();

private:
    string managerName; // login details
    static LinkedList mealsList; // holds all meals
    LinkedList drinksList; // holds all drinks

protected:
    // Editable menus
    vector<RestaurantItem*> entreeMenu;
    vector<RestaurantItem*> drinksMenu;
    vector<RestaurantItem*> dessertMenu;
    vector<RestaurantItem*> sidesMenu;

}; // End of MenuManager Class


// ***   ADD ITEMS TO LinkedList ***   ////////////
//=================================================

// template function to handle different child classes
template<typename... Args>
void MenuManager::addNewMeals(RestaurantItem* first, Args... args) {
    if (first != nullptr) {
        if (dynamic_cast<EntreeItem*>(first)) {
            mealsList.InsertAtStart(first);
            //std::cout << first->getName() << "  added to the meals list." << endl;
        }
        else if (dynamic_cast<DessertItem*>(first)) {
            mealsList.InsertAtStart(first);
            //std::cout << first->getName() << " added to the meals list." << endl;
        }
        else if (dynamic_cast<SideDishItem*>(first)) {
            mealsList.InsertAtStart(first);
            //std::cout << first->getName() << " added to the meals list." << endl;
        }
        else {
            mealsList.InsertAtStart(first);
            //std::cout << first->getName() << " is an unknown type and has been added to the meals list." << std::endl;
        }
        //mealsList.InsertAtStart(first); // Insert the first item
    
    }
    else {
        std::cout << "Restaurant item not found." << std::endl;
    }
    

    // Base case for recursion
    if constexpr (sizeof...(args) > 0) {
        addNewMeals(args...); // Insert the rest of the items
    }
}



template<typename... Args>
void MenuManager::addNewDrinks(RestaurantItem* first, Args... args)
{
    if (first != nullptr)
    {   
        drinksList.InsertAtStart(first); // Insert the first item
        //cout << first->getName() << " added to the Drinks list." << endl;
    }
    else {
        cout << first->getName() << " not found." << std::endl;
    }
    
    addNewDrinks(args...); // Insert the rest of the items
};

template<typename... Args>
void MenuManager::addItemToMenu(RestaurantItem* item, Args... args) {
    if (item != nullptr) {
        if (dynamic_cast<EntreeItem*>(item)) {
            mealsList.searchAndRetrieve(entreeMenu, item);
            //cout << item->getName() << " added to the entree menu.\n";

            addItemToMenu(args...);  // Recursive call with the remaining arguments       
        }

        else if (dynamic_cast<DrinkItem*>(item)) {

            drinksList.searchAndRetrieve(drinksMenu, item);

            //cout << item->getName() << " added to the drinks menu." << endl;
            addItemToMenu(args...);  // Recursive call with the remaining arguments
        }

        else if (dynamic_cast<DessertItem*>(item)) {

            mealsList.searchAndRetrieve(dessertMenu, item);

            //cout << item->getName() << " added to the dessert menu." << endl;
            addItemToMenu(args...);  // Recursive call with the remaining arguments
        }

        else if (dynamic_cast<SideDishItem*>(item)) {

            mealsList.searchAndRetrieve(sidesMenu, item);

            //cout << item->getName() << " added to the sides menu." << endl;
            addItemToMenu(args...);  // Recursive call with the remaining arguments
        }
    }
    else {
        cout << item->getName() << " not found." << std::endl;
    }
    //addItemToEntreeMenu(args...);  // Recursive call with the remaining arguments
}