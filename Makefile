build: battleship.c
	gcc battleship.c -o battleship -lncurses -g  -Wall -lm
run: battleship
	./battleship map1 map2 map3 map4 map5
clean: battleship
	rm battleship
