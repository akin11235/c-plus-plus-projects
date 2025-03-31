#pragma once

#include "RestaurantItem.h"


class DrinkItem : public RestaurantItem {
private:

    bool isAlcoholic = false;
    string size;

public:
    DrinkItem(int idInput, string nameInput, float priceInput, 
        string descInput, string orderID, bool alcoholInput);

    void displayDetails() const override;

    string getSize() const;
    void setSize(const string& sizeInput);

    string getAlcoholContent() const;
    void setAlcoholicContent(bool AlcoholInput);
};

