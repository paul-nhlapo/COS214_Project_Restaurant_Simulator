#pragma once
//#include "Individual.h"
#include <iostream>
using namespace std;

class Individual;
class Satisfaction
{
private:
    /* data */

public:
    Individual *myIn;
    char type;
    int patience = 100;
    Satisfaction(int patience);
    ~Satisfaction();
    virtual Satisfaction *moodSwing() = 0;
    virtual int tip() = 0;
    void setIndividual(Individual *i);
};
