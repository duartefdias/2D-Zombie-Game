//
// Created by bob on 23-05-2018.
//

#include "../headers/Powers.h"

//AMMO

Ammo::Ammo(std::shared_ptr<Game> game) : PowerUp(game) {
    spriteTexture.loadFromFile("../assets/sprites/powerups/gun.png");
    sprite.setTexture(spriteTexture);
    //sprite.setTextureRect(sf::IntRect(30, 30, 220, 200)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.7, 0.7);
    sprite.setOrigin(95, 85);
    sprite.setPosition(X, Y);
}

void Ammo::startPower(std::shared_ptr<Game> game) {
    game->setBulletFrequency(100);
}

void Ammo::endPower(std::shared_ptr<Game> game) {
    game->setBulletFrequency(game->getBulletFrequencyAux());
    delete this;
}


//ZOMBIEOVERDOSE

ZombieOverload::ZombieOverload(std::shared_ptr<Game> game) : PowerUp(game) {
    spriteTexture.loadFromFile("../assets/sprites/powerups/graves.png");
    sprite.setTexture(spriteTexture);
    //sprite.setTextureRect(sf::IntRect(30, 30, 220, 200)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.6, 0.6);
    sprite.setOrigin(95, 85);
    sprite.setPosition(X, Y);
}

void ZombieOverload::startPower(std::shared_ptr<Game> game) {
    game->setZombieFrequencyAux(game->getZombieFrequency());
    game->setZombieFrequency(200);
}

void ZombieOverload::endPower(std::shared_ptr<Game> game) {
    game->setZombieFrequency(game->getZombieFrequencyAux());
    delete this;
}