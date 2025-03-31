#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<iomanip>

#include "Customer.h"
#include "RestaurantItem.h"
#include "LinkedList.h"
#include "EntreeItem.h"
#include "MealItem.h"
#include"DrinkItem.h"
#include"MenuManager.h"

using std::string;
using std::cout;
using std::cin;


const int NAMEWIDTH = 30; 
const int PRICEWIDTH = 0;


// Definition of the static data member
multimap<std::string, RestaurantItem*> Customer::customerOrder;

float Customer::totalPrice;
int Customer::lastCustomerID = 0;  // Initialize the static member

int Customer::generateCustomerID() {
    return ++lastCustomerID;  // Increment and return the new ID
}

Customer::Customer(const string& nameInput, MenuManager* menuManager, double tax)
    : customerName(nameInput),
    customerID(generateCustomerID()),
    taxRate(tax),
    tipAmount(0.0),
    menuManager(menuManager)
{}

void Customer::addItemToOrder(RestaurantItem* item) {
    bool itemFound = false;

    // Search for the item in the appropriate menu
    if (dynamic_cast<EntreeItem*>(item)) {
        itemFound = searchMenu(menuManager->getEntreeMenu(), item);
        if (itemFound) {
            customerOrder.insert({ item->getName(), item }); // Add to order
            totalPrice = calculateTotalPrice();  // Update total price
        }
        else {
            cout << item->getName() << " not found in the entree menu.\n";
        }
    }
    else if (dynamic_cast<DessertItem*>(item)) {
        itemFound = searchMenu(menuManager->getDessertMenu(), item);
        if (itemFound) {
            customerOrder.insert({ item->getName(), item }); // Add to order
            totalPrice = calculateTotalPrice();  // Update total price
        }
        else {
            cout << item->getName() << " not found in the dessert menu.\n";
        }
    }
    else if (dynamic_cast<SideDishItem*>(item)) {
        itemFound = searchMenu(menuManager->getSidesMenu(), item);
        if (itemFound) { 
            customerOrder.insert({ item->getName(), item }); // Add to order
            totalPrice = calculateTotalPrice();  // Update total price
        }
        else {
            cout << item->getName() << " not found in the sides menu.\n";
        }
    }
    else if (dynamic_cast<DrinkItem*>(item)) {
        itemFound = searchMenu(menuManager->getDrinksMenu(), item);
        if (itemFound) {
             
            customerOrder.insert({ item->getName(), item }); // Add to order
            totalPrice = calculateTotalPrice();  // Update total price
        }
        else {
            cout << item->getName() << " not found in the drinks menu.\n";
        }
    }
    else {
        std::cout << "Restaurant item not found." << std::endl;
    }
}


bool Customer::searchMenu(const std::vector<RestaurantItem*>& vec, RestaurantItem* item) {
    for (auto& menuItem : vec) {
        if (menuItem == item) {
            return true;  // Item found in the menu
        }
    }
    return false;  // Item not found in the menu
}

void Customer::displayOrder() {
    double subtotal = calculateTotalPrice();
    double taxAmount = subtotal * taxRate;
    double total = subtotal + taxAmount;

    cout << left << setw(NAMEWIDTH - 12) << ("Customer: " + customerName)
        << right << setw(PRICEWIDTH) << ("Order ID: " + to_string(customerID)) << endl <<endl << endl;

    // Header
    cout << "\t" << left << setw(NAMEWIDTH) << "Item Name"
        << right << setw(PRICEWIDTH) << "Price" << endl;

    // Separator
    cout << "\t" << setfill('-') << setw(NAMEWIDTH + PRICEWIDTH + 6) << "" << setfill(' ') << endl;

    // Order items
    for (const auto& pair : customerOrder) {
        cout << "\t" << left << setw(NAMEWIDTH) << pair.second->getName()
            << right << setw(PRICEWIDTH) << fixed << setprecision(2) << "$" << pair.second->getPrice() << endl;
    }

    if (customerOrder.empty()) {
        cout << "\tYour order is empty." << endl;
    }
 
    // Separator 
    cout << "\t" << setfill('-') << setw(NAMEWIDTH + PRICEWIDTH + 6) << "" << setfill(' ') << endl;

    // Subtotal
    cout << "\t" << left << setw(NAMEWIDTH) << "Subtotal:"
        << right << setw(PRICEWIDTH) << fixed << setprecision(2) << "$" << subtotal << endl;

    // Tax
    cout << "\t" << left << setw(NAMEWIDTH) << "Tax (13%):"
        << right << setw(PRICEWIDTH) << fixed << setprecision(2) << "$" << taxAmount << endl;

    // Separator 
    cout << "\t" << setfill('-') << setw(NAMEWIDTH + PRICEWIDTH + 6) << "" << setfill(' ') << endl;

    // Total
    cout << "\t" << left << setw(NAMEWIDTH) << "Total:"
        << right << setw(PRICEWIDTH) << fixed << setprecision(2) << "$" << total << endl;

    // Final separator
    cout << "\t" << setfill('-') << setw(NAMEWIDTH + PRICEWIDTH + 6) << "" << setfill(' ') << endl;
 

    cout << endl;
}


void Customer::displayInvoice() {

    displayOrder();
    double subtotal = calculateTotalPrice();
    double taxAmount = subtotal * taxRate;
    double total = subtotal + taxAmount + tipAmount;
    cout << endl;

    // Total
    cout << "\t" << left << setw(NAMEWIDTH) << "Tip:"
        << right << setw(PRICEWIDTH) << fixed << setprecision(2) << "$" << tipAmount << endl;

    // Total
    cout << "\t" << left << setw(NAMEWIDTH) << "Total:"
        << right << setw(PRICEWIDTH) << fixed << setprecision(2) << "$" << total << endl;

    // Final separator
    cout << "\t" << setfill('-') << setw(NAMEWIDTH + PRICEWIDTH + 6) << "" << setfill(' ') << endl;

    cout << endl;
}


RestaurantItem* Customer::getItemByOrderId(const string& orderId) {
    vector<vector<RestaurantItem*>> allMenus = {
        menuManager->getEntreeMenu(),
        menuManager->getDessertMenu(),
        menuManager->getSidesMenu(),
        menuManager->getDrinksMenu()
    };

    for (auto& menu : allMenus) {
        for (auto& item : menu) {
            if (item->getOrderCode() == orderId) {
                return item;
            }
        }
    }

    return nullptr; // Return nullptr if the item is not found
}

double Customer::calculateTotalPrice() const {
    double totalPrice = 0.0;
    for (const auto& pair : customerOrder) {
        totalPrice += pair.second->getPrice();
    }
    return totalPrice;
}

double Customer::getTipAmount() { return tipAmount; }

void Customer::setTipAmount(double amount) {
    tipAmount = amount;
}

void Customer::getUserInputForTip() {
    double tipAmount;
    cout << "Enter tip amount: $";
    cin >> tipAmount;
    setTipAmount(tipAmount);
}

double Customer::calculateTipAmount() const {
    return tipAmount;
}