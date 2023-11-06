/*
    Chef Implementation File
*/
#ifndef CHEF_CPP
#define CHEF_CPP

#include "Chef.h"
#include "ChefState.h"
#include "FreeState.h"
#include "BusyState.h"
#include "Kitchen.h"

Chef::Chef(std::string name, Kitchen* kitchen)                                //Constructor
{
    this->name = name;
    this->nextChef = NULL;
    currentState = new FreeState();
    this->kitchen = kitchen;
    this->kitchen->addStaff(this);
}

/*
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
*/

void Chef::prepareMeal(Order_* order)                            //HANDLE method in CoR
{
    if(nextChef)
    {
        nextChef->prepareMeal(order);
    }

    else
    {
        return;                                                 //DEFINE ACTION TO DO IF NO NEXT
    }
}

void Chef::setChefState(ChefState* chefState)                   //Set new chef state
{
    delete this->currentState;
    this->currentState = chefState;
}

void Chef::changeChefState()                                    //Allows Chef to change their state
{
    currentState->changeState(this);
    //kitchen->notifyStateChange(this);                           //Tells Kitchen (MEDIATOR) that it has changed its State
}   

std::string Chef::getCurrentState()                             //Returns Chef's State as a String
{
    return currentState->getCurrentState();
}

#endif