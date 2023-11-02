/*
    Chef Implementation File
*/
#ifndef CHEF_CPP
#define CHEF_CPP

#include "Chef.h"

Chef::Chef(std::string name)                                //Constructor
{
    this->name = name;
    this->nextChef = NULL;
}

void Chef::prepareMeal(std::string mealType)                //HANDLE method in CoR
{
    if(nextChef)
    {
        nextChef->prepareMeal(mealType);
    }

    else
    {
        return;                                                 //DEFINE ACTION TO DO IF NO NEXT
    }
}

#endif