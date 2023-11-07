
#include "MainOrder.h"

MainOrder::MainOrder(std::string mainElement, std::string cookingMethod, std::string side, std::string sauce)
{
    this->mainElement = mainElement;
    this->cookingMethod = cookingMethod;
    this->side = side;
    this->sauce = sauce;

    this->orderType = "Main";
    this->price = 100.0;
}

std::string MainOrder::getOrderType()
{
    return this->orderType;
}
