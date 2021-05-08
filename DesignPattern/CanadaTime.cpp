//
// Created by helianhaodong on 2021/5/8.
//

#include "CanadaTime.h"

CanadaTime::CanadaTime()
{

}

void CanadaTime::dis()
{
    std::cout << m_hour << ":" << m_min << ":" << m_sec << std::endl;
}

void CanadaTime::update(int hour, int min, int sec)
{
    m_hour = hour + 100;
    m_min  = min;
    m_sec  = sec;
    dis();
}