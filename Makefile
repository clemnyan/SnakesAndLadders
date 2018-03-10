startGame: Source.o Board.o
			 g++ -std=c++0x -Wall Source.o Board.o -o startGame

Source.o: Source.cpp
			 g++ -c Source.cpp

Board.o: Board.cpp
			 g++ -c Board.cpp

clean:
			 rm *.o startGame

