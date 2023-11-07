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
#include <limits>
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

    // int menuChoice;
    // // cin >> menuChoice;

    // while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3)
    // {
    //     std::cout << "Please enter a valid number" << std::endl;
    //     cin >> menuChoice;
    //     std::cout << std::endl
    //               << std::endl;
    // }
    int menuChoice;
    while (!(std::cin >> menuChoice) || (menuChoice != 1 && menuChoice != 2 && menuChoice != 3))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid number (1, 2, or 3)" << std::endl;
    }

    if (menuChoice == 1)
    {
        OrderBuilder *starterBuilder = new StarterOrderBuilder();

        // std::cout << "What would you like for your starter? :" << std::endl
        //           << std::endl;
        // starterMenu->printMainElementList();

        // int starterMainElement;
        // cin >> starterMainElement;
        // std::cout << std::endl;

        // starterBuilder->setMainElement(starterMainElement);

        // if (starterMainElement == 1 || starterMainElement == 6 || starterMainElement == 9)
        // {
        //     starterMenu->printMainElementStrategyList(starterMainElement);
        //     int mainPrepStrategy;
        //     cin >> mainPrepStrategy;
        //     starterBuilder->setMainElementPrepStrategy(mainPrepStrategy);
        // }
        std::cout << "What would you like for your starter? :" << std::endl
                  << std::endl;
        starterMenu->printMainElementList();

        int starterMainElement;
        while (!(std::cin >> starterMainElement) || (starterMainElement < 1 || starterMainElement > 10))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 10: " << std::endl;
        }
        std::cout << std::endl;

        starterBuilder->setMainElement(starterMainElement);

        if (starterMainElement == 1 || starterMainElement == 6 || starterMainElement == 9)
        {
            starterMenu->printMainElementStrategyList(starterMainElement);
            int mainPrepStrategy;
            while (!(std::cin >> mainPrepStrategy) || (mainPrepStrategy < 1 || mainPrepStrategy > 10))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 10: " << std::endl;
            }
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

        // std::cout << "What would you like for your main? :" << std::endl
        //           << std::endl;
        // mainMenu->printMainElementList();

        // int mainMainElement;
        // cin >> mainMainElement;
        // std::cout << std::endl;

        // mainBuilder->setMainElement(mainMainElement);

        // if (mainMainElement == 1 || mainMainElement == 4 || mainMainElement == 6 || mainMainElement == 8)
        // {
        //     mainMenu->printMainElementStrategyList(mainMainElement);
        //     int mainPrepStrategy;
        //     cin >> mainPrepStrategy;
        //     mainBuilder->setMainElementPrepStrategy(mainPrepStrategy);
        // } // else mainprepstrat = 1
        std::cout << "What would you like for your main? :" << std::endl
                  << std::endl;
        mainMenu->printMainElementList();

        int mainMainElement;
        while (!(std::cin >> mainMainElement) || (mainMainElement < 1 || mainMainElement > 10))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 10: " << std::endl;
        }
        std::cout << std::endl;

        mainBuilder->setMainElement(mainMainElement);

        if (mainMainElement == 1 || mainMainElement == 4 || mainMainElement == 6 || mainMainElement == 8)
        {
            mainMenu->printMainElementStrategyList(mainMainElement);
            int mainPrepStrategy;
            while (!(std::cin >> mainPrepStrategy) || (mainPrepStrategy < 1 || mainPrepStrategy <= 8))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 8: " << std::endl;
            }
            mainBuilder->setMainElementPrepStrategy(mainPrepStrategy);
        }

        // std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
        //           << std::endl;
        // char sidesChoice = ' ';
        // cin >> sidesChoice;
        char sidesChoice = ' ';
        do
        {
            std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
                      << std::endl;
            cin >> sidesChoice;
            if (sidesChoice != 'Y' && sidesChoice != 'y' && sidesChoice != 'N' && sidesChoice != 'n')
            {
                std::cout << "Invalid choice. Please enter Y or N." << std::endl;
                cin.clear();                                                   // clear the error flag
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            }
        } while (sidesChoice != 'Y' && sidesChoice != 'y' && sidesChoice != 'N' && sidesChoice != 'n');

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

        // std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
        //           << std::endl;
        // char sauceChoice = ' ';
        // cin >> sauceChoice;
        char sauceChoice = ' ';
        do
        {
            std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
                      << std::endl;
            cin >> sauceChoice;
            if (sauceChoice != 'Y' && sauceChoice != 'y' && sauceChoice != 'N' && sauceChoice != 'n')
            {
                std::cout << "Invalid choice. Please enter Y or N." << std::endl;
                cin.clear();                                                   // clear the error flag
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            }
        } while (sauceChoice != 'Y' && sauceChoice != 'y' && sauceChoice != 'N' && sauceChoice != 'n');

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
        // OrderBuilder *dessertBuilder = new DessertOrderBuilder();

        // std::cout << "What would you like for your dessert? :" << std::endl
        //           << std::endl;
        // dessertMenu->printMainElementList();

        // int dessertMainElement;
        // cin >> dessertMainElement;
        // std::cout << std::endl;

        // dessertBuilder->setMainElement(dessertMainElement);
        OrderBuilder *dessertBuilder = new DessertOrderBuilder();

        std::cout << "What would you like for your dessert? :" << std::endl
                  << std::endl;
        dessertMenu->printMainElementList();

        int dessertMainElement;
        do
        {
            cin >> dessertMainElement;
            if (dessertMainElement < 1 || dessertMainElement > 5)
            {
                std::cout << "Invalid choice. Please choose a number between 1 and 5." << std::endl;
                cin.clear();                                                   // clear the error flag
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            }
        } while (dessertMainElement < 1 || dessertMainElement > 5);

        std::cout << std::endl;

        dessertBuilder->setMainElement(dessertMainElement);

        // std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
        //           << std::endl;
        // char sidesChoice = ' ';
        // cin >> sidesChoice;
        char sidesChoice = ' ';
        do
        {
            std::cout << "Would you like any sides with your meal? (Y/N)" << std::endl
                      << std::endl;
            cin >> sidesChoice;
            if (sidesChoice != 'Y' && sidesChoice != 'y' && sidesChoice != 'N' && sidesChoice != 'n')
            {
                std::cout << "Invalid choice. Please enter Y or N." << std::endl;
                cin.clear();                                                   // clear the error flag
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            }
        } while (sidesChoice != 'Y' && sidesChoice != 'y' && sidesChoice != 'N' && sidesChoice != 'n');

        dessertBuilder->setSideChoice(sidesChoice);

        if (sidesChoice == 'Y' || sidesChoice == 'y')
        {
            // std::cout << "What side would you like? :" << std::endl
            //           << std::endl;
            // dessertMenu->printSideItemsList();

            // int sidesElementChoice;
            // cin >> sidesElementChoice;

            // dessertBuilder->setSideElement(sidesElementChoice);
            std::cout << "What side would you like? :" << std::endl
                      << std::endl;
            dessertMenu->printSideItemsList();

            int sidesElementChoice;
            do
            {
                cin >> sidesElementChoice;
                if (sidesElementChoice < 1 || sidesElementChoice > 3)
                {
                    std::cout << "Invalid choice. Please choose a number between 1 and 3." << std::endl;
                    cin.clear();                                                   // clear the error flag
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
                }
            } while (sidesElementChoice < 1 || sidesElementChoice > 3);

            dessertBuilder->setSideElement(sidesElementChoice);
        }

        // std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
        //           << std::endl;
        // char sauceChoice = ' ';
        // cin >> sauceChoice;
        char sauceChoice = ' ';
        do
        {
            std::cout << "Would you like a sauce with your meal? (Y/N)" << std::endl
                      << std::endl;
            cin >> sauceChoice;
            if (sauceChoice != 'Y' && sauceChoice != 'y' && sauceChoice != 'N' && sauceChoice != 'n')
            {
                std::cout << "Invalid choice. Please enter Y or N." << std::endl;
                cin.clear();                                                   // clear the error flag
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            }
        } while (sauceChoice != 'Y' && sauceChoice != 'y' && sauceChoice != 'N' && sauceChoice != 'n');

        dessertBuilder->setSauceChoice(sauceChoice);

        if (sauceChoice == 'Y' || sauceChoice == 'y')
        {
            // std::cout << "What sauce would you like? :" << std::endl
            //           << std::endl;
            // dessertMenu->printSauceItemsList();

            // int sauceElementChoice;
            // cin >> sauceElementChoice;

            // dessertBuilder->setSauceElement(sauceElementChoice);
            std::cout << "What sauce would you like? :" << std::endl
                      << std::endl;
            dessertMenu->printSauceItemsList();

            int sauceElementChoice;
            do
            {
                cin >> sauceElementChoice;
                if (sauceElementChoice < 1 || sauceElementChoice > 3)
                {
                    std::cout << "Invalid choice. Please choose a number between 1 and 3." << std::endl;
                    cin.clear();                                                   // clear the error flag
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
                }
            } while (sauceElementChoice < 1 || sauceElementChoice > 3);

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
