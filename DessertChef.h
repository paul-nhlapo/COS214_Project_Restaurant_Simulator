/*
    Dessert Chef Definition File
    - Inherits from Chef class
*/
#ifndef DESSERTCHEF_H
#define DESSERTCHEF_H

#include "Chef.h"

class DessertChef : public Chef
{
    public:
        DessertChef(std::string name);                          //Constructor

        std::string getChefType();
        void receiveOrder();                                    //Set STATE to FREE to indicate they are able to receive a new order
        void sendOrder();                                       //Send order to Head Chef to plate IF Head Chef's STATE is FREE

        void prepareMeal(std::string mealType);                 //CoR HANDLE method
        void setNextChef(Chef* nextChef);                       //CoR setNext method
};

#endif