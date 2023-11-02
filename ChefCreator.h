/*
    Creator/Factory Interface in FACTORY DP
*/
#ifndef CHEFCREATOR_H
#define CHEFCREATOR_H

#include "Chef.h"

class ChefCreator
{
    public:
        virtual Chef* createChef(std::string name) = 0;             //Abstract Method to create new Chef
};

#endif