//
// Created by bob on 23-05-2018.
//

#ifndef ZOMBIEGAME_POWERS_H
#define ZOMBIEGAME_POWERS_H

#include "PowerUp.h"

class Ammo : public PowerUp {
public:
    Ammo(std::shared_ptr<Game> game);
    void startPower(std::shared_ptr<Game> game) override ;
    void endPower(std::shared_ptr<Game> game) override ;
};

class ZombieOverload : public PowerUp {
public:
    ZombieOverload(std::shared_ptr<Game> game);
    void startPower(std::shared_ptr<Game> game) override ;
    void endPower(std::shared_ptr<Game> game) override ;
};
#endif //ZOMBIEGAME_POWERS_H
