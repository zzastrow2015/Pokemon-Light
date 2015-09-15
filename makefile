main: main.o Pokemon.o Dice.o
	g++ -g -o main main.o Pokemon.o Dice.o

main.o: main.cpp Pokemon.cpp Dice.cpp
	g++ -g -c main.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -g -c Pokemon.cpp

Dice.o: Dice.h Dice.cpp
	g++ -g -c Dice.cpp

clean: rm *.o
