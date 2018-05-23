//
// Created by bob on 23-05-2018.
//

#include "../headers/Powers.h"

//AMMO

Ammo::Ammo(Game *game) : PowerUp(game) {
    spriteTexture.loadFromFile("../assets/sprites/ammo/bullets.png");
    sprite.setTexture(spriteTexture);
    //sprite.setTextureRect(sf::IntRect(30, 30, 220, 200)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(95, 85);
    sprite.setPosition(X, Y);
}

void Ammo::startPower(Game* game){
    game->setBulletFrequency(50);
}