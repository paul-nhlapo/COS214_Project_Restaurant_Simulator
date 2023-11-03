#include "Medium.h"
#include "Low.h"
using namespace std;

Medium::Medium(/* args */) : Satisfaction()
{
}

Medium::~Medium()
{
}

Satisfaction *Medium::moodSwing()
{
    if (patience < 50)
    {
        return new Low();
    }
}

int Medium::tip()
{
    return 20;
}
