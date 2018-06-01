//
// Created by bob on 18-05-2018.
//

#ifndef ZOMBIEGAME_PLAYER_H
#define ZOMBIEGAME_PLAYER_H

#include <memory>
#include "Game.h"
#include "GameCharacter.h"

class Player : public GameCharacter{
public:

    Player(int x, int y);

    //Movement
    void move(std::shared_ptr<Game> game, float speed = 1);
    void rotate(std::shared_ptr<Game> game);

    bool shoot();

    void kill();

private:
};

#endif //ZOMBIEGAME_PLAYER_H
