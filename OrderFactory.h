#pragma once
#include "Factory.h"
#include "Order.h"
#include "Individual.h"
#include "Menu.h"

#include <vector>
using namespace std;

class Table;
class OrderFactory : public Factory
{
private:
    int current;

public:
    Menu *starterMenu;
    Menu *mainMenu;
    Menu *dessertMenu;
    char nextGroupID;
    vector<Order_ *> getOrder(Table *t);

    OrderFactory();
    ~OrderFactory();
    void createProduct();
};
