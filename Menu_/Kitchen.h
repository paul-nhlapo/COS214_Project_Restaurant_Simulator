/*
    Mediator Object
        - Holds vector of staff objects
            - Just Chefs for now -- Must make CHEF.H inherit from STAFF -- Must add waiters
        
*/

#ifndef KITCHEN_H
#define KITCHEN_H

#include <vector>
class Staff;
class Chef;

class Kitchen
{
    public:
    	void addStaff(Staff* newStaff);                                    //Add a Chef to its list/vector
        void notifyStateChange(Staff* staff);                             //Notify all chefs that its STATE has changed
        void sendToKitchen(Order_* order , Chef* headChef);

    private:
        std::vector<Staff*> listOfStaff;                                 //List of chefs subscribed to Kitchen Mediator
};

#endif