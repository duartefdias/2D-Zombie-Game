//
// Created by bob on 18-05-2018.
//

#include "../headers/Zombie.h"

void Zombie::setMovementStrategy(movementType type, std::shared_ptr<Player> player, std::shared_ptr<Game> game, Zombie* zombie, int speed) {
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
    setMovementStrategy(type, player, game, this, speed);
}

/*void Zombie::move(Player* player, std::shared_ptr<Game> game, int speed) {
    float angle = 0;

    if(!offensive) {
        //Zombie moves randomly
        int maxX = game->getWindow().getSize().x;
        int maxY = game->getWindow().getSize().y;
        switch (randDirection) {
            case 0:
                moveX = 0;
                moveY = -0.5;
                angle = -90.0;
                if (Y < 10) {
                    randDirection = 2;
                }
                break;
            case 1:
                moveX = 0.5;
                moveY = 0;
                angle = 0;
                if (X > maxX - 10) {
                    randDirection = 3;
                }
                break;
            case 2:
                moveX = 0;
                moveY = 0.5;
                angle = 90;
                if (Y > maxY - 10) {
                    randDirection = 0;
                }
                break;
            case 3:
                moveX = -0.5;
                moveY = 0;
                angle = 180;
                if (X < 10) {
                    randDirection = 1;
                }
                break;
        }
    }
        //Zombie moves torwards player
        else if(offensive) {
        //Based on linear interpolation
        moveX = player->getX() - X;
        moveY = player->getY() - Y;
        moveX = moveX / 200;
        moveY = moveY / 200;

        if (moveX == 0 && moveY == 0) {
            moveX = 1;
        }

        //Calculate angle
        angle = atan2(player->getY() - Y, player->getX() - X);
        angle *= 180 / PI;
    }


    X += (moveX * speed);
    Y += (moveY * speed);
    sprite.setRotation(angle);

    //std::cout << "moveX: " << moveX*speed << std::endl;
    //std::cout << "moveY: " << moveY*speed << std::endl;

    sprite.setPosition(X, Y);
}*/

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