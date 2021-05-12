//
// Created by helianhaodong on 2021/5/8.
//

#ifndef MODERNCPP_CANADATIME_H
#define MODERNCPP_CANADATIME_H

#include "Observer.h"

class CanadaTime : public Observer
{
public:
    CanadaTime();
    void dis();
    void update(int hour, int min, int sec);

private:
    int m_hour;
    int m_min;
    int m_sec;
};


#endif //MODERNCPP_CANADATIME_H
