#pragma once

#include "RestaurantItem.h"

class Node : public RestaurantItem {

public:
    Node* next;
    RestaurantItem* data;

    Node(int id, const string& name, float price,
        string& descInput, string orderID);


    Node(RestaurantItem* menuItem);

    virtual ~Node();  // Virtual destructor

    void displayDetails() const override;
};
