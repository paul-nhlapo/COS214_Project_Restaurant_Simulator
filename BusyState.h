#ifndef BUSYSTATE_H
#define BUSYSTATE_H

#include "ChefState.h"
#include "Chef.h"

class BusyState : public ChefState
{
    public:
        void changeState(Chef* chef);
        std::string getCurrentState();
};

#endif