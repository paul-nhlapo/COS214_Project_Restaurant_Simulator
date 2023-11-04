/*
    Starter Chef Definition File
    - Inherits from Chef class
*/
#ifndef STARTERCHEF_H
#define STARTERCHEF_H

#include "Chef.h"

class StarterChef : public Chef
{
    public:
        StarterChef(std::string name, Kitchen* kitchen);

        std::string getChefType();
        void receiveOrder();                                    //Set STATE to FREE to indicate they are able to receive a new order
        void sendOrder();                                       //Send order to Head Chef to plate IF Head Chef's STATE is FREE

        //void prepareMeal(std::string mealType);                 //CoR HANDLE method
        void prepareMeal(Order* order);
        void setNextChef(Chef* nextChef);                       //CoR setNext method


        void receiveNotification(Chef* senderChef) {};
};

#endif