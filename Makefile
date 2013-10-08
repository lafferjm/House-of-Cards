flags = `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -g

Run: button.o main.o card.o game.o blackjack.o poker.o inbetween.o chip.o slots.o functions.o
	g++ button.o main.o card.o game.o blackjack.o poker.o inbetween.o chip.o slots.o functions.o $(flags) -o Run

button.o: classes/button.cpp classes/button.h
	g++ classes/button.cpp -c $(flags)

main.o: main.cpp functions.h
	g++ main.cpp -c $(flags)

card.o: classes/card.h classes/card.cpp
	g++ classes/card.cpp -c $(flags)

game.o: classes/game.h classes/game.cpp classes/card.h classes/card.cpp
	g++ classes/game.cpp -c $(flags)

blackjack.o: classes/blackjack.h classes/blackjack.cpp classes/game.h classes/game.cpp
	g++ classes/blackjack.cpp -c $(flags)

poker.o: classes/poker.h classes/poker.cpp classes/game.h classes/game.cpp
	g++ classes/poker.cpp -c $(flags)

inbetween.o: classes/inbetween.h classes/inbetween.cpp classes/game.h classes/game.cpp
	g++ classes/inbetween.cpp -c $(flags)

chip.o: classes/chip.h classes/chip.cpp
	g++ classes/chip.cpp -c $(flags)

slots.o: classes/slots.h classes/slots.cpp
	g++ classes/slots.cpp -c $(flags)

functions.o: functions.h functions.cpp
	g++ functions.cpp -c $(flags)

clean:
	rm *.o Run
