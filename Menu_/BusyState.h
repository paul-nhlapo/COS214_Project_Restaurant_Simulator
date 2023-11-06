#ifndef BUSYSTATE_H
#define BUSYSTATE_H

#include "ChefState.h"
#include "Chef.h"

/**
 * @class BusyState
 * @brief A class representing the Busy state of a chef.
 */
class BusyState : public ChefState {
public:
    /**
     * @brief Change the state of the chef to Busy.
     * @param chef A pointer to the Chef object.
     */
    void changeState(Chef* chef);

    /**
     * @brief Get the current state as a string.
     * @return A string representing the current state.
     */
    std::string getCurrentState();
};


#endif