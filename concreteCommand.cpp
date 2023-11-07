#include "concreteCommand.h"
#include <string>
#include <vector>
using namespace std;

concreteCommand::concreteCommand::concreteCommand(maitreD *md, Floor *f, customerFactory *cf, OrderFactory *of)
{
    this->floor = f;
    this->md = md;
    this->cf = cf;
    this->of = of;

    kitchen = new Kitchen();

    headChefCreator = new HeadChefCreator();
    starterChefCreator = new StarterChefCreator();
    mainChefCreator = new MainChefCreator();
    dessertChefCreator = new DessertChefCreator();

    Chef *xheadChef = headChefCreator->createChef("Head Chef", kitchen);
    this->headChef = dynamic_cast<HeadChef *>(xheadChef);

    Chef *xstarterChef = starterChefCreator->createChef("Starter Chef", kitchen);
    this->starterChef = dynamic_cast<StarterChef *>(xstarterChef);

    Chef *xmainChef = mainChefCreator->createChef("Main Chef", kitchen);
    this->mainChef = dynamic_cast<MainChef *>(xmainChef);

    Chef *xdessertChef = dessertChefCreator->createChef("Dessert Chef", kitchen);
    this->dessertChef = dynamic_cast<DessertChef *>(xdessertChef);

    starterChef->headChef = headChef;
    mainChef->headChef = headChef;
    dessertChef->headChef = headChef;

    headChef->setNextChef(starterChef);
    starterChef->setNextChef(mainChef);
    mainChef->setNextChef(dessertChef);

    for (int i = 0; i < floor->numRows; i++)
    {
        for (int j = 0; j < floor->numCols; j++)
        {
            this->kitchen->addStaff(floor->getTable(i, j)->myWaiter);
        }
    }
}

concreteCommand::~concreteCommand()
{
    delete floor;
    delete md;
    delete cf;
}

Customer *concreteCommand::produceCustomer(char group)
{
    if (group == '!')
    {
        Customer *res = cf->getIndividualCustomer();
        seatCustomer(res);
        return res;
    }
    else
    {
        Customer *res = cf->getMultiCustomers(group);
        // seatCustomer(res);
        return res;
    }
}

void concreteCommand::seatCustomer(Customer *c)
{
    cout << "Would you like to reserve a table? " << endl;
    cout << "Y or N";
    cout << endl;
    char response;
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
        int _x;
        int _y;
        cout << "Choose your location: " << endl;
        cout << "Row: 1, 2, 3, 4: " << endl;
        cin >> _x;
        cout << "Isle: 1, 2, 3, 4: " << endl;
        cin >> _y;
        c->makeReservation(_x - 1, _y - 1, md);
        md->seat(c);
    }
    else
    {
        cout << "The next available table will be allocated to you" << endl;
        pair<int, int> work = md->findNext();
        c->makeReservation(work.first, work.second, md);
        md->seat(c);
    }
}

void concreteCommand::seatMultipleCustomers(int x, int y, Customer *c)
{
    this->floor->getTable(x, y)->addCustomer(c);
}

pair<int, int> concreteCommand::reserveGroupTable()
{
    cout << "Would you like to reserve a table? " << endl;
    cout << "Y or N";
    cout << endl;
    char response;
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
        int x;
        int y;
        cout << "Choose your location: " << endl;
        cout << "Row: 1, 2, 3, 4: " << endl;
        cin >> x;
        cout << "Isle: 1, 2, 3, 4: " << endl;
        cin >> y;
        x -= 1;
        y -= 1;
        if (md->reserve(x, y))
        {
            pair<int, int> result;
            result.first = x;
            result.second = y;
            return result;
        }
        else
        {
            cout << "Table not available" << endl;
            cout << "The next available table will allocated to you" << endl;
            pair<int, int> result = md->findNext();
            return result;
        }
    }
    else
    {
        cout << "The next available table will allocated to you" << endl;
        pair<int, int> result = md->findNext();
        return result;
    }
}

char concreteCommand::getGroupID()
{
    return this->cf->getGID();
}

char concreteCommand::setGroupID()
{
    this->cf->nextGroupID++;
}

void concreteCommand::startOrdering()
{
    int x;
    int y;
    cout << "Choose your location: " << endl;
    cout << "Row: 1, 2, 3, 4: " << endl;
    cin >> x;
    cout << "Isle: 1, 2, 3, 4: " << endl;
    cin >> y;
    x--;
    y--;
    if (x >= 0 && y >= 0 && x < this->floor->numRows && y < this->floor->numCols)
    {
        char userChoice;
        if (this->floor->getTable(x, y)->hasCustomer)
        {
            do
            {
                this->floor->getTable(x, y)->order = this->of->getOrder(this->floor->getTable(x, y));
                cout << "Do you want to continue ordering? (y/n): ";
                cin >> userChoice;
            } while (userChoice == 'y' || userChoice == 'Y');
            this->floor->getTable(x, y)->placedOrder = true;
            this->floor->getTable(x, y)->bill = this->floor->getTable(x, y)->getBill();
            this->floor->getTable(x, y)->sendOrder(this->floor->getTable(x, y)->myWaiter);
            this->floor->getTable(x, y)->myWaiter->printOrders();
            for (int i = 0; i < this->floor->getTable(x, y)->myWaiter->orders.size(); i++)
            {
                this->kitchen->sendToKitchen(this->floor->getTable(x, y)->myWaiter->orders[i], this->headChef);
            }
            // for (int j = 0; j < this->floor->getTable(x, y)->myWaiter->meals.size(); j++)
            // {
            //     this->floor->getTable(x, y)->myWaiter->deliverMeal(this->floor->getTable(x, y)->myWaiter->meals[j]);
            // }
            this->floor->getTable(x, y)->askForTheCheque(this->floor->getTable(x, y)->myWaiter);
            return;
        }
        else
        {
            cout << "This table has no customers, please try again" << endl;
            startOrdering();
        }
    }
    else
    {
        cout << "Invalid selection" << endl;
    }
}

bool concreteCommand::verify()
{
    int x;
    int y;
    cout << "Choose your location: " << endl;
    cout << "Row: 1, 2, 3, 4: " << endl;
    cin >> x;
    cout << "Isle: 1, 2, 3, 4: " << endl;
    cin >> y;

    x--;
    y--;
    if (x >= 0 && y >= 0 && x < this->floor->numRows && y < this->floor->numCols)
    {
        char userChoice;
        if (this->floor->getTable(x, y)->hasCustomer)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}