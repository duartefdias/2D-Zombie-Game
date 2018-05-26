//
// Created by bob on 26-05-2018.
//

#ifndef ZOMBIEGAME_MOVEMENTTYPES_H
#define ZOMBIEGAME_MOVEMENTTYPES_H

#include "MovementStrategy.h"
#include "Player.h"
#include "Game.h"


class Roaming : public MovementStrategy{
public:

    virtual void doMove(Player* player, Game* game, Zombie* zombie, int speed);
};

class Offensive : public MovementStrategy{
public:
    virtual void doMove(Player* player, Game* game, Zombie* zombie, int speed);
};

#endif //ZOMBIEGAME_MOVEMENTTYPES_H
