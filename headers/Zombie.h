//
// Created by bob on 18-05-2018.
//

#ifndef ZOMBIEGAME_ZOMBIE_H
#define ZOMBIEGAME_ZOMBIE_H

#include "Game.h"
#include "GameCharacter.h"
#include "Player.h"
#include "MovementStrategy.h"
#include "MovementTypes.h"

#include <iostream>
#include <math.h>

#define PI 3.14159265

enum movementType{ randomize, roaming, offensive};

class Zombie : GameCharacter{
public:

    Zombie(movementType type, Player* player, Game* game, Zombie* zombie, int speed);

    //void move(Player* player, Game* game, int speed = 1);

    void renderSprite(Game* game);


    int getX();
    int getY();
    void setX(int newX);
    void setY(int newY);

    void setMovementStrategy(movementType type, Player* player, Game* game, Zombie* zombie, int speed);
    MovementStrategy::MovementStrategy* getMovementStrategy();

protected:

    //bool offensive = true;
    //int randDirection = 0;

    MovementStrategy::MovementStrategy* movementStrategy;
};

#endif //ZOMBIEGAME_ZOMBIE_H
