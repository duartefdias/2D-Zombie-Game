#include "../headers/Bullet.h"

#include <iostream>

Bullet::Bullet(int startX, int startY, int endX, int endY) {
    bulletX = startX;
    bulletY = startY;
    /*std::cout << "startX: " << startX << std::endl;
    std::cout << "startY: " << startY << std::endl;
    std::cout << "endX: " << endX << std::endl;
    std::cout << "endY: " << endY << std::endl;*/

    //Setup bullet sprite
    sprite.setRadius(10);
    sprite.setFillColor(sf::Color(100, 250, 50));
    sprite.setPosition(startX, startY);

    //Based on linear interpolation
    moveX = endX - startX;
    moveY = endY - startY;
    moveX = moveX / 200;
    moveY = moveY / 200;

    if(moveX == 0 && moveY == 0) {
        moveX = 1;
    }


    //std::cout << "moveX: " << moveX << std::endl;
    //std::cout << "moveY: " << moveY << "\n" << std::endl;
}

void Bullet::move(int speed) {
    bulletX += (moveX * speed);
    bulletY += (moveY * speed);

    //std::cout << "bulletX: " << bulletX << std::endl;
    //std::cout << "bulletY: " << bulletY << "\n" << std::endl;
    sprite.setPosition(bulletX, bulletY);
}

/*void Bullet::createBullet(List* bulletList) {
    //TODO: Add bullet to bulletList
}*/

void Bullet::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
}

int Bullet::getBulletX() {
    return bulletX;
}

int Bullet::getBulletY() {
    return bulletY;
}

int Bullet::isOutOfScreen(Game* game) {
    int windowX = game->getWindow().getSize().x;
    int windowY = game->getWindow().getSize().y;

    if(bulletX < 0 || bulletX > windowX) {
        std::cout << "Bullet is out of screen" << std::endl;
        return 1;
    }

    if(bulletY < 0 || bulletY > windowY) {
        std::cout << "Bullet is out of screen" << std::endl;
        return 1;
    }

    return 0;
}

BulletList::BulletList() {
    head = new bulletNode();
    tail = new bulletNode();
    head->next = tail;
    tail->next = nullptr;
}

void BulletList::insertNodeEnd(Bullet* newBullet) {
    bulletNode *auxNode = new bulletNode();
    bulletNode *newNode = new bulletNode();

    newNode->bullet = newBullet;

    for(auxNode = head; auxNode->next != tail; auxNode = auxNode->next) {
        //Travels through the list to the last node before the head
    }
    newNode->next = auxNode->next;
    auxNode->next = newNode;

}

bulletNode* BulletList::getNextNode(bulletNode* node) {
    return node->next;
}

bulletNode* BulletList::deleteNode(bulletNode* node) {
    bulletNode* previousNode;
    bulletNode* deletedNode = node;

    bulletNode* returnNode;
    returnNode = node->next;

    for(previousNode = head; previousNode->next != node; previousNode = previousNode->next) {
        //Travels through the list to the last node before the head
    }

    if(previousNode == head) {
        head->next = node->next;
        node->next = nullptr;
        delete deletedNode;
        //std::cout << "Deleted node after head" << std::endl;
    }else if(previousNode != head) {
        previousNode->next = node->next;
        node->next = nullptr;
        delete deletedNode;
        //std::cout << "Deleted normal node" << std::endl;
    }

    return returnNode;
}

bulletNode* BulletList::getHead() {
    return head;
}

bulletNode* BulletList::getTail() {
    return tail;
}
