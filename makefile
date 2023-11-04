run: main
	./main

main: main.o Chef.o DessertChef.o HeadChef.o MainChef.o StarterChef.o ConcreteChefCreator.o BusyState.o FreeState.o Kitchen.o SimpleOrder.o StarterOrder.o MainOrder.o DessertOrder.o
	g++ -static main.o Chef.o DessertChef.o HeadChef.o MainChef.o StarterChef.o ConcreteChefCreator.o BusyState.o FreeState.o Kitchen.o SimpleOrder.o StarterOrder.o MainOrder.o DessertOrder.o -o main

main.o:	main.cpp Chef.h DessertChef.h HeadChef.h MainChef.h StarterChef.h ConcreteChefCreator.h BusyState.h FreeState.h Kitchen.h SimpleOrder.h StarterOrder.h MainOrder.h DessertOrder.h
	g++ -c main.cpp

Chef.o: Chef.cpp Chef.h
	g++ -c Chef.cpp

DessertChef.o: DessertChef.cpp DessertChef.h
	g++ -c DessertChef.cpp

ConcreteChefCreator.o: ConcreteChefCreator.cpp ConcreteChefCreator.h
	g++ -c ConcreteChefCreator.cpp

HeadChef.o: HeadChef.cpp HeadChef.h
	g++ -c HeadChef.cpp

MainChef.o: MainChef.cpp MainChef.h
	g++ -c MainChef.cpp

StarterChef.o: StarterChef.cpp StarterChef.h
	g++ -c StarterChef.cpp

BusyState.o: BusyState.cpp BusyState.h
	g++ -c BusyState.cpp

FreeState.o: FreeState.cpp FreeState.h
	g++ -c FreeState.cpp

Kitchen.o: Kitchen.cpp Kitchen.h
	g++ -c Kitchen.cpp

SimpleOrder.o: SimpleOrder.cpp SimpleOrder.h
	g++ -c SimpleOrder.cpp

StarterOrder.o: StarterOrder.cpp StarterOrder.h
	g++ -c StarterOrder.cpp

MainOrder.o: MainOrder.cpp MainOrder.h
	g++ -c MainOrder.cpp

DessertOrder.o: DessertOrder.cpp DessertOrder.h
	g++ -c DessertOrder.cpp

clean:
	rm -f *.o