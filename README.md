## Zombie Survival Game

In this game you control a 2D character through a top-view whose objective is to survive the longest.
The character can shoot bullets whose speed and direction are controlled by the mouse.
If a zombie touches the character the game ends.

![Screenshot](https://github.com/DuarteDx/2D-Zombie-Game/blob/master/misc/screenshot2.png)

## Try the game

Requirements:
- [X] SFML
- [X] Linux terminal
- [X] A mouse

To install SFML just run the following command:

    sudo apt-get install libsfml-dev

Using a laptop's touchpad doesn't allow you to move and shot at the same time.

To try the game [download](https://github.com/DuarteDx/2D-Zombie-Game/archive/master.zip) this repository, cd into it and run it:

    cd 2D-Zombie-Game
    ./ZombieGame.exe

You can try previous versions such as "ZombieGame2.0.exe":

    ./ZombieGame2.0.exe

To compile the project and run it's output you can use the make method:

    cd 2D-Zombie-Game
    make makeobject

Or to compile and run it using [Valgrind](http://valgrind.org/) to check memory leaks:

    cd 2D-Zombie-Game
    make valgrind

## UML

![UML](https://github.com/DuarteDx/2D-Zombie-Game/blob/master/UML/UML1.jpg)

This might not be the most updated version of the UML but it will probabbly be quite similar.

## Development environment

This game was developed in C++ using mainly the text editor [Atom](atom.io) and the [DDD](www.gnu.org/software/ddd/) debuger.

## Bug Reporting

If you find any bugs please describe them in the ["Issues" section](https://github.com/DuarteDx/2D-Zombie-Game/issues) of this repository.
