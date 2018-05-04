CC = g++

CFILES = src/*

# header files
IFILES = headers/*

#sfml includes
SFML = 	-lsfml-graphics \
		-lsfml-window	\
		-lsfml-system	\

makeobject: $(CFILES) $(IFILES)
	#$(CC) -c src/main.cpp src/Game.cpp headers/Game.h
	$(CC) -I$(IFILES) $(CFILES)  -o ZombieGame.exe -lsfml-graphics -lsfml-window -lsfml-system -g
	./ZombieGame.exe
