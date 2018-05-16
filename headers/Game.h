#ifndef GAME_H
#define  GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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

    int getGameScore();
    void setScoreString(int score);
    void renderScoreString();
    sf::Text & getScoreString();
    sf::Font & getScoreStringFont();

    sf::Mouse & getMouse();

    void incrementGameScore();

private:
    sf::RenderWindow window;
    sf::RectangleShape background;
    sf::Text scoreText;
    sf::Font scoreTextFont;

    int gameScore = 0;
    sf::Text scoreString;
    sf::Font scoreStringFont;

    sf::Mouse mouse;
    sf::Music backgroundMusic;
};

#endif //GAME_H
