#pragma once
#include <string>
#include <iostream>
#include "AddOn.h"
using namespace std;

class Ice : public AddOn
{
public:
    Ice();
    Ice(string x);
    void addInfo(string x);
    void addDetail(int ID);
};