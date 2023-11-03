#pragma once
#include "Satisfaction.h"
using namespace std;

class Medium: public Satisfaction
{
private:

public:
    Medium();
    ~Medium();
    Satisfaction* moodSwing();
    int tip();
};


