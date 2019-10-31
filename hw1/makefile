all: clean nim

nim: bot.cpp player.cpp board.cpp production.cpp main.cpp
	g++ bot.cpp player.cpp board.cpp production.cpp main.cpp -o nim

clean: 
	rm -f *.o nim