#ifndef STARTERMENU_CPP
#define STARTERMENU_CPP

#include "StarterMenu.h"

StarterMenu::StarterMenu()
{
    // mainElementItems.push_back({"Chicken Salad", {"Grilled", "Fried", "Baked"}});
    // mainElementItems.push_back({"Sushi", {""}});                                                   //Sushi
    // mainElementItems.push_back({"Pumpkin Soup", {""}});                                            //Simmered
    // mainElementItems.push_back({"Butternut Soup", {""}});                                          //Simmered
    // mainElementItems.push_back({"Tomato Soup", {""}});                                             //Simmered
    // mainElementItems.push_back({"Calamari", {"Fried", "Grilled"}});
    // mainElementItems.push_back({"Caeasar Salad", {""}});                                           //Salad
    // mainElementItems.push_back({"Samoosas", {""}});                                                //Fried
    // mainElementItems.push_back({"Tapas", {"Grilled", "Fried", "Baked"}});
    // mainElementItems.push_back({"Empanadas", {""}});                                               //Baked

    std::vector<ItemDetails> mainItems_ =
        {
            {1, 75, "Chicken Salad", {"Grilled", "Fried", "Baked"}},
            {2, 80, "Sushi", {"Simmered"}},
            {3, 50, "Pumpkin Soup", {"Simmered"}},
            {4, 55, "Butternut Soup", {"Simmered"}},
            {5, 55, "Tomato Soup", {"Simmered"}},
            {6, 70, "Calamari", {"Fried", "Grilled"}},
            {7, 45, "Caeasar Salad", {"Salad"}},
            {8, 25, "Samoosas", {"Fried"}},
            {9, 85, "Tapas", {"Grilled", "Fried", "Baked"}},
            {10, 70, "Empanadas", {"Baked"}}};

    mainElementItems = mainItems_;

    std::vector<ItemDetails> sideItems_ =
        {
            {1, 75, "Bread Rolls", {"Baked"}},
            {2, 80, "Bread Sticks", {"Baked"}},
            {3, 50, "Mozzarella Sticks", {"No Cook"}},
            {4, 55, "Nachos", {"Baked"}},
            {5, 55, "Buffalo Wings", {"Fried"}},
        };

    sidesItems = sideItems_;

    // sidesItems.push_back({"Bread Rolls", {""}});                                                       //Baked
    // sidesItems.push_back({"Bread Sticks", {""}});                                                      //Baked
    // sidesItems.push_back({"Mozzarella Sticks", {""}});                                                 //No Cook
    // sidesItems.push_back({"Nachos", {}});                                                              //Baked
    // sidesItems.push_back({"Chicken Wings", {}});                                                       //Fried

    // sauceItems.push_back({"Soy Sauce"});
    // sauceItems.push_back({"Salad Dressing"});
    // sauceItems.push_back({"Guacamole"});
    // sauceItems.push_back({"Mushroom Sauce"});
    // sauceItems.push_back({"Hot Sauce"});

    std::vector<ItemDetails> sauceItems_ =
        {
            {1, 15, "Soy Sauce", {"Simmered"}},
            {2, 14, "Salad Dressing", {"Simmered"}},
            {3, 25, "Guacamole", {"Simmered"}},
            {4, 18, "Mushroom Sauce", {"Simmered"}},
            {5, 9, "Hot Sauce", {"Simmered"}},
        };

    sauceItems = sauceItems_;

    this->menuType = "Starter";
}

std::string StarterMenu::getMenuType()
{
    return this->menuType;
}

#endif