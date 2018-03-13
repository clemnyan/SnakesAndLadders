# Makefile for the SnakesAndLadders Program
# Clement Nyanhongo

startGame: Source.o utils/Board.o utils/Snake.o utils/Ladder.o utils/Dice.o
	g++ -std=c++0x -Wall Source.o utils/Board.o utils/Snake.o utils/Ladder.o utils/Dice.o -o startGame

Source.o: Source.cpp
	g++ -c Source.cpp

Board.o: utils/Board.cpp
	g++ -c utils/Board.cpp

Snake.o: utils/Snake.cpp
	g++ -c utils/Snake.cpp

Ladder.o: utils/Ladder.cpp
	g++ -c utils/Ladder.cpp

Dice.o: utils/Dice.cpp
	g++ -c utils/Dice.cpp

clean:
	rm *.o startGame

