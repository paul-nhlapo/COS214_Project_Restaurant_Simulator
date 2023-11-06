#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include <list>



class Menu
{
    public:
        Menu();
        virtual ~Menu() {};
        virtual std::string getMenuType() = 0;
        virtual std::string getMainElement();
        virtual std::string getSide();
        virtual std::string getSauce();

        virtual void printMainElementList();
        virtual void printMainElementStrategyList(int selectedMainElement);

        virtual void printSideItemsList();
        virtual void printSauceItemsList();

        struct ItemDetails
        {
            int menuNumber;
            int price;
            std::string MainElement;
            std::vector<std::string> cookingMethods;
        };

        virtual std::vector<ItemDetails> getMainElementItems();
        virtual std::vector<ItemDetails> getSidesItems();
        virtual std::vector<ItemDetails> getSauceItems();      

    protected:
        std::string menuType;
        std::string mainElement;
        std::string side;
        std::string sauce;
        
        std::vector<ItemDetails> mainElementItems;
        std::vector<ItemDetails> sidesItems;
        std::vector<ItemDetails> sauceItems;
};

#endif