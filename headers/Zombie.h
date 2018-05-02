#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../headers/Game.h"
#include "../headers/Bullet.h"
#include <SFML/Graphics.hpp>


class Zombie {
public:

    Zombie(Game* game);

    void renderSprite(Game* game);

private:

    int zombieX;
    int zombieY;

    sf::CircleShape sprite;

};

#endif // ZOMBIE_H
