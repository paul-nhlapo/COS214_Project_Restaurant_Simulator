#ifndef WAITER_H
#define WAITER_H

#include "Staff.h"
#include "Table.h"
#include "Order.h"
#include "Menu.h"
#include "StarterMenu.h"
#include "MainMenu.h"
#include "DessertMenu.h"
#include "MealProduct.h"
// #include "Chef.h"
#include "OrderBuilder.h"
#include "StarterOrderBuilder.h"
#include "MainOrderBuilder.h"
#include "DessertOrderBuilder.h"

class Chef;
class Waiter : public Staff
{

public:
    vector<Table *> tables;
    vector<Order_ *> orders;
    double balance;

    Waiter();
    void process(Table *t);
    void visitTable(Table *table);
    void visitAllTable(std::vector<Table *>);
    void printOrders();
    void receiveBill(Table *table);
    void receiveNotification(Staff *senderChef){};
    void sendOrders(Chef *headChef);
    void deliverMeal(Meal *m);

private:
};
#endif