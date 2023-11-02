#include <iostream>
#include <memory>

#include "Chef.h"
#include "ConcreteChefCreator.h"
#include "DessertChef.h"
#include "HeadChef.h"
#include "MainChef.h"
#include "StarterChef.h"

using namespace std;

int main()
{

    //Create Chef Factories
    ChefCreator* headChefCreator = new HeadChefCreator();
    ChefCreator* starterChefCreator = new StarterChefCreator();
    ChefCreator* mainChefCreator = new MainChefCreator();
    ChefCreator* dessertChefCreator = new DessertChefCreator();

    //Create individual Chefs
    Chef* headChef = headChefCreator->createChef("Head Chef");
    Chef* starterChef = starterChefCreator->createChef("Starter Chef");
    Chef* mainChef = mainChefCreator->createChef("Main Chef");
    Chef* dessertChef = dessertChefCreator->createChef("Dessert Chef");

    std::cout << std::endl;

    // Chef* headChef = new HeadChef("Main Chef");
    // Chef* starterChef = new StarterChef("Starter Chef");
    // Chef* mainChef = new MainChef("Main Chef");
    // Chef* dessertChef = new DessertChef("Dessert Chef");

    //Set next Chef in CoR
    headChef->setNextChef(starterChef);
    starterChef->setNextChef(mainChef);
    mainChef->setNextChef(dessertChef);


    //Meal to prepare - Passes through Chain
    headChef->prepareMeal("Dessert");

    std::cout << std::endl;

    delete dessertChef;
    delete mainChef;
    delete starterChef;
    delete headChef;

    delete dessertChefCreator;
    delete mainChefCreator;
    delete starterChefCreator;
    delete headChefCreator;

    return 0;
}