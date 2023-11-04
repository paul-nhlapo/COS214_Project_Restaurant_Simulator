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


using namespace std;

int main()
{
    
    Kitchen* kitchen = new Kitchen();
    
    //******** Factory DP Testing ********//

    std::cout << "***** Testing Factory DP *****" << std::endl;

    //Create Chef Factories
    std::cout << "*** Creating Chef Factories ***" << std::endl;
    ChefCreator* headChefCreator = new HeadChefCreator();
    ChefCreator* starterChefCreator = new StarterChefCreator();
    ChefCreator* mainChefCreator = new MainChefCreator();
    ChefCreator* dessertChefCreator = new DessertChefCreator();
    std::cout << "*** Chef Factories Created ***" << std::endl << std::endl;

    //Create individual Chefs
    std::cout << "*** Creating Concrete Chefs ***" << std::endl;
    Chef* headChef = headChefCreator->createChef("Head Chef", kitchen);
    Chef* starterChef = starterChefCreator->createChef("Starter Chef", kitchen);
    Chef* mainChef = mainChefCreator->createChef("Main Chef", kitchen);
    Chef* dessertChef = dessertChefCreator->createChef("Dessert Chef", kitchen);
    std::cout << "*** Concrete Chefs Created ***" << std::endl << std::endl;

    std::cout << std::endl;

    //******** State DP Testing ********//

    std::cout << "***** Testing State DP *****" << std::endl;

    //Get Starting State
    std::cout << "*** Print Initial States: ***" << std::endl;
    std::cout << headChef->getChefType() << "'s Current State is: " << headChef->getCurrentState() << std::endl;
    std::cout << starterChef->getChefType() << "'s Current State is: " << starterChef->getCurrentState() << std::endl;
    std::cout << mainChef->getChefType() << "'s Current State is: " << mainChef->getCurrentState() << std::endl;
    std::cout << dessertChef->getChefType() << "'s Current State is: " << dessertChef->getCurrentState() << std::endl;

    std::cout << std::endl;

    //Change State from Free to Busy

    std::cout << "*** Changing States From Free to Busy: ***" << std::endl;
    headChef->changeChefState();
    starterChef->changeChefState();
    mainChef->changeChefState();
    dessertChef->changeChefState();

    std::cout << headChef->getChefType() << "'s Current State is: " << headChef->getCurrentState() << std::endl;
    std::cout << starterChef->getChefType() << "'s Current State is: " << starterChef->getCurrentState() << std::endl;
    std::cout << mainChef->getChefType() << "'s Current State is: " << mainChef->getCurrentState() << std::endl;
    std::cout << dessertChef->getChefType() << "'s Current State is: " << dessertChef->getCurrentState() << std::endl;

    std::cout << std::endl;

    std::cout << "*** Changing States From Busy to Free: ***" << std::endl;
    headChef->changeChefState();
    starterChef->changeChefState();
    mainChef->changeChefState();
    dessertChef->changeChefState();

    std::cout << headChef->getChefType() << "'s Current State is: " << headChef->getCurrentState() << std::endl;
    std::cout << starterChef->getChefType() << "'s Current State is: " << starterChef->getCurrentState() << std::endl;
    std::cout << mainChef->getChefType() << "'s Current State is: " << mainChef->getCurrentState() << std::endl;
    std::cout << dessertChef->getChefType() << "'s Current State is: " << dessertChef->getCurrentState() << std::endl;

    //******** CoR DP Testing ********//

    std::cout << "***** Testing CoR DP *****" << std::endl;

    //Set next Chef in CoR
    headChef->setNextChef(starterChef);
    starterChef->setNextChef(mainChef);
    mainChef->setNextChef(dessertChef);

    Order* order1 = new StarterOrder("Sushi", "Sushi", "Wasabi", "Soy Sauce");
    headChef->addOrderToQueue(order1);

    Order* order2 = new DessertOrder("Ice Cream", "Cold Dessert", "", "Chocolate");
    headChef->addOrderToQueue(order2);

    Order* order3 = new MainOrder("Steak", "Grill", "Roasted Potatoes", "Mushroom Sauce");  
    headChef->addOrderToQueue(order3);



    //Meal to prepare - Passes through Chain
    headChef->prepareMeal(order1);

    std::cout << std::endl;

    headChef->prepareMeal(order2);

    std::cout << std::endl;

    headChef->prepareMeal(order3);

    delete order3;
    delete order2;
    delete order1;

    delete dessertChef;
    delete mainChef;
    delete starterChef;
    delete headChef;

    delete dessertChefCreator;
    delete mainChefCreator;
    delete starterChefCreator;
    delete headChefCreator;

    delete kitchen;

    return 0;
}