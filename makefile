CXX=g++
CFLAGS=-I. -Wall -g -pthread
TARGET=Main
SRCS=Main.cpp Floor.cpp Table.cpp maitreD.cpp Manager.cpp Waiter.cpp Staff.cpp Customer.cpp Individual.cpp Low.cpp Medium.cpp High.cpp Satisfaction.cpp customerFactory.cpp Factory.cpp Command.cpp concreteCommand.cpp Order.cpp MainOrder.cpp OrderFactory.cpp CreditCard.cpp Cash.cpp SimpleOrder.cpp DessertOrderBuilder.cpp StarterOrderBuilder.cpp MainOrderBuilder.cpp Menu.cpp StarterMenu.cpp MainMenu.cpp DessertMenu.cpp UI.cpp
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