#include "Bartender.h"
#include "Order.h"
#include "OrderDetail.h"
#include "AddOn.h"
#include "Cocktail.h"
#include "CocktailMixer.h"
#include "Builder.h"
#include "Base.h"
#include "Type.h"
#include "Ice.h"
#include "Fruit.h"
#include "Bar.h"
using namespace std;

int main()
{
    CocktailMixer *cm1 = new CocktailMixer();
    Bartender *b1 = new Bartender();
    b1->setBuilder(cm1);
    Bar *bar_ = new Bar();
    bar_->setBarTender(b1);
    bar_->placeOrder();

    delete bar_;
    // delete b1;
    // delete cm1;
    return 0;
}