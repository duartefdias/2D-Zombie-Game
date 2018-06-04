//
// Created by bob on 18-05-2018.
//

#include "../headers/Zombie.h"

void Zombie::setMovementStrategy(movementType type) {
    switch(type){
        case roaming:
            movementStrategy = std::make_shared<Roaming>();
            break;
        case offensive:
            movementStrategy = std::make_shared<Offensive>();
            break;
        default:
            movementStrategy = std::make_shared<Offensive>();
            break;
    }
}

Zombie::Zombie(movementType type, std::shared_ptr<Player> player, std::shared_ptr<Game> game, int speed) {
    X = 20;
    Y = 20;

    int windowX = game->getWindow().getSize().x;
    int windowY = game->getWindow().getSize().y;

    //Choose side of window where zombie spawns
    int side = rand() % 4;

    switch (side) {
        //Top
        case 0:
            X = rand() % windowX;
            Y = 80;
            break;
            //Right
        case 1:
            X = windowX - 80;
            Y = rand() % windowY;
            break;
            //Down
        case 2:
            X = rand() % windowX;
            Y = windowY-80;
            break;
            //Left
        default:
            X = 80;
            Y = rand() % windowY;
            break;
    }

    //Setup zombie sprite
    spriteTexture.loadFromFile("../assets/sprites/zombie/zombieSprite.png");
    sprite.setTexture(spriteTexture);
    sprite.setTextureRect(sf::IntRect(30, 30, 220, 200)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(95, 85);
    sprite.setPosition(X, Y);

    if(type == randomize){
        int randType = rand() % 2;

        switch(randType){
            case 0:
                type = roaming;
                break;
            case 1:
                type = offensive;
                break;
        }
    }

    //Choose a movement strategy
    setMovementStrategy(type);
}


void Zombie::renderSprite(std::shared_ptr<Game> game) {
    game->getWindow().draw(sprite);
}

int Zombie::getX() {
    return X;
}

int Zombie::getY() {
    return Y;
}

void Zombie::setX(int newX) {
    X = newX;
}

void Zombie::setY(int newY) {
    Y = newY;
}

std::shared_ptr<MovementStrategy> Zombie::getMovementStrategy() {
    return movementStrategy;
}