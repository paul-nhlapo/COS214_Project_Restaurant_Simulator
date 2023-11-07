CXX=g++
CFLAGS=-I. -Wall -g -pthread
TARGET=Main
SRCS=Main.cpp Floor.cpp Table.cpp maitreD.cpp Manager.cpp Waiter.cpp Staff.cpp Customer.cpp Individual.cpp Low.cpp Medium.cpp High.cpp Satisfaction.cpp customerFactory.cpp Factory.cpp Command.cpp concreteCommand.cpp Order.cpp OrderFactory.cpp CreditCard.cpp Cash.cpp SimpleOrder.cpp DessertOrderBuilder.cpp StarterOrderBuilder.cpp MainOrderBuilder.cpp Menu.cpp StarterMenu.cpp MainMenu.cpp DessertMenu.cpp UI.cpp Bartender.cpp CocktailOrder.cpp CocktailOrderDetail.cpp AddOn.cpp Cocktail.cpp CocktailMixer.cpp Builder.cpp Base.cpp Type.cpp Ice.cpp Fruit.cpp Bar.cpp Chef.cpp DessertChef.cpp HeadChef.cpp MainChef.cpp StarterChef.cpp ConcreteChefCreator.cpp BusyState.cpp FreeState.cpp Kitchen.cpp StarterOrder.cpp MainOrder.cpp DessertOrder.cpp Grill.cpp Fry.cpp Bake.cpp Boil.cpp Sushi.cpp Saute.cpp Simmer.cpp Salad.cpp NoCook.cpp HotDessert.cpp ColdDessert.cpp MealProduct.cpp MealBuilder.cpp 
OBJS=$(SRCS:.cpp=.o)
TEST_SRCS=my_test.cpp
TEST_OBJS=$(TEST_SRCS:.cpp=.o)
TEST_TARGET=my_test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CFLAGS) $(TEST_OBJS) -o $(TEST_TARGET) -lgtest -lgtest_main -pthread

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(OBJS) $(TEST_TARGET) $(TEST_OBJS)
	clear

	# 