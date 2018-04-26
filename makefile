CC=g++

makeobject: main.cpp
	$(CC) -c main.cpp
	$(CC) main.o -o ZombieGame -lsfml-graphics -lsfml-window -lsfml-system
	./ZombieGame
