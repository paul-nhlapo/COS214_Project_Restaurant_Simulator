#pragma once
#include "Satisfaction.h"
using namespace std;

class Low: public Satisfaction
{
private:

public:
    Low();
    ~Low();
    Satisfaction* moodSwing();
    int tip();
};


