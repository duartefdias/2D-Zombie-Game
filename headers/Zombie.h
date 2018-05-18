//
// Created by bob on 18-05-2018.
//

#ifndef ZOMBIEGAME_ZOMBIE_H
#define ZOMBIEGAME_ZOMBIE_H

#include "Game.h"
#include "GameCharacter.h"
#include "Player.h"

#include <iostream>
#include <math.h>

#define PI 3.14159265

class Zombie : GameCharacter{
public:

    Zombie(Game* game);

    void move(Player* player, int speed = 1);

    void renderSprite(Game* game);

    int getX();
    int getY();

private:

    //Movement direction
    float moveX;
    float moveY;

};

#endif //ZOMBIEGAME_ZOMBIE_H
