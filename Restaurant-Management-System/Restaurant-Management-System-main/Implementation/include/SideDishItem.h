#pragma once

#include "RestaurantItem.h"
#include "MealItem.h"

class SideDishItem : public MealItem {
    bool isShareable;
    string dressing;
    bool isGlutenFree;

public:
    SideDishItem(int idInput, string nameInput, float priceInput,
        string descInput, string orderID, bool isShareableInput, string dressingInput, bool glutenInput);

    void displayDetails() const override;
};