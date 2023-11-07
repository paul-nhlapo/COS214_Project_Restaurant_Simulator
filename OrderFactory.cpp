#include "OrderFactory.h"
#include "Order.h"
#include "MainOrder.h"
#include "BasicOrder.h"
// #include "MainOrder.h"
#include <string>
#include <vector>
#include <iostream>
#include "Table.h"
#include "OrderDetail.h"
#include "OrderBuilder.h"
#include "StarterOrderBuilder.h"
#include "MainOrderBuilder.h"
#include "DessertOrderBuilder.h"
#include "StarterMenu.h"
#include "MainMenu.h"
#include "DessertMenu.h"
using namespace std;

// OrderFactory::

OrderFactory::OrderFactory() : Factory()
{
    starterMenu = new StarterMenu();
    mainMenu = new MainMenu();
    dessertMenu = new DessertMenu();
}

OrderFactory::~OrderFactory()
{
}

vector<Order_ *> OrderFactory::getOrder(Table *t)
{
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
        OrderBuilder *starterBuilder = new StarterOrderBuilder();

        std::cout << "What would you like for your starter? :" << std::endl
                  << std::endl;
        starterMenu->printMainElementList();

        int starterMainElement;
        cin >> starterMainElement;
        std::cout << std::endl;

        starterBuilder->setMainElement(starterMainElement);

        if (starterMainElement == 1 || starterMainElement == 6 || starterMainElement == 9)
        {
            starterMenu->printMainElementStrategyList(starterMainElement);
            int mainPrepStrategy;
            cin >> mainPrepStrategy;
            starterBuilder->setMainElementPrepStrategy(mainPrepStrategy);
        }

        std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sidesChoice = ' ';
        cin >> sidesChoice;

        starterBuilder->setSideChoice(sidesChoice);

        if (sidesChoice == 'Y' || sidesChoice == 'y')
        {
            std::cout << "What side would you like? :" << std::endl
                      << std::endl;
            starterMenu->printSideItemsList();
            int sidesElementChoice;
            cin >> sidesElementChoice;

            starterBuilder->setSideElement(sidesElementChoice);
        }

        std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sauceChoice = ' ';
        cin >> sauceChoice;

        starterBuilder->setSauceChoice(sauceChoice);

        if (sauceChoice == 'Y' || sauceChoice == 'y')
        {
            std::cout << "What sauce would you like? :" << std::endl
                      << std::endl;
            starterMenu->printSauceItemsList();

            int sauceElementChoice;
            cin >> sauceElementChoice;

            starterBuilder->setSauceElement(sauceElementChoice);
        }
        starterBuilder->getOrder()->chefChoice = menuChoice;
        starterBuilder->getOrder()->tableNO = t->tableID;
        t->order.push_back(starterBuilder->getOrder());
        t->starterCount++;
        // delete starterBuilder;
    }

    else if (menuChoice == 2)
    {
        OrderBuilder *mainBuilder = new MainOrderBuilder();

        std::cout << "What would you like for your main? :" << std::endl
                  << std::endl;
        mainMenu->printMainElementList();

        int mainMainElement;
        cin >> mainMainElement;
        std::cout << std::endl;

        mainBuilder->setMainElement(mainMainElement);

        if (mainMainElement == 1 || mainMainElement == 4 || mainMainElement == 6 || mainMainElement == 8)
        {
            mainMenu->printMainElementStrategyList(mainMainElement);
            int mainPrepStrategy;
            cin >> mainPrepStrategy;
            mainBuilder->setMainElementPrepStrategy(mainPrepStrategy);
        } // else mainprepstrat = 1

        std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sidesChoice = ' ';
        cin >> sidesChoice;

        mainBuilder->setSideChoice(sidesChoice);

        if (sidesChoice == 'Y' || sidesChoice == 'y')
        {
            std::cout << "What side would you like? :" << std::endl
                      << std::endl;
            mainMenu->printSideItemsList();
            // std::cout << "testing:" << std::endl;
            int sidesElementChoice;
            cin >> sidesElementChoice;

            mainBuilder->setSideElement(sidesElementChoice);
        }

        std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sauceChoice = ' ';
        cin >> sauceChoice;

        mainBuilder->setSauceChoice(sauceChoice);

        if (sauceChoice == 'Y' || sauceChoice == 'y')
        {
            std::cout << "What sauce would you like? :" << std::endl
                      << std::endl;
            mainMenu->printSauceItemsList();

            int sauceElementChoice;
            cin >> sauceElementChoice;

            mainBuilder->setSauceElement(sauceElementChoice);
        }
        mainBuilder->getOrder()->chefChoice = menuChoice;
        mainBuilder->getOrder()->tableNO = t->tableID;
        t->order.push_back(mainBuilder->getOrder());
        t->mainCount++;
    }

    else if (menuChoice == 3)
    {
        OrderBuilder *dessertBuilder = new DessertOrderBuilder();

        std::cout << "What would you like for your dessert? :" << std::endl
                  << std::endl;
        dessertMenu->printMainElementList();

        int dessertMainElement;
        cin >> dessertMainElement;
        std::cout << std::endl;

        dessertBuilder->setMainElement(dessertMainElement);

        std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sidesChoice = ' ';
        cin >> sidesChoice;

        dessertBuilder->setSideChoice(sidesChoice);

        if (sidesChoice == 'Y' || sidesChoice == 'y')
        {
            std::cout << "What side would you like? :" << std::endl
                      << std::endl;
            dessertMenu->printSideItemsList();

            int sidesElementChoice;
            cin >> sidesElementChoice;

            dessertBuilder->setSideElement(sidesElementChoice);
        }

        std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
                  << std::endl;
        char sauceChoice = ' ';
        cin >> sauceChoice;

        dessertBuilder->setSauceChoice(sauceChoice);

        if (sauceChoice == 'Y' || sauceChoice == 'y')
        {
            std::cout << "What sauce would you like? :" << std::endl
                      << std::endl;
            dessertMenu->printSauceItemsList();

            int sauceElementChoice;
            cin >> sauceElementChoice;

            dessertBuilder->setSauceElement(sauceElementChoice);
        }
        dessertBuilder->getOrder()->chefChoice = menuChoice;
        dessertBuilder->getOrder()->tableNO = t->tableID;
        t->order.push_back(dessertBuilder->getOrder());
        t->dessertCount++;
    }
    return t->order;
}

void OrderFactory::createProduct()
{
    return;
}
