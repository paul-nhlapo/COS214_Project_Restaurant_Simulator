#pragma once
#include "Satisfaction.h"
#include "Individual.h"
using namespace std;

class Low : public Satisfaction
{
private:
public:
    Low(int patience);
    ~Low();
    Satisfaction *moodSwing();
    int tip();
};
