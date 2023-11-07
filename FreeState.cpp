#ifndef FREESTATE_CPP
#define FREESTATE_CPP

#include "BusyState.h"
#include "FreeState.h"

void FreeState::changeState(Chef* chef)
{
    chef->setChefState(new BusyState());
}

std::string FreeState::getCurrentState()
{
    return "Free";
}

#endif