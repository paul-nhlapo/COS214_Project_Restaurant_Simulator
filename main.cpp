#include "High.h"
#include "Med.h"
#include "Low.h"
#include "Individual.h"

int main()
{
    // Create state objects
    High high;
    Med med;
    Low low;

    // Create an Individual object with initial state as 'High'
    Individual individual(&high);

    // Test the current state
    individual.applyState();

    // Change state to 'Med'
    individual.setState(&med);
    individual.applyState();

    // Change state to 'Low'
    individual.setState(&low);
    individual.applyState();

    return 0;
}
