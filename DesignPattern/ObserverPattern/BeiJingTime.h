//
// Created by helianhaodong on 2021/5/8.
//

#ifndef MODERNCPP_BEIJINGTIME_H
#define MODERNCPP_BEIJINGTIME_H

#include "Subject.h"

class BeiJingTime : public Subject
{
public:
    BeiJingTime();
    void dis();
    void notify();
    void setTime(int hour, int min, int sec);

protected:
    int m_hour;
    int m_min;
    int m_sec;
};


#endif //MODERNCPP_BEIJINGTIME_H
