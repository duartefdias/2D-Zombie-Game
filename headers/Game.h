#ifndef GAME_H
#define  GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:

    Game(int windowWidth = 900, int windowHeight = 700);

    void setupBackground(std::string fileName, int width = 900, int height = 700);
    void renderBackground();

    sf::RenderWindow & getWindow();
    sf::RectangleShape & getBackground();

    void setScoreText();
    void renderScoreText();
    sf::Text & getScoreText();
    sf::Font & getScoreTextFont();

private:
    sf::RenderWindow window;
    sf::RectangleShape background;
    sf::Text scoreText;
    sf::Font scoreTextFont;
};

#endif //GAME_H
