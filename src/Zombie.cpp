#include "../headers/Zombie.h"
#include "../headers/Game.h"

#include <iostream>
#include <math.h>

#define PI 3.14159265

Zombie::Zombie(Game* game) {
    zombieX = 20;
    zombieY = 20;

    int windowX = game->getWindow().getSize().x;
    int windowY = game->getWindow().getSize().y;

    //Choose side of window where zombie spawns
    int side = rand() % 4;

    switch (side) {
        //Top
        case 0:
            zombieX = rand() % windowX;
            zombieY = 80;
        break;
        //Right
        case 1:
            zombieX = windowX - 80;
            zombieY = rand() % windowY;
        break;
        //Down
        case 2:
            zombieX = rand() % windowX;
            zombieY = windowY-80;
        break;
        //Left
        default:
            zombieX = 80;
            zombieY = rand() % windowY;
        break;
    }

    //Setup zombie sprite
    spriteTexture.loadFromFile("assets/sprites/zombie/zombieSprite.png");
    sprite.setTexture(spriteTexture);
    sprite.setTextureRect(sf::IntRect(30, 30, 220, 200)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(95, 85);
    sprite.setPosition(zombieX, zombieY);

    dead = 0;
}

void Zombie::renderSprite(Game* game) {
    if(!dead)
    game->getWindow().draw(sprite);
}

void Zombie::move(Player* player, int speed) {
    //Based on linear interpolation
    moveX = player->getPlayerX() - zombieX;
    moveY = player->getPlayerY() - zombieY;
    moveX = moveX / 200;
    moveY = moveY / 200;

    if(moveX == 0 && moveY == 0) {
        moveX = 1;
    }

    zombieX += (moveX * speed);
    zombieY += (moveY * speed);

    //Calculate angle
    float angle = atan2(player->getPlayerY() - zombieY, player->getPlayerX() - zombieX);
    angle *= 180 / PI;

    sprite.setRotation(angle);

    //std::cout << "moveX: " << moveX*speed << std::endl;
    //std::cout << "moveY: " << moveY*speed << std::endl;

    sprite.setPosition(zombieX, zombieY);
}

int Zombie::getZombieX() {
    return zombieX;
}

int Zombie::getZombieY() {
    return zombieY;
}

void Zombie::kill(Game* game) {
if(dead == 0) {
    game->incrementGameScore();
    game->setScoreString(game->getGameScore());
}
    dead = 1;
}

int Zombie::isDead() {
    return dead;
}



ZombieList::ZombieList() {
    head = new zombieNode();
    tail = new zombieNode();
    head->next = tail;
    tail->next = nullptr;
}

void ZombieList::insertNodeEnd(Zombie* newZombie) {
    zombieNode *auxNode = new zombieNode();
    zombieNode *newNode = new zombieNode();

    newNode->zombie = newZombie;

    for(auxNode = head; auxNode->next != tail; auxNode = auxNode->next) {
        //Travels through the list to the last node before the head
    }
    newNode->next = auxNode->next;
    auxNode->next = newNode;

}

zombieNode* ZombieList::getNextNode(zombieNode* node) {
    return node->next;
}

zombieNode* ZombieList::deleteNode(zombieNode* node) {
    zombieNode* previousNode;
    zombieNode* deletedNode = node;

    zombieNode* returnNode;
    returnNode = node->next;

    for(previousNode = head; previousNode->next != node; previousNode = previousNode->next) {
        //Travels through the list to the last node before the head
    }

    if(previousNode == head) {
        //node->next = nullptr;
        //delete deletedNode;
        head->next = tail;
        std::cout << "Deleted node after head" << std::endl;
    }else if(previousNode != head) {
        previousNode->next = node->next;
        //node->next = nullptr;
        //delete deletedNode;
        std::cout << "Deleted normal node" << std::endl;
    }

    return returnNode;
}

zombieNode* ZombieList::getHead() {
    return head;
}

zombieNode* ZombieList::getTail() {
    return tail;
}
