/*
    Dessert Chef Definition File
    - Inherits from Chef class
*/
#ifndef DESSERTCHEF_H
#define DESSERTCHEF_H

#include "Chef.h"
#include "HeadChef.h"
#include "MealBuilder.h"
class Meal;

class DessertChef : public Chef
{
public:
    DessertChef(std::string name, Kitchen *kitchen); // Constructor

    std::string getChefType();
    void receiveOrder();       // Set STATE to FREE to indicate they are able to receive a new order
    void sendOrder();          // IGNORE VIRTUAL
    void sendMeal(Meal *meal); // Send meal object

    // void prepareMeal(std::string mealType);                 //CoR HANDLE method
    void prepareMeal(Order_ *order);
    void setNextChef(Chef *nextChef); // CoR setNext method

    void receiveNotification(Chef *senderChef){};
    void setHeadChef(HeadChef *headChef); // Needs to be declared in MAIN ??

    void receiveNotification(Staff *senderChef);

    HeadChef *headChef;
};

#endif