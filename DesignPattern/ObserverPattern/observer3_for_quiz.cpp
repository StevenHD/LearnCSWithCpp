//
// Created by helianhaodong on 2021/6/15.
//

#include "../../all.h"

using namespace std;

class Observer
{
public:
    Observer();
    virtual void update(int hour, int min, int sec) = 0;
};

class CanadaTime : public Observer
{
public:
    CanadaTime() {}
    void update(int hour, int min, int sec)
    {
        m_hour = hour + 100;
        m_min  = min;
        m_sec  = sec;

        dis();
    }

    void dis()
    {
        std::cout << m_hour << ":" << m_min << ":" << m_sec << std::endl;
    }

protected:
    int m_hour;
    int m_min;
    int m_sec;
};

class LondonTime : public Observer
{
public:
    LondonTime() {}
    void update(int hour, int min, int sec)
    {
        m_hour = hour + 200;
        m_min  = min;
        m_sec  = sec;

        dis();
    }

    void dis()
    {
        std::cout << m_hour << ":" << m_min << ":" << m_sec << std::endl;
    }

protected:
    int m_hour;
    int m_min;
    int m_sec;
};

class Subject
{
public:
    Subject() {}

    void registerObsvr(Observer* obr)
    {
        m_obsvrList.push_back(obr);
    }

    void removeObsvr(Observer* obr)
    {
        m_obsvrList.remove(obr);
    }

    virtual void notify() = 0;

protected:
    list<Observer*> m_obsvrList;
};

class BeiJingTime : public Subject
{
public:
    BeiJingTime() {};

    void notify()
    {
        for (auto itr = m_obsvrList.begin(); itr != m_obsvrList.end(); ++ itr)
        {
            (*itr)->update(m_hour, m_min, m_sec);
        }
    }

    void setTime(int hour, int min, int sec)
    {
        m_hour = hour;
        m_min  = min;
        m_sec  = sec;
        notify();
        dis();
    }

    void dis()
    {
        std::cout << m_hour << ":" << m_min << ":" << m_sec << std::endl;
    }

protected:
    int m_hour;
    int m_min;
    int m_sec;
};

int mainQZ()
{
    CanadaTime  ct;
    LondonTime  lt;
    BeiJingTime bt;

    bt.registerObsvr(&ct);
    bt.registerObsvr(&lt);

    bt.setTime(0, 0, 0);
    cout << "--------" << endl;

    bt.setTime(9, 0, 0);
    cout << "========" << endl;

    bt.removeObsvr(&lt);
    bt.setTime(4, 0, 0);
}

