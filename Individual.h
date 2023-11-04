#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "Satisfaction.h"

// The 'Context' class
class Individual
{
private:
    Satisfaction *state; // pointer to hold the current state
public:
    Individual(Satisfaction *state);
    void setState(Satisfaction *state); // Function to change the state
    void applyState();                  // Function to call the handle function of the current state
};

#endif // INDIVIDUAL_H
