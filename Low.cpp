#include "Low.h"
using namespace std;

Low::Low(/* args */) : Satisfaction()
{
}

Low::~Low()
{
}

Satisfaction *Low::moodSwing()
{
    if (patience < 0)
    {
        return new Low();
    }
}

int Low::tip()
{
    return 5;
}
