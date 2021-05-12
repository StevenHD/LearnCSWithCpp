//
// Created by helianhaodong on 2021/5/8.
//

#include "LondonTime.h"

LondonTime::LondonTime()
{

}

void LondonTime::dis()
{
    std::cout << m_hour << ":" << m_min << ":" << m_sec << std::endl;
}

void LondonTime::update(int hour, int min, int sec)
{
    m_hour = hour + 200;
    m_min  = min;
    m_sec  = sec;
    dis();
}