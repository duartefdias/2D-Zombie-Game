//
// Created by bob on 23-05-2018.
//

#include "../headers/PowerUp.h"
#include "../headers/Powers.h"

//POWERUP

PowerUp::PowerUp(std::shared_ptr<Game> game) {

    X = rand() % game->getWindow().getSize().x;
    Y = rand() % game->getWindow().getSize().y;
}

std::shared_ptr<PowerUp> PowerUp::makePowerUp(std::shared_ptr<Game> game, int type){
    switch(type){
        case 0:
            return std::make_shared<Ammo>(game);
            break;
        default:
            return std::make_shared<ZombieOverload>(game);
            break;
    }
}

int PowerUp::getX() {
    return X;
}

int PowerUp::getY() {
    return Y;
}

void PowerUp::renderSprite(std::shared_ptr<Game> game) {
    game->getWindow().draw(sprite);
}
