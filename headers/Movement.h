//
// Created by bob on 23-05-2018.
//

#ifndef ZOMBIEGAME_MOVEMENT_H
#define ZOMBIEGAME_MOVEMENT_H

#include "Game.h"
#include "GameCharacter.h"
#include "Player.h"

#include <iostream>
#include <math.h>

class Movement{
public:

    //Defines type of zombie movement
    Movement();

    void move(Player* player, int speed = 1);

protected:

    bool offensive = true;
};

#endif //ZOMBIEGAME_MOVEMENT_H