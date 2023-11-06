/*
    Head Chef Definition File
    - Inherits from Chef class
*/
#ifndef HEADCHEF_H
#define HEADCHEF_H

#include <queue>
#include "Chef.h"
class Meal;

class HeadChef : public Chef
{
public:
    HeadChef(std::string name, Kitchen *kitchen);

    std::string getChefType();
    void receiveOrder(){};               // Set STATE to FREE to indicate they are able to receive a new order
    void sendOrder();                    // Send order to Head Chef to plate IF Head Chef's STATE is FREE
    void addOrderToQueue(Order_ *order); // Head Chef pushes new orders to queues

    void receiveMeal(Meal *meal); // Receieves Meal Object

    // void prepareMeal(std::string mealType);               //CoR HANDLE method
    void prepareMeal(Order_ *order);
    void setNextChef(Chef *nextChef); // CoR setNext method
    Chef* getNextChef();

    void receiveNotification(Chef *senderChef);
    void receiveNotification(Staff *senderChef);

    Order_ *popStarterQueue();
    Order_ *popMainQueue();
    Order_ *popDessertQueue();

private:
    // Queues to hold different Orders
    std::queue<Order_ *> starterQueue;
    std::queue<Order_ *> mainQueue;
    std::queue<Order_ *> dessertQueue;

    // Vectors to hold different meals
    std::vector<Meal*>* starterMeals;
    std::vector<Meal *> mainMeals;
    std::vector<Meal *> dessertMeals;
};
#endif