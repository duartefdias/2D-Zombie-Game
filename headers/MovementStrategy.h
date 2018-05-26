//
// Created by bob on 26-05-2018.
//

#ifndef ZOMBIEGAME_MOVEMENTSTRATEGY_H
#define ZOMBIEGAME_MOVEMENTSTRATEGY_H

#include "GameCharacter.h"
#include "Player.h"
#include "Game.h"
#include "Zombie.h"

class MovementStrategy {
public:

    virtual void doMove(Player* player, Game* game, Zombie* zombie, int speed) = 0;

protected:

    //Movement direction
    float moveX;
    float moveY;
};

#endif //ZOMBIEGAME_MOVEMENTSTRATEGY_H
