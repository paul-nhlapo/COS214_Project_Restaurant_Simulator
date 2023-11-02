#include <iostream>

#include "BasicOrder.h"
#include "MainOrder.h"
#include "Order.h"
#include "ProteinDecorator.h"
#include "SauceDecorator.h"
#include "SideDecorator.h"
#include "VegDecorator.h"

#include "BasicOrder.cpp"
#include "MainOrder.cpp"
#include "ProteinDecorator.cpp"
#include "SauceDecorator.cpp"
#include "SideDecorator.cpp"
#include "VegDecorator.cpp"


int main(){

    BasicOrder b1("soup" , "boil" , "starter");
    //std::cout << b1.print() << std::endl;

    BasicOrder* mstk = new BasicOrder("steak", "grill", "main");
    MainOrder* mainsteak = new ProteinDecorator(mstk);
    //std::cout << mainsteak->print();

    delete mstk;
    delete mainsteak;

    std::cout << "do you want a\n 1.basic order\n2.main order\n";
    int orderType;
    std::cin >> orderType;
    std::cout << "\n\n";

    if(orderType == 1){
        std::cout << "do you want a\n 1.starter \n2.dessert\n";
        int stdes;
        std::cin >> stdes;
        std::cout << "\n\n";

            if(stdes == 1){
            std::cout << "do you want a\n 1.baked \n2.simmer\n";
            int ch;
            std::cin >> ch;
            std::cout << "\n\n";
                if(ch == 1){
                    BasicOrder b1("bread roll" , "baked" , "starter");
                    std::cout << b1.print() << std::endl;
                }
                else{
                    BasicOrder b1("soup" , "simmer" , "starter");
                    std::cout << b1.print() << std::endl;
                }
            }
            else{
                std::cout << "do you want a\n 1.cold \n2.hot\n";
                int ch;
                std::cin >> ch;
                std::cout << "\n\n";
                    if(ch == 1){
                        BasicOrder b1("ice cream" , "cold" , "dessert");
                        std::cout << b1.print() << std::endl;
                    }
                    else{
                        BasicOrder b1("cake" , "hot" , "dessert");
                        std::cout << b1.print() << std::endl;
                    }
            }

    }
    else if(orderType == 2){
        std::cout << "do you want a\n 1.protein \n2.sauce \n3.side \n4.veg\n";
        int stdes;
        std::cin >> stdes;
         std::cout << "\n\n";

            if(stdes == 1){
                std::cout << "do you want a\n 1.grill \n2.fry\n";
                int ch;
                std::cin >> ch;
                 std::cout << "\n\n";

                    if(ch == 1){
                       std::cout << "do you want a\n 1.steak \n2.chicken\n";
                       int ch;
                       std::cin >> ch;
                        std::cout << "\n\n";
                            if(ch==1){
                                BasicOrder* mstk = new BasicOrder("steak", "grill", "main");
                                MainOrder* mainsteak = new ProteinDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                            }
                            else{
                                BasicOrder* mstk = new BasicOrder("chicken", "grill", "main");
                                MainOrder* mainsteak = new ProteinDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;    
                            }
                            
                    }
                    else{
                    std::cout << "do you want a\n 1.fish \n2.ignore this\n";
                       int ch;
                       std::cin >> ch;
                        std::cout << "\n\n";
                       if(ch==1){
                                BasicOrder* mstk = new BasicOrder("fish", "fry", "main");
                                MainOrder* mainsteak = new ProteinDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                            }
                        else{

                        }
                    }
            }
            else if(stdes ==2) {
                std::cout << "do you want a\n 1.simmer \n2.fry\n";
                int ch;
                std::cin >> ch;
                 std::cout << "\n\n";

                    if(ch == 1){
                       std::cout << "do you want a\n 1.red wine \n2.ignore\n";
                       int ch;
                       std::cin >> ch;
                        std::cout << "\n\n";
                            if(ch==1){
                                BasicOrder* mstk = new BasicOrder("red wine", "simmer", "main");
                                MainOrder* mainsteak = new SauceDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                            }
                            else{
                                  
                            }
                            
                    }
                    else{
                    std::cout << "do you want a\n 1.lemon sauce \n2.garlic sauce\n";
                       int ch;
                       std::cin >> ch;
                        std::cout << "\n\n";
                       if(ch==1){
                                BasicOrder* mstk = new BasicOrder("lemon", "fry", "main");
                                MainOrder* mainsteak = new SauceDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                            }
                        else{
                            BasicOrder* mstk = new BasicOrder("garlic", "fry", "main");
                                MainOrder* mainsteak = new SauceDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;  
                        }
                    }
            }
            else if(stdes ==3) {
                std::cout << "do you want a\n 1.boiled \n2.fried \n3.salad\n";
                int ch;
                std::cin >> ch;
                 std::cout << "\n\n";

                    if(ch == 1){
                       std::cout << "do you want a\n 1.rice \n2.ignore\n";
                       int ch;
                       std::cin >> ch;
                        std::cout << "\n\n";
                            if(ch==1){
                                BasicOrder* mstk = new BasicOrder("rice", "boil", "main");
                                MainOrder* mainsteak = new SideDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                            }
                            else{
                                   
                            }
                            
                    }
                    else if(ch==2){
                    std::cout << "do you want a\n 1.chips \n2.ignore this\n";
                       int ch;
                       std::cin >> ch;
                        std::cout << "\n\n";
                       if(ch==1){
                                BasicOrder* mstk = new BasicOrder("chips", "fry", "main");
                                MainOrder* mainsteak = new SideDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                            }
                        else{
                            
                        }
                    }
                    else if(ch==3){
                    std::cout << "do you want a\n 1.salad \n2.ignore this\n";
                       int ch;
                       std::cin >> ch;
                        std::cout << "\n\n";
                       if(ch==1){
                                BasicOrder* mstk = new BasicOrder("salad", "salad", "main");
                                MainOrder* mainsteak = new SideDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                            }
                        else{
                            
                        }
                    }
            }
            else if(stdes ==4) {
                std::cout << "do you want a\n 1.grill \n2.bake\n";
                int ch;
                std::cin >> ch;
                 std::cout << "\n\n";

                    if(ch == 1){
                       std::cout << "do you want a\n 1.mediterranean veg combo \n2.ignore\n";
                       int ch;
                       std::cin >> ch;
                        std::cout << "\n\n";
                            if(ch==1){
                                BasicOrder* mstk = new BasicOrder("mediterranean", "grill", "main");
                                MainOrder* mainsteak = new VegDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                            }
                            else{
                                  
                            }
                            
                    }
                    else{
                    std::cout << "do you want a\n 1.middle east \n2.south africa\n";
                       int ch;
                       std::cin >> ch;
                        std::cout << "\n\n";
                       if(ch==1){
                                BasicOrder* mstk = new BasicOrder("middle east", "bake", "main");
                                MainOrder* mainsteak = new VegDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                            }
                        else{
                                BasicOrder* mstk = new BasicOrder("south africa", "bake", "main");
                                MainOrder* mainsteak = new VegDecorator(mstk);
                                std::cout << mainsteak->print();
                                delete mstk;
                                delete mainsteak;
                        }
                    }
            }
    }
    else std::cout << "choose properly\n\n";


}