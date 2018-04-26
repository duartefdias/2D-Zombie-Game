#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "../headers/Game.h"
#include "../headers/Player.h"

int main() {

    Game* game = new Game();
    //game->createWindow();
    game->setupBackground("assets/textures/background1.jpg", 900, 700);

    while (game->getWindow().isOpen())
    {
        sf::Event event;
        while(game->getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed)
                game->getWindow().close();
        }
        game->getWindow().clear();
        game->renderBackground();
        game->getWindow().display();
        std::cout << "loopz for days" << std::endl;
    }

    std::cout << "the end" << std::endl;

    return 0;

}
