CXX=c++11
LDLIBS=-lcurses

all: test server client game 

game:game.cpp Card.h Deck.h gameScreen.h global.h Player.h game.h
	$(CXX) -o game -Wall game.cpp $(LDLIBS)

alt:alt.cpp
	c++11 -o alt -Wall alt.cpp -lcurses

client:client.cpp
	c++11 -o client -Wall client.cpp -lcurses

server:server.cpp
	c++11 -o server -Wall server.cpp -lpthread -lcurses
