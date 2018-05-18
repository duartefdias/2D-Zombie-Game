//
// Created by bob on 18-05-2018.
//

#include "../headers/GameCharacter.h"

GameCharacter::GameCharacter() {}

void GameCharacter::setupSprite() {
    sprite.setPosition(X, Y);
    spriteTexture.loadFromFile("../assets/sprites/player/player_spriteT.png");
    sprite.setTexture(spriteTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, 150, 190)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(75, 95);
}

void GameCharacter::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
}

sf::Sprite & GameCharacter::getSprite() {
    return sprite;
}

int GameCharacter::getX() {
    return X;
}

int GameCharacter::getY() {
    return Y;
}