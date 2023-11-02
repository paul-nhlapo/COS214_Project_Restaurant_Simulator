#include "Bartender.h"
#include <string>
#include <vector>
using namespace std;

Bartender::Bartender()
{
    this->b1 = new CocktailMixer();
}

Bartender::~Bartender()
{
    delete this->b1;
}

void Bartender::mix(Order *order)
{
    string base;
    string type;
    string ice;
    string fruit;

    Order *current = order;
    while (current != nullptr)
    {
        if (current->type == "Base")
        {
            base = current->name;
        }
        else if (current->type == "Type")
        {
            type = current->name;
        }
        else if (current->type == "Ice")
        {
            ice = current->name;
        }
        else if (current->type == "Fruit")
        {
            fruit = current->name;
        }

        if (dynamic_cast<AddOn *>(current) != nullptr)
        {
            current = dynamic_cast<AddOn *>(current)->nextItem;
        }
        else
        {
            current = nullptr;
        }
    }

    b1->setBase(base);
    b1->setType(type);
    b1->setIce(ice);
    b1->setFruit(fruit);
}

Cocktail* Bartender::getDrink()
{
    return b1->getProduct();
}

void Bartender::setBuilder(Builder* b)
{
    this->b1 = b;
}
