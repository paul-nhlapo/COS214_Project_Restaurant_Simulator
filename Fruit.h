#pragma once
#include <string>
#include <iostream>
#include "AddOn.h"
using namespace std;

class Fruit : public AddOn
{
public:
    Fruit();
    Fruit(string x);
    void addInfo(string x);
    void addDetail(int ID);
};