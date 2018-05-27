//
// Created by bob on 27-05-2018.
//

#ifndef ZOMBIEGAME_ACHIEVEMENTS_H
#define ZOMBIEGAME_ACHIEVEMENTS_H

#include <iostream>

#include "Observer.h"

class ZombiesKilled : public Observer{
public:
    virtual void onNotify(Event event, int value = 0);
};

#endif //ZOMBIEGAME_ACHIEVEMENTS_H
