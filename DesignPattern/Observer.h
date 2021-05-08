//
// Created by helianhaodong on 2021/5/8.
//

#ifndef MODERNCPP_OBSERVER_H
#define MODERNCPP_OBSERVER_H

#include <iostream>

class Observer
{
public:
    Observer();
    ~Observer();

    virtual void update(int hour, int min, int sec) = 0;
};


#endif //MODERNCPP_OBSERVER_H
