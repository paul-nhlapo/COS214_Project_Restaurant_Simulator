#pragma once
#include <string>
#include <iostream>
#include "AddOn.h"
using namespace std;

class Type : public AddOn
{
public:
    Type();
    Type(string x);
    void addInfo(string x);
    void addDetail(int ID);
};