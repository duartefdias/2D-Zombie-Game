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

enum movementType{ roaming = 1, offensive = 2};

class Zombie : GameCharacter{
public:

    Zombie(Game* game);

    void move(Player* player, Game* game, int speed = 1);

    void renderSprite(Game* game);

    int getX();
    int getY();

    void becomeOffensive();

    void setMovementStrategy(movementType type, Player *player, Game *game, Zombie* zombie, int speed);

protected:

    //Movement direction
    float moveX;
    float moveY;

    bool offensive = true;
    int randDirection = 0;

    MovementStrategy* movementStrategy;
};

#endif //ZOMBIEGAME_ZOMBIE_H
