#pragma once
#include "Satisfaction.h"
#include "Individual.h"
using namespace std;

class Medium : public Satisfaction
{
private:
public:
    Medium(int patience);
    ~Medium();
    Satisfaction *moodSwing();
    int tip();
};
