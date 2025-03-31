#pragma once

#include "MealItem.h"
#include "RestaurantItem.h"
#include "MealItem.h"


class DessertItem : public MealItem {
    bool containsNuts;

public:
    DessertItem(int idInput, string nameInput, float priceInput, 
        string descInput, string orderID, bool nutsInput);

    void displayDetails() const override;

};

