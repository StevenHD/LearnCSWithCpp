//
// Created by helianhaodong on 2021/5/8.
//

#include "BeiJingTime.h"

BeiJingTime::BeiJingTime()
{

}

void BeiJingTime::dis()
{
    std::cout << m_hour << ":" << m_min << ":" << m_sec << std::endl;
}

void BeiJingTime::setTime(int hour, int min, int sec)
{
    m_hour = hour;
    m_min  = min;
    m_sec  = sec;
    dis();
    notify();
}

void BeiJingTime::notify()
{
    std::list<Observer*>::iterator itr;
    for (itr = m_obsvrList.begin(); itr != m_obsvrList.end(); ++ itr)
    {
        (*itr)->update(m_hour, m_min, m_sec);
    }
}