startGame: Source.o utils/Board.o
			 g++ -std=c++0x -Wall Source.o utils/Board.o -o startGame

Source.o: Source.cpp
			 g++ -c Source.cpp

Board.o: utils/Board.cpp
			 g++ -c utils/Board.cpp

clean:
			 rm *.o startGame

