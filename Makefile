CXX=c++11
LDLIBS=-lcurses

all: client server game alt test

client:client.cpp
	c++11 -o client -Wall client.cpp

server:server.cpp
	c++11 -o server -Wall server.cpp

game:game.cpp Card.h Deck.h gameScreen.h global.h Player.h
	$(CXX) -o game -Wall game.cpp $(LDLIBS)

alt:alt.cpp
	c++11 -o alt -Wall alt.cpp -lcurses

test:test.cpp
	c++11 -o test -Wall test.cpp -lcurses
