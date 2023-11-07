#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "StarterMenu.h"
#include "MainMenu.h"
#include "DessertMenu.h"

class Order_
{
public:
    std::string menuChoice;
    int chefChoice;
    int mainElement;
    int mainPrepStrategy;
    int sidePrepStrategy;
    char sidesChoice;
    int sidesElement;
    char sauceChoice;
    int sauceElement;
    double price;
    int tableNO;

    // Additional attributes and methods can be added as needed
    // getMenuChoice() sets it to what the user pressed

    std::string getMenuChoice()
    {
        if (chefChoice == 1)
            menuChoice = "Starter";
        else if (chefChoice == 2)
            menuChoice = "Main";
        else if (chefChoice == 3)
            menuChoice = "Dessert";
        return menuChoice;
    }

    std::string getMainElement()
    {
        if (chefChoice == 1)
        {
            StarterMenu starterObj;
            return starterObj.getMainElementItems()[mainElement - 1].MainElement;
        }
        if (chefChoice == 2)
        {
            MainMenu mainObj;
            return mainObj.getMainElementItems()[mainElement - 1].MainElement;
        }
        if (chefChoice == 3)
        {
            DessertMenu dessertObj;
            return dessertObj.getMainElementItems()[mainElement - 1].MainElement;
        }
    }

    std::string getMainPrepStrategy()
    {
        if (chefChoice == 1)
        {
            StarterMenu starterObj;
            return starterObj.getMainElementItems()[mainElement - 1].cookingMethods[mainPrepStrategy - 1];
        }
        if (chefChoice == 2)
        {
            MainMenu mainObj;
            return mainObj.getMainElementItems()[mainElement - 1].cookingMethods[mainPrepStrategy - 1];
        }
        if (chefChoice == 3)
        {
            DessertMenu dessertObj;
            return dessertObj.getMainElementItems()[mainElement - 1].cookingMethods[mainPrepStrategy - 1];
        }
    }

    std::string getSidePrepStrategy()
    {
        if (sidesChoice == 'Y' || sidesChoice == 'y')
        {
            if (chefChoice == 1)
            {
                StarterMenu starterObj;
                return starterObj.getSidesItems()[sidesElement - 1].cookingMethods[sidePrepStrategy - 1];
            }
            if (chefChoice == 2)
            {
                MainMenu mainObj;
                return mainObj.getSidesItems()[sidesElement - 1].cookingMethods[sidePrepStrategy - 1];
            }
            if (chefChoice == 3)
            {
                DessertMenu dessertObj;
                return dessertObj.getSidesItems()[sidesElement - 1].cookingMethods[sidePrepStrategy - 1];
            }
        }
        else
            return "";
    }

    std::string getSidesElement()
    {
        if (sidesChoice == 'Y' || sidesChoice == 'y')
        {
            if (chefChoice == 1)
            {
                StarterMenu starterObj;
                return starterObj.getSidesItems()[sidesElement - 1].MainElement;
            }
            if (chefChoice == 2)
            {
                MainMenu mainObj;
                return mainObj.getSidesItems()[sidesElement - 1].MainElement;
            }
            if (chefChoice == 3)
            {
                DessertMenu dessertObj;
                return dessertObj.getSidesItems()[sidesElement - 1].MainElement;
            }
        }
        else
            return "";
    }

    std::string getSauceElement()
    {
        if (sauceChoice == 'Y' || sauceChoice == 'y')
        {
            if (chefChoice == 1)
            {
                StarterMenu starterObj;
                return starterObj.getSauceItems()[sauceElement - 1].MainElement;
            }
            if (chefChoice == 2)
            {
                MainMenu mainObj;
                return mainObj.getSauceItems()[sauceElement - 1].MainElement;
            }
            if (chefChoice == 3)
            {
                DessertMenu dessertObj;
                return dessertObj.getSauceItems()[sauceElement - 1].MainElement;
            }
        }
        else
            return "";
    }

    // srat = get cooking methdo
    //  yeah thanks man it sokay
    //  yeah good idea

    Order_()
    {

        menuChoice = ""; // which chef will cook this
        chefChoice = 1;
        mainElement = 1;
        mainPrepStrategy = 1;
        sidePrepStrategy = 1;
        sidesChoice = 'N';
        sidesElement = -1;
        sauceChoice = 'N';
        sauceElement = -1;
        price = 0.0;
        tableNO = 0;
    }
};

#endif
