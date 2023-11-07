#ifndef BUSYSTATE_CPP
#define BUSYSTATE_CPP

#include "BusyState.h"
#include "FreeState.h"

void BusyState::changeState(Chef* chef)
{
    chef->setChefState(new FreeState());
}

std::string BusyState::getCurrentState()
{
    return "Busy";
}

#endif