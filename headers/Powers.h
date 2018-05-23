//
// Created by bob on 23-05-2018.
//

#ifndef ZOMBIEGAME_POWERS_H
#define ZOMBIEGAME_POWERS_H

#include "PowerUp.h"

class Ammo : PowerUp {
public:
    Ammo(Game *game);
    void startPower(Game* game);
    void endPower(Game* game);
};
#endif //ZOMBIEGAME_POWERS_H
