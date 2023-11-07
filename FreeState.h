#ifndef FREESTATE_H
#define FREESTATE_H

#include "ChefState.h"
#include "Chef.h"

class FreeState : public ChefState
{
    public:
        void changeState(Chef* chef);
        std::string getCurrentState();

};

#endif