#ifndef DESSERTMENU_CPP
#define DESSERTMENU_CPP

#include "DessertMenu.h"

DessertMenu::DessertMenu()
{
    // mainElementItems.push_back({"Vanilla Ice Cream", {""}});                                      //Cold Dessert
    // mainElementItems.push_back({"Malva Pudding", {""}});                                          //Warm Dessert
    // mainElementItems.push_back({"Chocolate Lava Cake", {""}});                                    //Warm Dessert
    // mainElementItems.push_back({"Apple Crumble", {""}});                                          //Warm Dessert
    // mainElementItems.push_back({"Lemon Cheesecake", {""}});                                       //Cold Dessert

    std::vector<ItemDetails> mainItems_ =
        {
            {1, 75, "Vanilla Ice Cream", {"Cold Dessert"}},
            {2, 80, "Malva Pudding", {"Warm Dessert"}},
            {3, 50, "Chocolate Lava Cake", {"Warm Dessert"}},
            {4, 55, "Apple Crumble", {"Warm Dessert"}},
            {5, 55, "Lemon Cheesecake", {"Cold Dessert"}},
        };

    mainElementItems = mainItems_;

    // sidesItems.push_back({"Fresh Fruit", {""}});                                                      //No Cook
    // sidesItems.push_back({"Whipped Cream", {""}});                                                    //No Cook
    // sidesItems.push_back({"Chocolate Pieces", {""}});                                                 //No Cook

    std::vector<ItemDetails> sideItems_ =
        {
            {1, 75, "Fresh Fruit", {"No Cook"}},
            {2, 80, "Whipped Cream", {"No Cook"}},
            {3, 50, "Butter Biscuits", {"No Cook"}},
        };

    sidesItems = sideItems_;

    // sauceItems.push_back({"Caramel Sauce"});
    // sauceItems.push_back({"Chocolate Sauce"});
    // sauceItems.push_back({"Raspberry Sauce"});

    std::vector<ItemDetails> sauceItems_ =
        {
            {1, 15, "Caramel Sauce", {"Simmered"}},
            {2, 14, "Chocolate Sauce", {"Simmered"}},
            {3, 25, "Raspberry Sauce", {"Simmered"}},
        };

    sauceItems = sauceItems_;

    this->menuType = "Dessert";
}

std::string DessertMenu::getMenuType()
{
    return this->menuType;
}

#endif