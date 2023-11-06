#include <iostream>

#include "Chef.h"
#include "ConcreteChefCreator.h"
#include "DessertChef.h"
#include "HeadChef.h"
#include "MainChef.h"
#include "StarterChef.h"
#include "Kitchen.h"
#include "SimpleOrder.h"
#include "StarterOrder.h"
#include "MainOrder.h"
#include "DessertOrder.h"
#include "Menu.h"
#include "StarterMenu.h"
#include "MainMenu.h"
#include "DessertMenu.h"

#include "Staff.h"
#include "Waiter.h"

using namespace std;

int main()
{

    Kitchen *kitchen = new Kitchen();

    //******** Factory DP Testing ********//

    std::cout << "***** Testing Factory DP *****" << std::endl;

    // Create Chef Factories
    std::cout << "*** Creating Chef Factories ***" << std::endl;
    ChefCreator *headChefCreator = new HeadChefCreator();
    ChefCreator *starterChefCreator = new StarterChefCreator();
    ChefCreator *mainChefCreator = new MainChefCreator();
    ChefCreator *dessertChefCreator = new DessertChefCreator();
    std::cout << "*** Chef Factories Created ***" << std::endl
              << std::endl;

    // Create individual Chefs
    std::cout << "*** Creating Concrete Chefs ***" << std::endl;
    Chef *headChef = headChefCreator->createChef("Head Chef", kitchen);
    Chef *starterChef = starterChefCreator->createChef("Starter Chef", kitchen);
    Chef *mainChef = mainChefCreator->createChef("Main Chef", kitchen);
    Chef *dessertChef = dessertChefCreator->createChef("Dessert Chef", kitchen);

    

    std::cout << "*** Concrete Chefs Created ***" << std::endl
              << std::endl;

    std::cout << std::endl;

    //******** State DP Testing ********//

    std::cout << "***** Testing State DP *****" << std::endl;

    // Get Starting State
    std::cout << "*** Print Initial States: ***" << std::endl;
    std::cout << headChef->getChefType() << "'s Current State is: " << headChef->getCurrentState() << std::endl;
    std::cout << starterChef->getChefType() << "'s Current State is: " << starterChef->getCurrentState() << std::endl;
    std::cout << mainChef->getChefType() << "'s Current State is: " << mainChef->getCurrentState() << std::endl;
    std::cout << dessertChef->getChefType() << "'s Current State is: " << dessertChef->getCurrentState() << std::endl;

    std::cout << std::endl;

    // Change State from Free to Busy

    std::cout << "*** Changing States From Free to Busy: ***" << std::endl;
    headChef->changeChefState();
    starterChef->changeChefState();
    mainChef->changeChefState();
    dessertChef->changeChefState();

    std::cout << headChef->getChefType() << "'s Current State is: " << headChef->getCurrentState() << std::endl;
    std::cout << starterChef->getChefType() << "'s Current State is: " << starterChef->getCurrentState() << std::endl;
    std::cout << mainChef->getChefType() << "'s Current State is: " << mainChef->getCurrentState() << std::endl;
    std::cout << dessertChef->getChefType() << "'s Current State is: " << dessertChef->getCurrentState() << std::endl;

    std::cout << std::endl;

    std::cout << "*** Changing States From Busy to Free: ***" << std::endl;
    headChef->changeChefState();
    starterChef->changeChefState();
    mainChef->changeChefState();
    dessertChef->changeChefState();

    std::cout << headChef->getChefType() << "'s Current State is: " << headChef->getCurrentState() << std::endl;
    std::cout << starterChef->getChefType() << "'s Current State is: " << starterChef->getCurrentState() << std::endl;
    std::cout << mainChef->getChefType() << "'s Current State is: " << mainChef->getCurrentState() << std::endl;
    std::cout << dessertChef->getChefType() << "'s Current State is: " << dessertChef->getCurrentState() << std::endl;

    //******** CoR DP Testing ********//

    std::cout << "***** Testing CoR DP *****" << std::endl;

    // Set next Chef in CoR
    headChef->setNextChef(starterChef);
    starterChef->setNextChef(mainChef);
    mainChef->setNextChef(dessertChef);

    std::cout << std::endl
              << std::endl
              << std::endl;

    // Testing Menu and Order
    /*
    Menu *starterMenu = new StarterMenu();
    Menu *mainMenu = new MainMenu();
    Menu *dessertMenu = new DessertMenu();

    std::cout << "Would you like to order: " << std::endl;
    std::cout << "1. Starters" << std::endl;
    std::cout << "2. Main" << std::endl;
    std::cout << "3. Dessert" << std::endl;

    int menuChoice;
    cin >> menuChoice;

    while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3)
    {
        std::cout << "Please enter a valid number" << std::endl;
        cin >> menuChoice;
        std::cout << std::endl
                  << std::endl;
    }

    if (menuChoice == 1)
    {
        std::cout << "What would you like for your starter? :" << std::endl
                  << std::endl;
        starterMenu->printMainElementList();

        int starterMainElement;
        cin >> starterMainElement;
        std::cout << std::endl;

        if (starterMainElement == 1 || starterMainElement == 6 || starterMainElement == 9)
        {
            starterMenu->printMainElementStrategyList(starterMainElement);
            int mainPrepStrategy;
            cin >> mainPrepStrategy;
        }

        std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sidesChoice = ' ';
        cin >> sidesChoice;
        if (sidesChoice == 'Y' || 'y')
        {
            std::cout << "What side would you like? :" << std::endl
                      << std::endl;
            starterMenu->printSideItemsList();

            int sidesElementChoice;
            cin >> sidesElementChoice;
        }

        std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sauceChoice = ' ';
        cin >> sauceChoice;
        if (sauceChoice == 'Y' || 'y')
        {
            std::cout << "What sauce would you like? :" << std::endl
                      << std::endl;
            starterMenu->printSauceItemsList();

            int sidesElementChoice;
            cin >> sidesElementChoice;
        }
    }

    else if (menuChoice == 2)
    {
        std::cout << "What would you like for your main? :" << std::endl
                  << std::endl;
        mainMenu->printMainElementList();

        int mainMainElement;
        cin >> mainMainElement;
        std::cout << std::endl;

        if (mainMainElement == 1 || mainMainElement == 4 || mainMainElement == 6 || mainMainElement == 8)
        {
            starterMenu->printMainElementStrategyList(mainMainElement);
            int mainPrepStrategy;
            cin >> mainPrepStrategy;
        }

        std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sidesChoice = ' ';
        cin >> sidesChoice;
        if (sidesChoice == 'Y' || 'y')
        {
            std::cout << "What side would you like? :" << std::endl
                      << std::endl;
            mainMenu->printSideItemsList();

            int sidesElementChoice;
            cin >> sidesElementChoice;
        }

        std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sauceChoice = ' ';
        cin >> sauceChoice;
        if (sauceChoice == 'Y' || 'y')
        {
            std::cout << "What sauce would you like? :" << std::endl
                      << std::endl;
            mainMenu->printSauceItemsList();

            int sidesElementChoice;
            cin >> sidesElementChoice;
        }
    }

    else if (menuChoice == 3)
    {
        std::cout << "What would you like for your dessert? :" << std::endl
                  << std::endl;
        dessertMenu->printMainElementList();

        int dessertMainElement;
        cin >> dessertMainElement;
        std::cout << std::endl;

        std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sidesChoice = ' ';
        cin >> sidesChoice;
        if (sidesChoice == 'Y' || 'y')
        {
            std::cout << "What side would you like? :" << std::endl
                      << std::endl;
            dessertMenu->printSideItemsList();

            int sidesElementChoice;
            cin >> sidesElementChoice;
        }

        std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sauceChoice = ' ';
        cin >> sauceChoice;
        if (sauceChoice == 'Y' || 'y')
        {
            std::cout << "What sauce would you like? :" << std::endl
                      << std::endl;
            dessertMenu->printSauceItemsList();

            int sidesElementChoice;
            cin >> sidesElementChoice;
        }
    }
*/

    Waiter* waiter1 = new Waiter();

    waiter1->takeOrder();
    waiter1->printOrders();
    
    for(int i=0; i<waiter1->orders.size(); i++){
        kitchen->sendToKitchen(waiter1->orders[i] , headChef);
    }

    std::cout << std::endl
              << std::endl;

    // Order* order1 = new StarterOrder("Sushi", "Sushi", "Wasabi", "Soy Sauce");
    // headChef->addOrderToQueue(order1);

    // Order* order2 = new DessertOrder("Ice Cream", "Cold Dessert", "", "Chocolate");
    // headChef->addOrderToQueue(order2);

    // Order* order3 = new MainOrder("Steak", "Grill", "Roasted Potatoes", "Mushroom Sauce");
    // headChef->addOrderToQueue(order3);

    // //Meal to prepare - Passes through Chain
    // headChef->prepareMeal(order1);

    // std::cout << std::endl;

    // headChef->prepareMeal(order2);

    // std::cout << std::endl;

    // headChef->prepareMeal(order3);

    // delete order3;
    // delete order2;
    // delete order1;

    delete dessertChef;
    delete mainChef;
    delete starterChef;
    delete headChef;

    delete dessertChefCreator;
    delete mainChefCreator;
    delete starterChefCreator;
    delete headChefCreator;

    delete kitchen;

    return 0;
}