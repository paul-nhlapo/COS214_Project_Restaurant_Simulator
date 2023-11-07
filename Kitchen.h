/*
    Mediator Object
        - Holds vector of staff objects
            - Just Chefs for now -- Must make CHEF.H inherit from STAFF -- Must add waiters

*/

#ifndef KITCHEN_H
#define KITCHEN_H

#include <vector>
#include "MealProduct.h"
#include "Waiter.h"
class Staff;
class Chef;
class Order_;

class Kitchen
{
public:
    void addStaff(Staff *newStaff);       // Add a Chef to its list/vector
    void notifyStateChange(Staff *staff); // Notify all chefs that its STATE has changed
    void sendToKitchen(Order_ *order, Chef *headChef);
    void notifyMealReady(Meal *m);
    std::vector<Staff *> listOfStaff; // List of chefs subscribed to Kitchen Mediator

private:
};

#endif