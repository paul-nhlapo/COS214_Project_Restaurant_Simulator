#include "Waiter.h"
#include <iostream>

Waiter::Waiter()
{
    this->balance = 0.0;
}

void Waiter::process(Table *t)
{
}

void Waiter::visitTable(Table *table)
{
    std::cout << "taking order at table : " << table->tableID << "\n";
    this->orders = table->order;
}

void Waiter::visitAllTable(std::vector<Table *> table)
{
    std::cout << "floor waiter cant visit all tables, not a head waiter\n";
}

void Waiter::printOrders()
{
    cout << "Waiter's orders:" << endl;
    for (Order_ *order : orders)
    {
        cout << "Main Element: " << order->getMainElement() << " mainPrepStrategy:  " << order->mainPrepStrategy << " mainPrepStrategy string:  " << order->getMainPrepStrategy() << " sauceChoice: " << order->sauceElement << " sidesChoice: " << order->sidesElement << endl;
    }
}

void Waiter::deliverMeal(Meal *m)
{
    std::cout << "\nWaiter says that your meal: \n";
    std::cout << " - " << m->getMealType() << " " << m->getMainElement() << ", ";
    std::cout << "Prepeared by " << m->getMainPrepStrategy() << "\n";
    if (m->getSidesElement() != "")
    {
        std::cout << " - With side " << m->getSidesElement() << ", ";
        std::cout << "Prepeared by " << m->getSidePrepStrategy() << "\n";
    }
    if (m->getSauceElement() != "")
        std::cout << " - With sauce " << m->getSauceElement() << "\n";

    std::cout << "Is ready\n";
}

void Waiter::receiveBill(Table *table)
{
    table->payTheBill(this);
}
