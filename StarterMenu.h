#ifndef STARTERMENU_H
#define STARTERMENU_H

#include "Menu.h"

class StarterMenu : public Menu
{
    public:
        StarterMenu();
        std::string getMenuType();
};

#endif