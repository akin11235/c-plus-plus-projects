#pragma once

#include "MealItem.h"
#include "RestaurantItem.h"


class EntreeItem : public MealItem {
    bool isVegetarian;
    bool isSpicy;

public:
    EntreeItem(int idInput, string nameInput, float priceInput,
        string descInput, string orderID, bool isVegInput);

    void displayDetails() const override;
};
