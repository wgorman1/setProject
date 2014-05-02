CXX=c++11
LDLIBS=-lcurses

all: game alt test

game:game.cpp Card.h Deck.h gameScreen.h global.h Player.h
	$(CXX) -o game -Wall game.cpp $(LDLIBS)

alt:alt.cpp
	c++11 -o alt -Wall alt.cpp -lcurses

test:test.cpp
	c++11 -o test -Wall test.cpp -lcurses
