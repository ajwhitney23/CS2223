all: clean game

game: bot.cpp player.cpp board.cpp production.cpp main.cpp
	g++ bot.cpp player.cpp board.cpp production.cpp main.cpp -o game

clean: 
	rm -f *.o game