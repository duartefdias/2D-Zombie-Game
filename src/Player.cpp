#include "../headers/Player.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Player::Player(int x, int y) {
    playerX = x - 40;
    playerY = y - 40;
}

void Player::setupSprite() {
    sprite.setPosition(playerX, playerY);
    spriteTexture.loadFromFile("assets/sprites/player/player_spriteT.png");
    sprite.setTexture(spriteTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, 150, 190)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
}

void Player::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
}

sf::Sprite & Player::getSprite() {
    return sprite;
}

void Player::move(Game* game, float speed) {
    int windowWidth = game->getWindow().getSize().x;
    int windowHeight = game->getWindow().getSize().y;
    //Move UP
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (playerY >= 10)
            playerY -= 5 * speed;
        else
            playerY = 10;
    }
    //Move RIGHT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (playerX <= windowWidth - 80)
            playerX += 5 * speed;
        else
            playerX = 820;
    }
    //Move DOWN
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (playerY <= windowHeight - 80)
            playerY += 5 * speed;
        else
            playerY = 620;
    }
    //Move LEFT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (playerX >= 10)
            playerX -= 5 * speed;
        else
            playerX = 10;
    }
    sprite.setPosition(playerX, playerY);
}
