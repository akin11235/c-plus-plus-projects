#pragma once

#include<iostream>
#include"RestaurantItem.h"
#include"Node.h"
#include"MealItem.h"
#include"DrinkItem.h"
#include<vector>

using namespace std;


//basic operation: insert, search, display, update and delete

class LinkedList
{
private:

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void InsertAtStart(int idInput, string nameInput, float priceInput,
        string& descInput, string orderID);

    void InsertAtStart(RestaurantItem* menuItem);
    void displayList() const;
    void InsertAtMiddle(int pos, RestaurantItem* value);
    Node* searchList(RestaurantItem* value);
    Node* searchList(int id); //searches for a node by its ID and returns a pointer to the node if found.
    int searchCount(RestaurantItem* value);
    void updateElement(RestaurantItem* old_data, RestaurantItem* new_data);
    void deleteNode(RestaurantItem* value);


    // Function to search the list, retrieve items based on a condition, and store them in a vector
    void searchAndRetrieve(vector<RestaurantItem*>& vec, RestaurantItem* value);
};