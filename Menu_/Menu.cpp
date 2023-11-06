#ifndef MENU_CPP
#define MENU_CPP

#include "Menu.h"

Menu::Menu()
{
    this->mainElement = "";
    this->side = "";
    this->sauce = "";
}

std::string Menu::getMainElement()
{
    return this->mainElement;
}

std::string Menu::getSauce()
{
    return this->sauce;
}

std::string Menu::getSide()
{
    return this->side;
}

void Menu::printMainElementList()
{
    for (int i = 0; i < mainElementItems.size(); i++)
    {
        ItemDetails menuItem = mainElementItems[i];
        std::cout << menuItem.menuNumber << "\t" << menuItem.MainElement << std::endl;
    }
}

void Menu::printMainElementStrategyList(int selectedMainElement)
{
    if (selectedMainElement < 1 || selectedMainElement > mainElementItems.size())
    {
        std::cout << "Invalid selection." << std::endl;
        return;
    }

    for(int i = 0; i < mainElementItems.size(); i++)
    {
        if(mainElementItems[i].menuNumber == selectedMainElement)
        {
            std::cout << "How would you like your " << mainElementItems[i].MainElement << " prepared? :" << std::endl;
            for(int j = 0; j < mainElementItems[i].cookingMethods.size(); j++)
            {
                std::cout << j + 1 << "\t" << mainElementItems[i].cookingMethods[j] << std::endl;
            }
        }
    }
}

void Menu::printSideItemsList()
{
    for (int i = 0; i < sidesItems.size(); i++)
    {
        ItemDetails menuItem = sidesItems[i];
        std::cout << menuItem.menuNumber << "\t" << menuItem.MainElement << std::endl;
    }
}

void Menu::printSauceItemsList()
{
    for(int i = 0; i < sauceItems.size(); i++)
    {
        ItemDetails menuItem = sauceItems[i];
        std::cout << menuItem.menuNumber << "\t" << menuItem.MainElement << std::endl;
    }
}

std::vector<Menu::ItemDetails> Menu::getMainElementItems(){
    return mainElementItems;
}

std::vector<Menu::ItemDetails> Menu::getSidesItems(){
    return sidesItems;
}

std::vector<Menu::ItemDetails> Menu::getSauceItems(){
    return sauceItems;
}

#endif