/*
    Head Chef Definition File
    - Inherits from Chef class
*/
#ifndef HEADCHEF_H
#define HEADCHEF_H

#include <queue>
#include "Chef.h"

class HeadChef : public Chef
{
    public:
        HeadChef(std::string name);

        std::string getChefType();
        void receiveOrder();                                    //Set STATE to FREE to indicate they are able to receive a new order
        void sendOrder();                                     //Send order to Head Chef to plate IF Head Chef's STATE is FREE
        //void addOrderToQueue(Order* order);                   //Head Chef pushes new orders to queues

        void prepareMeal(std::string mealType);                 //CoR HANDLE method
        void setNextChef(Chef* nextChef);                       //CoR setNext method
/*
        Order* popStarterQueue();
        Order* popMainQueue();
        Order* popDessertQueue();

    private:
        //Queues to hold different Orders
        std::queue<MealType> starterQueue;                      
        std::queue<MealType> mainQueue;
        std::queue<MealType> dessertQueue;
*/
};

#endif