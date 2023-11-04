/*
    Concrete Creator/Factory Implementation in FACTORY DP
    - Implements createChef method for each type of Chef
*/
#ifndef CONCRETECHEFCREATOR_CPP
#define CONCRETECHEFCREATOR_CPP

#include "ConcreteChefCreator.h"
#include "HeadChef.h"
#include "StarterChef.h"
#include "MainChef.h"
#include "DessertChef.h"

HeadChefCreator::HeadChefCreator()
{}

Chef* HeadChefCreator::createChef(std::string name, Kitchen* kitchen)
{
    Chef* headChef = new HeadChef("Head Chef", kitchen);                                     //Creates Head Chef Objects
    std::cout << "Head Chef Created" << std::endl;                                  //Just for testing/visualisation
    return headChef;
}

StarterChefCreator::StarterChefCreator()
{}

Chef* StarterChefCreator::createChef(std::string name, Kitchen* kitchen)
{
    Chef* starterChef = new StarterChef("StarterChef", kitchen);
    std::cout << "Starter Chef Created" << std::endl;
    return starterChef;
}

MainChefCreator::MainChefCreator()
{}

Chef* MainChefCreator::createChef(std::string name, Kitchen* kitchen)
{
    Chef* mainChef = new MainChef("MainChef", kitchen);
    std::cout << "Main Chef Created" << std::endl;
    return mainChef;
}

DessertChefCreator::DessertChefCreator()
{}

Chef* DessertChefCreator::createChef(std::string name, Kitchen* kitchen)
{
    Chef* dessertChef = new DessertChef("DessertChef", kitchen);
    std::cout << "Dessert Chef Created" << std::endl;
    return dessertChef; 
}

#endif