/*
    Mediator Object
        - Holds vector of staff objects
            - Just Chefs for now -- Must make CHEF.H inherit from STAFF -- Must add waiters
        
*/

#ifndef KITCHEN_H
#define KITCHEN_H

#include <vector>
class Chef;

class Kitchen
{
    public:
    	void addChef(Chef* newChef);                                    //Add a Chef to its list/vector
        void notifyStateChange(Chef* chef);                             //Notify all chefs that its STATE has changed

    private:
        std::vector<Chef*> listOfChefs;                                 //List of chefs subscribed to Kitchen Mediator
};

#endif