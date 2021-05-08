//
// Created by helianhaodong on 2021/5/8.
//

#ifndef MODERNCPP_LONDONTIME_H
#define MODERNCPP_LONDONTIME_H

#include "Observer.h"

class LondonTime : public Observer
{
public:
    LondonTime();
    void dis();
    void update(int hour, int min, int sec);

private:
    int m_hour;
    int m_min;
    int m_sec;
};


#endif //MODERNCPP_LONDONTIME_H
