#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>

class Order{

    public:
        virtual ~Order() = 0;

        virtual std::string print() = 0;

        virtual double getCost() = 0;
        virtual double getTimeToPrep() = 0;
        virtual std::string getDish() = 0;
        virtual std::string getStrategy() = 0;
        virtual std::string getChef() = 0;

        virtual void setCost(double) = 0;
        virtual void setTimeToPrep(double) = 0;
        virtual void setDish(std::string) = 0;
        virtual void setStrategy(std::string) = 0;
        virtual void setChef(std::string) = 0;


    /*
        Menu
            main - chef
                protien - type
                    fish - dish
                    steak
                    chicken
                    pork
                side
                    chips
                    rice
                    salad

                sauce
                    mushroom 
                    red wine
                    white wine
                    garlic butter
                veg
                    veg combo 1
                    veg combo 2
            starter - chef
                soup - dish
                bread rolls - dish
            dessert - chef
                ice cream
                choc cake
            drink - chef
                water
                cooldrink


    strat : fried salad bake boil grill sushi simmer colddesset hotdessert

    - add costs , base 
    - time to prep , base 
    - printDetails , base (altered)

    - type (main,start,etc) , dec
    - prep strat , dec
    - chef needed , dec

    orderdetail has default implementations of each menu item, if the person
        doesnt specify what method they want

    use the decorator to specify cooking strategies

    ---------------
    orderdetail specifies starter dessert and drink w/ default for all
    addOn turns into main
        main can then have each protien side and sauce as concDec

    */



};

#endif