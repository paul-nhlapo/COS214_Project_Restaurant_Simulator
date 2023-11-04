#include "Individual.h"

/**
 * @brief Construct a new Individual:: Individual object
 * 
 * @param state pointer to a Satisfaction object
 */
Individual::Individual(Satisfaction *state) : state(state) {}

/**
 * @brief Set the state object
 * 
 * @param state pointer to a Satisfaction object
 */
void Individual::setState(Satisfaction *state)
{
    this->state = state;
}

/**
 * @brief Apply the current state
 * 
 */
void Individual::applyState()
{
    state->handle();
}
