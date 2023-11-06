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
        cout << "chef Choice : " << order->getMenuChoice();
        cout << " \nMain Element: " << order->getMainElement();
        cout << " \nmainPrepStrategy:  " << order->getMainPrepStrategy();
        cout << " \nsauceChoice: " << order->getSauceElement();
        cout << " \nsidesChoice: " << order->getSidesElement();
        cout << "\n-side prep strat : " << order->getSidePrepStrategy() << endl;
        cout << endl;
    }
}

void Waiter::receiveBill(Table *table)
{
    table->payTheBill(this);
}
