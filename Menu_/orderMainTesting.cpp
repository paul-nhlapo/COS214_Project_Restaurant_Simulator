#include <iostream>

#include "Chef.h"
#include "ConcreteChefCreator.h"
#include "DessertChef.h"
#include "HeadChef.h"
#include "MainChef.h"
#include "StarterChef.h"
#include "Kitchen.h"
#include "SimpleOrder.h"
#include "StarterOrder.h"
#include "MainOrder.h"
#include "DessertOrder.h"

#include "Menu.h"
#include "StarterMenu.h"
#include "MainMenu.h"
#include "DessertMenu.h"

#include "Staff.h"
#include "Waiter.h"

#include "Order.h"
#include "OrderBuilder.h"
#include "StarterOrderBuilder.h"
#include "MainOrderBuilder.h"
#include "DessertOrderBuilder.h"



using namespace std;

int main()
{
    //Testing Menu and Order
    
    Waiter* waiter1 = new Waiter();

    waiter1->takeOrder();
    waiter1->printOrders();

    delete waiter1;
    return 0;
}