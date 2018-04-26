#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 700), "2D Zombies");
    window.setVerticalSyncEnabled(true);

    sf::RectangleShape background(sf::Vector2f(900, 700));
    sf::Texture bgTexture;
    bgTexture.loadFromFile("textures/background1.jpg");
    background.setTexture(&bgTexture);

    int playerX = 450;
    int playerY = 350;
    sf::CircleShape player(40);
    player.setPosition(playerX, playerY);
    player.setFillColor(sf::Color::Red);

    //start clock
    sf::Clock clock;

    //define fonts & text
    sf::Font font;
    font.loadFromFile("fonts/Raleway-Medium.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Current score: ");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(20, 15);

    sf::Text scoreText;
    std::string scoreString = "0";
    scoreText.setFont(font);
    scoreText.setString(scoreString);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition(240, 15);

    int gameScore = 0;

    while (window.isOpen())
    {
        window.setSize(sf::Vector2u(900,700));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(text);
        window.draw(scoreText);
        window.draw(player);
        window.display();

        sf::Time elapsed1 = clock.getElapsedTime();
        if((int) elapsed1.asSeconds() - 2 == 0){
            std::cout << elapsed1.asSeconds() << std::endl;
            clock.restart();
            gameScore++;
            std::string scoreString = std::to_string(gameScore);
            scoreText.setString(scoreString);
        }

        player.setPosition(playerX, playerY);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (playerY <= 680) {
                playerY += 5;
            }
            else{
                playerY = 680;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (playerY >= 20) {
                playerY -= 5;
            }
            else{
                playerY = 20;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (playerX >= 20) {
                playerX -= 5;
            }
            else{
                playerX = 20;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (playerX <= 880) {
                playerX += 5;
            }
            else{
                playerX = 880;
            }
        }

        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                std::cout << "the left button was pressed" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
        }

    }

    return 0;
}
