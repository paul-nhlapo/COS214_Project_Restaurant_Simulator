#ifndef KITCHEN_CPP
#define KITCHEN_CPP

#include "Kitchen.h"
#include "Chef.h"

void Kitchen::addStaff(Staff* newStaff)
{
    listOfStaff.push_back(newStaff);
}

void Kitchen::notifyStateChange(Staff* chef)
{
    for(int i = 0; i < listOfStaff.size(); i++)
    {
        if(listOfStaff[i] != chef)
        {
            listOfStaff[i]->receiveNotification(chef);
        }
    }
}



void Kitchen::sendToKitchen(Order_* order, Chef* headChef){
    headChef->addOrderToQueue(order);
}


#endif