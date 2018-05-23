//
// Created by bob on 23-05-2018.
//

#include "../headers/PowerUp.h"

//POWERUP

PowerUp::PowerUp(Game* game) {

    X = rand() % game->getWindow().getSize().x;
    Y = rand() % game->getWindow().getSize().y;
}

PowerUp *PowerUp::makePowerUp(Game* game, int type){
    switch(type){
        case 0:
            return new Ammo(game);
            break;
        default:
            //return new ZombieOverload;
            break;
    }
}

int PowerUp::getX() {
    return X;
}

int PowerUp::getY() {
    return Y;
}

void PowerUp::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
}
