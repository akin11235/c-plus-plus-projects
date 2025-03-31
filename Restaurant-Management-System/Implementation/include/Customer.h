#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<string>

#include "RestaurantItem.h"
#include "LinkedList.h"
#include "EntreeItem.h"
#include "MealItem.h"
#include"DrinkItem.h"
#include"MenuManager.h"

using std::string;
using std::cout;
using std::cin;


class Customer : protected MenuManager {

public:

    Customer(const string& nameInput, MenuManager* menuManager, double tax=0.13);

    bool searchMenu(const vector<RestaurantItem*>& vec, RestaurantItem* item);

    void displayOrder();
    void displayInvoice();

    void addItemToOrder(RestaurantItem* item);
    RestaurantItem* getItemByOrderId(const string& orderId);

    double calculateTotalPrice() const;
    double getTipAmount();
    void setTipAmount(double amount);
    void getUserInputForTip();
    double calculateTipAmount() const;

    int getCustomerID() const { return customerID; }
    int generateCustomerID();  // Function to auto-generate ID

private:
    string customerName;
    int customerID;
    static int lastCustomerID;  // Static member to keep track of the last generated ID
    static float totalPrice;
    double taxRate;
    double tipAmount;
    static multimap<string, RestaurantItem*> customerOrder;
    MenuManager* menuManager;  // Composition
};

