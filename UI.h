#pragma once
#include "Command.h"
#include "concreteCommand.h"
#include "customerFactory.h"
#include "Customer.h"
#include "Factory.h"
#include "Staff.h"
#include "maitreD.h"
#include "Waiter.h"
#include "Floor.h"
#include "OrderFactory.h"
#include "Bartender.h"
#include "Order.h"
#include "OrderDetail.h"
#include "AddOn.h"
#include "Cocktail.h"
#include "CocktailMixer.h"
#include "Builder.h"
#include "Base.h"
#include "Type.h"
#include "Ice.h"
#include "Fruit.h"
#include "Bar.h"
#include "Chef.h"
#include "ConcreteChefCreator.h"
#include "DessertChef.h"
#include "HeadChef.h"
#include "MainChef.h"
#include "StarterChef.h"
#include "Kitchen.h"
using namespace std;

class UI
{
private:
    concreteCommand *c1;
    Floor *mainFloor;
    maitreD *md;
    CocktailMixer *cm1;
    Bartender *b1;
    Bar *bar_;

public:
    UI(concreteCommand *c, Floor *f);
    ~UI();
    void addCustomer();
    void order();
    void additionLoop();
};
