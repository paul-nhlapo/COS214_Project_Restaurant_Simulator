#pragma once
#include "Satisfaction.h"
#include "High.h"
#include "Medium.h"
#include "Low.h"
using namespace std;

class Individual
{
private:
public:
    int cID;
    Satisfaction *s;
    Individual();
    Individual(int cID, Satisfaction *s);
    virtual ~Individual();
};


