#ifndef CHEFSTATE_H
#define CHEFSTATE_H
#include <iostream>

class Chef;


class ChefState
{
    public:
        virtual void changeState(Chef* chef) = 0;
        virtual std::string getCurrentState() = 0;
        virtual ~ChefState() {};
};

#endif