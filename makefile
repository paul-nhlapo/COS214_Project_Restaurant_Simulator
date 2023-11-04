main: *.cpp
	 g++ -std=c++11 *.cpp -o main
	
run: main
	./main

clean:
	rm *.o main