/*
    Concrete Creator/Factory in FACTORY DP
    - Defines createChef() method for each type of Chef
*/
#ifndef CONCRETECHEFCREATOR_H
#define CONCRETECHEFCREATOR_H

#include "ChefCreator.h"

class HeadChefCreator : public ChefCreator
{
    public:
        HeadChefCreator();
        Chef* createChef(std::string name, Kitchen* kitchen);
};

class StarterChefCreator : public ChefCreator
{
    public:
        StarterChefCreator();
        Chef* createChef(std::string name, Kitchen* kitchen);
};

class MainChefCreator : public ChefCreator
{
    public:
        MainChefCreator();
        Chef* createChef(std::string name, Kitchen* kitchen);
};

class DessertChefCreator : public ChefCreator
{
    public:
        DessertChefCreator();
        Chef* createChef(std::string name, Kitchen* kitchen);
};

#endif