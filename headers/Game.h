#ifndef GAME_H
#define  GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:

    int gameOver = 0;

    Game();

    void setupBackground(std::string fileName, int width = 900, int height = 700);

    void renderBackground();

    sf::RenderWindow & getWindow();
    sf::RectangleShape & getBackground();

private:
    sf::RenderWindow window;
    sf::RectangleShape background;
};

#endif //GAME_H
