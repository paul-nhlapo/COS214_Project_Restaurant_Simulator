#include "Bar.h"
#include <string>
#include <vector>
using namespace std;

Bar::Bar()
{
    this->b1 = new Bartender();
}

Bar::~Bar()
{
    delete this->b1;
}

void Bar::setBarTender(Bartender *b)
{
    this->b1 = b;
}

void Bar::placeCocktailOrder()
{
    string base;
    string type;
    string ice;
    string fruit;
    cout << "Choose a base: " << endl;
    cout << "1. Rum" << endl
         << "2. Vodka" << endl
         << "3. Gin";
    cout << endl;

    int choice1;
    cin >> choice1;

    switch (choice1)
    {
    case 1:
        base = "Rum";
        break;
    case 2:
        base = "Vodka";
        break;
    case 3:
        base = "Gin";
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
    cout << endl;
    cout << "Choose a type: " << endl
         << "1. Shaken" << endl
         << "2. Stirred" << endl;
    cout << endl;
    int choice2;
    cin >> choice2;

    switch (choice2)
    {
    case 1:
        type = "Shaken";
        break;
    case 2:
        type = "Stirred";
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    cout << "How would you like your ice? " << endl
         << "1. Crushed" << endl
         << "2. Cubed" << endl
         << "3. No Ice" << endl;
    cout << endl;

    int choice3;
    cin >> choice3;

    switch (choice3)
    {
    case 1:
        ice = "Crushed";
        break;
    case 2:
        ice = "Cubed";
        break;
    case 3:
        ice = "No ";
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    cout << "What fruit would you like to add on the side?" << endl
         << "1. Cherry" << endl
         << "2. Orange Slices" << endl
         << "3. Blueberry" << endl;
    cout << endl;
    int choice4;
    cin >> choice4;

    switch (choice4)
    {
    case 1:
        fruit = "Cherries";
        break;
    case 2:
        fruit = "Orange Slices";
        break;
    case 3:
        fruit = "Blueberries";
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    Base *baseO = new Base(base);
    Type *typeO = new Type(type);
    Ice *iceO = new Ice(ice);
    Fruit *fruitO = new Fruit(fruit);
    baseO->setNextItem(typeO);
    typeO->setNextItem(iceO);
    iceO->setNextItem(fruitO);
    b1->mix(baseO);
    serve();
}

Cocktail *Bar::serve()
{
    this->b1->getDrink()->printCocktail();
    return this->b1->getDrink();
}