#ifndef KITCHEN_CPP
#define KITCHEN_CPP

#include "Kitchen.h"
#include "Chef.h"

void Kitchen::addChef(Chef* newChef)
{
    listOfChefs.push_back(newChef);
}

void Kitchen::notifyStateChange(Chef* chef)
{
    for(int i = 0; i < listOfChefs.size(); i++)
    {
        if(listOfChefs[i] != chef)
        {
            listOfChefs[i]->receiveNotification(chef);
        }
    }
}

#endif