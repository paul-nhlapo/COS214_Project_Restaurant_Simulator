/*
    Main Chef Definition File
    - Inherits from Chef class
*/
#ifndef MAINCHEF_H
#define MAINCHEF_H

#include "Chef.h"

class MainChef : public Chef
{
    public:
        MainChef(std::string name);

        std::string getChefType();
        void receiveOrder();                                    //Set STATE to FREE to indicate they are able to receive a new order
        void sendOrder();                                       //Send order to Head Chef to plate IF Head Chef's STATE is FREE

        void prepareMeal(std::string mealType);                 //CoR HANDLE method
        void setNextChef(Chef* nextChef);                       //CoR setNext method
};

#endif