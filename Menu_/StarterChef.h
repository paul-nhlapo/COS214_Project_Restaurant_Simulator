/*
    Starter Chef Definition File
    - Inherits from Chef class
*/
#ifndef STARTERCHEF_H
#define STARTERCHEF_H

#include "Chef.h"
#include "HeadChef.h"
#include "MealBuilder.h"
class Meal;

class StarterChef : public Chef
{
public:
    StarterChef(std::string name, Kitchen *kitchen);

    std::string getChefType();
    void receiveOrder();       // Set STATE to FREE to indicate they are able to receive a new order
    void sendOrder();          // IGNORE VIRTUAL
    void sendMeal(Meal *meal); // Send meal object

    // void prepareMeal(std::string mealType);               //CoR HANDLE method
    void prepareMeal(Order_ *order);
    void setNextChef(Chef *nextChef); // CoR setNext method

    void receiveNotification(Chef *senderChef){};
    void setHeadChef(HeadChef *headChef); // Needs to be declared in MAIN ??

    void receiveNotification(Staff *senderChef);

    HeadChef *headChef;
};

#endif