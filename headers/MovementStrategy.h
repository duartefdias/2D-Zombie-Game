//
// Created by bob on 26-05-2018.
//

#ifndef ZOMBIEGAME_MOVEMENTSTRATEGY_H
#define ZOMBIEGAME_MOVEMENTSTRATEGY_H

#include "GameCharacter.h"
#include "Zombie.h"
#include "Player.h"
#include "Game.h"




class MovementStrategy {
public:

    virtual void doMove(Player* player, Game* game, Zombie* zombie, int speed) = 0;
};

#endif //ZOMBIEGAME_MOVEMENTSTRATEGY_H
