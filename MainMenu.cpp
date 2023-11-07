#ifndef MAINMENU_CPP
#define MAINMENU_CPP

#include "MainMenu.h"

MainMenu::MainMenu()
{
    // mainElementItems.push_back({"Chicken", {"Grilled", "Fried", "Baked"}});
    // mainElementItems.push_back({"Pasta Alfredo", {""}});                                          //Fried ?? AND BOILED??
    // mainElementItems.push_back({"Paella", {""}});                                                 //Saute
    // mainElementItems.push_back({"T-Bone Steak", {"Fried", "Grilled"}});
    // mainElementItems.push_back({"Lamb Curry", {""}});                                             //Saute
    // mainElementItems.push_back({"Cheeseburger", {""}});                                           //Grilled
    // mainElementItems.push_back({"Pepperoni Pizza", {""}});                                        //Baked
    // mainElementItems.push_back({"Lamb Shanks", {"Grilled", "Fried"}});
    // mainElementItems.push_back({"Vegetarian StirFry", {""}});                                     //Fried
    // mainElementItems.push_back({"Vegetarian Biryani", {""}});                                     //Saute

    std::vector<ItemDetails> mainItems_ =
        {
            {1, 75, "Chicken", {"Grilled", "Fried", "Baked"}},
            {2, 80, "Pasta Alfredo", {"Boiled"}},
            {3, 50, "Paella", {"Saute"}},
            {4, 55, "T-Bone Steak", {"Grilled", "Fried"}},
            {5, 55, "Lamb Curry", {"Saute"}},
            {6, 70, "Cheese Burger", {"Fried", "Grilled"}},
            {7, 45, "Pork Belly", {"Grilled"}},
            {8, 25, "Lamb Shanks", {"Grilled", "Fried"}},
            {9, 85, "Vegetarian Stir Fry", {"Fried"}},
            {10, 70, "Vegetarain Biryani", {"Saute"}}};

    mainElementItems = mainItems_;

    // sidesItems.push_back({"Rice", {""}});                                                              //Boiled
    // sidesItems.push_back({"Roast Potatoes", {""}});                                                    //Baked
    // sidesItems.push_back({"Chips", {""}});                                                             //Fried
    // sidesItems.push_back({"Salad", {}});                                                               //Salad
    // sidesItems.push_back({"Bread Rolls", {}});                                                         //Baked

    std::vector<ItemDetails> sideItems_ =
        {
            {1, 75, "Rice", {"Boiled"}},
            {2, 80, "Roast Potatoes", {"Baked"}},
            {3, 50, "Chips", {"Fried"}},
            {4, 55, "Salad", {"Salad"}},
            {5, 55, "Bread Rolls", {"Baked"}},
        };

    sidesItems = sideItems_;

    // sauceItems.push_back({"Lemon and Herb"});
    // sauceItems.push_back({"Red Wine"});
    // sauceItems.push_back({"Hollandaise"});
    // sauceItems.push_back({"Mushroom Sauce"});
    // sauceItems.push_back({"Hot Sauce"});

    std::vector<ItemDetails> sauceItems_ =
        {
            {1, 28, "Lemon and Herb", {"Simmered"}},
            {2, 32, "Red Wine", {"Simmered"}},
            {3, 30, "Hollandaise", {"Simmered"}},
            {4, 18, "Mushroom Sauce", {"Simmered"}},
            {5, 9, "Hot Sauce", {"Simmered"}},
        };

    sauceItems = sauceItems_;

    this->menuType = "Main";
}

std::string MainMenu::getMenuType()
{
    return this->menuType;
}

#endif