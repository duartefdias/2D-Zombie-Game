#include "../headers/Game.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() {
    window.create(sf::VideoMode(640, 480), "2D Zombies");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
}

void Game::createWindow(){
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}

void Game::setupBackground(std::string fileName, int width, int height) {
    sf::RectangleShape background(sf::Vector2f(width, height));
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile(fileName)) {
        std::cout << "\nError loading texture!" << std::endl;
    }
    background.setTexture(&bgTexture);
}

void Game::renderBackground() {
    window.draw(background);
}

/*sf::RenderWindow & Game::getWindow() {
        return window;
}

sf::RectangleShape & Game::getBackground() {
        return background;
}*/
