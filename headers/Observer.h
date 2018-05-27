//
// Created by bob on 27-05-2018.
//

#ifndef ZOMBIEGAME_OBSERVER_H
#define ZOMBIEGAME_OBSERVER_H

enum Event {zombiesKilled};

class Observer{
public:
    virtual ~Observer() {}
    virtual void onNotify(Event event, int amount) = 0;
};

#endif //ZOMBIEGAME_OBSERVER_H
