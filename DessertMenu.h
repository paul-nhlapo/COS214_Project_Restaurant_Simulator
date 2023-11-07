#ifndef DESSERTMENU_H
#define DESSERTMENU_H

#include "Menu.h"

class DessertMenu : public Menu
{
    public:
        DessertMenu();
        std::string getMenuType();
};

#endif