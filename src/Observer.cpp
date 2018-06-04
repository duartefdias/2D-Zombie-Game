//
// Created by bob on 04-06-2018.
//

#include "../headers/Observer.h"

Observer::~Observer() {
    gamePointer->removeObserver(this);
}