#ifndef GAME_H
#define  GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
  static void Start();

private:
  static bool IsExiting();
  static void GameLoop();

  enum GameState { Uninitialized, ShowingSplash, Paused,
          ShowingMenu, Playing, Exiting };

  static GameState _gameState;
  static sf::RenderWindow _mainWindow;
};

#endif //GAME_H
