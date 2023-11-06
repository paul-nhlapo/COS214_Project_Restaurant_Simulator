#pragma once
#include "Staff.h"
// #include "Table.h"
#include <vector>
#include <iostream>
// class Table;

#include "Order.h"
#include "Menu.h"
#include "StarterMenu.h"
#include "MainMenu.h"
#include "DessertMenu.h"

#include "OrderBuilder.h"
#include "StarterOrderBuilder.h"
#include "MainOrderBuilder.h"
#include "DessertOrderBuilder.h"

class Waiter : public Staff
{
    private:
        /* data */
    public:
        Waiter(/* args */);
        ~Waiter();

        void process(Table *t);
        void printOrders();
        
        void addOrder(Order_* order);
        void takeOrder();

        void receiveNotification(Staff* senderChef) {};

        // vector<Table *> tables;
        std::vector<Order_*> orders;
        int income;
        Menu* starterMenu;
        Menu* mainMenu;
        Menu* dessertMenu;
};
