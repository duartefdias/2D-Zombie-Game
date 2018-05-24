//
// Created by bob on 23-05-2018.
//

#include "../headers/Powers.h"

//AMMO

Ammo::Ammo(Game *game) : PowerUp(game) {
    spriteTexture.loadFromFile("../assets/sprites/powerups/bullets.png");
    sprite.setTexture(spriteTexture);
    //sprite.setTextureRect(sf::IntRect(30, 30, 220, 200)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(95, 85);
    sprite.setPosition(X, Y);
}

void Ammo::startPower(Game* game) {
    game->setBulletFrequency(50);
}

void Ammo::endPower(Game *game) {
    game->setBulletFrequency(300);
}


//ZOMBIEOVERDOSE

ZombieOverload::ZombieOverload(Game *game) : PowerUp(game) {
    spriteTexture.loadFromFile("../assets/sprites/powerups/skull.png");
    sprite.setTexture(spriteTexture);
    //sprite.setTextureRect(sf::IntRect(30, 30, 220, 200)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(95, 85);
    sprite.setPosition(X, Y);
}

void ZombieOverload::startPower(Game *game) {
    game->setZombieFrequency(200);
}

void ZombieOverload::endPower(Game *game) {
    game->setZombieFrequency(game->getZombieFrequencyAux());
}