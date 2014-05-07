CXX=c++11
LDLIBS=-lcurses

all: test client server

game:game.cpp Card.h Deck.h gameScreen.h global.h Player.h
	$(CXX) -o game -Wall -pthread game.cpp $(LDLIBS)

alt:alt.cpp
	c++11 -o alt -Wall alt.cpp -lcurses

client:client.cpp Card.h Deck.h gameScreen.h global.h Player.h
	c++11 -o client -Wall -pthread client.cpp -lcurses 

server:server.cpp
	c++11 -o server -Wall server.cpp -lpthread -lcurses
