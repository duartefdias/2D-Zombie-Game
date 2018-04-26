#include "../headers/Game.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game(int windowWidth, int windowHeight) {
    window.create(sf::VideoMode(windowWidth, windowHeight), "2D Zombies");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
}

void Game::setupBackground(std::string fileName, int width, int height) {
    background.setSize(sf::Vector2f(width, height));

    //The white square problem... the code below won't work
    /*sf::Texture bgTexture;
    std::cout << "texture path: " << fileName << std::endl;
    if (!bgTexture.loadFromFile(fileName)) {
        std::cout << "\nError loading texture!" << std::endl;
    }
    background.setTexture(&bgTexture);*/
}

void Game::renderBackground() {
    window.draw(background);
}

sf::RenderWindow & Game::getWindow() {
        return window;
}

sf::RectangleShape & Game::getBackground() {
        return background;
}
