//
// Created by bob on 23-05-2018.
//

#ifndef ZOMBIEGAME_POWERS_H
#define ZOMBIEGAME_POWERS_H

#include "PowerUp.h"

class Ammo : public PowerUp {
public:
    Ammo(Game *game);
    void startPower(Game* game) override ;
    void endPower(Game* game) override ;
};

class ZombieOverload : public PowerUp {
public:
    ZombieOverload(Game * game);
    void startPower(Game* game) override ;
    void endPower(Game* game) override ;
};
#endif //ZOMBIEGAME_POWERS_H
