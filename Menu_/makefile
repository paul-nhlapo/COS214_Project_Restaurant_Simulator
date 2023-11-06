CXX=g++
CFLAGS=-I. -Wall -g -pthread
TARGET=main
SRCS=orderMainTesting.cpp Chef.cpp DessertChef.cpp HeadChef.cpp MainChef.cpp StarterChef.cpp ConcreteChefCreator.cpp BusyState.cpp FreeState.cpp Kitchen.cpp SimpleOrder.cpp StarterOrder.cpp MainOrder.cpp DessertOrder.cpp Menu.cpp StarterMenu.cpp MainMenu.cpp DessertMenu.cpp Staff.cpp Waiter.cpp StarterOrderBuilder.cpp MainOrderBuilder.cpp DessertOrderBuilder.cpp Grill.cpp Fry.cpp Bake.cpp Boil.cpp Sushi.cpp Saute.cpp Simmer.cpp Salad.cpp NoCook.cpp HotDessert.cpp ColdDessert.cpp MealProduct.cpp MealBuilder.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
	clear