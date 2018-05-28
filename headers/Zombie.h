//
// Created by bob on 18-05-2018.
//

#ifndef ZOMBIEGAME_ZOMBIE_H
#define ZOMBIEGAME_ZOMBIE_H

#include "Game.h"
#include "GameCharacter.h"
#include "Player.h"
#include "Zombie.h"

#include <iostream>
#include <math.h>

#define PI 3.14159265

enum movementType{ randomize, roaming, offensive};

class Zombie;

//MOVEMENT STRATEGY
class MovementStrategy {
public:

    virtual void doMove(Player* player, Game* game, Zombie* zombie, int speed) = 0;

protected:

    //Movement direction
    float moveX;
    float moveY;
};

//MAIN ZOMBIE CLASS
class Zombie : public GameCharacter{
public:

    Zombie(movementType type, Player* player, Game* game, int speed);

    //void move(Player* player, Game* game, int speed = 1);

    void renderSprite(Game* game);


    int getX();
    int getY();
    void setX(int newX);
    void setY(int newY);

    void setMovementStrategy(movementType type, Player* player, Game* game, Zombie* zombie, int speed);
    MovementStrategy* getMovementStrategy();

    MovementStrategy* movementStrategy;

protected:

    //bool offensive = true;
    //int randDirection = 0;
};

//TYPES OF ZOMBIE MOVEMENT
class Roaming : public MovementStrategy{
public:
    Roaming(){ randDirection = rand() % 4; }
    virtual void doMove(Player* player, Game* game, Zombie* zombie, int speed);

private:

    int randDirection = 0;
};

class Offensive : public MovementStrategy{
public:
    virtual void doMove(Player* player, Game* game, Zombie* zombie, int speed);
};

#endif //ZOMBIEGAME_ZOMBIE_H
