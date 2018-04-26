#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "../headers/Game.h"
#include "../headers/Player.h"

int main() {

    Game* game = new Game();
    game->createWindow();
    game->setupBackground("assets/textures/background1.jpg", 900, 700);
    

    /*Game game;
    game.createWindow();
    game.setupBackground("assets/textures/background1.jpg", 900, 700);

    sf::RectangleShape background(sf::Vector2f(900, 700));
    sf::Texture bgTexture;
    bgTexture.loadFromFile("textures/background1.jpg");
    background.setTexture(&bgTexture);

    while(game.getWindow().isOpen()) {
    game.getWindow().clear();
    game.getWindow().draw(background);
    game.getWindow().display();
}*/

    /*std::string backgroundFile = "assets/textures/background1.jpg";
    game.setupBackground(backgroundFile, 900, 700);


    std::cout << "Program starting" << std::endl;

    while(game.getWindow().isOpen()) {

        game.getWindow().setSize(sf::Vector2u(900,700));
        sf::Event event;
        while (game.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game.getWindow().close();
        }

        game.getWindow().clear();
        game.renderBackground();
        game.getWindow().display();
    }

    return 0;*/

}
