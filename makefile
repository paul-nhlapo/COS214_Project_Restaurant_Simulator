run: main
	./main

main: main.o Chef.o DessertChef.o HeadChef.o MainChef.o StarterChef.o ConcreteChefCreator.o
	g++ -static main.o Chef.o DessertChef.o HeadChef.o MainChef.o StarterChef.o ConcreteChefCreator.o -o main

main.o:	main.cpp Chef.h DessertChef.h HeadChef.h MainChef.h StarterChef.h ConcreteChefCreator.h
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

clean:
	rm -f *.o