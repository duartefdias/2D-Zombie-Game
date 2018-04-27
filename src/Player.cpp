#include "../headers/Player.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Player::Player(int x, int y) {
    playerX = x - 40;
    playerY = y - 40;
}

void Player::setupSprite() {
    sprite.setRadius(40);
    sprite.setFillColor(sf::Color(150, 50, 250));
    sprite.setPosition(playerX, playerY);

    spriteTexture.loadFromFile("assets/sprites/guns/player_sprite.png");
    sf::IntRect rectSourceSprite(300, 0, 300, 400);
    sprite1.setTexture(spriteTexture);
    //sprite1.setTextureRect(sf::IntRect(0, 0, 400, 532)); //(minWidth, minHeight, maxWidth, maxHeight)
}

void Player::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
    game->getWindow().draw(sprite1);
}

sf::CircleShape & Player::getSprite() {
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
