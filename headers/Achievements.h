//
// Created by bob on 27-05-2018.
//

#ifndef ZOMBIEGAME_ACHIEVEMENTS_H
#define ZOMBIEGAME_ACHIEVEMENTS_H

#include <iostream>

#include "Observer.h"

class ZombiesKilled : public Observer{
public:
    virtual void onNotify(Game* game, Event event, int value = 0);

private:

    std::string text = "efef";
    bool runOnce = false;
};

class TimeSurvived : public Observer{
public:
    virtual void onNotify(Game* game, Event event, int value = 0);
};

#endif //ZOMBIEGAME_ACHIEVEMENTS_H
