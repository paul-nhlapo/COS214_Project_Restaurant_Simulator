#pragma once
#include "Satisfaction.h"
using namespace std;

class High: public Satisfaction
{
private:

public:
    High();
    ~High();
    Satisfaction* moodSwing();
    int tip();
};


