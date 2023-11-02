#pragma once
#include <string>
#include <iostream>
#include "AddOn.h"
using namespace std;

class Base : public AddOn
{
public:
    Base();
    Base(string x);
    void addInfo(string x);
    void addDetail(int ID);
};