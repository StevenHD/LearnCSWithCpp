//
// Created by helianhaodong on 2021/5/7.
//

#include "../all.h"

class A
{
public:
    void update(int add)
    {

    }
};

class B
{
public:
    void update(int add)
    {

    }

};

class C
{
public:
    void update(int add)
    {

    }
};

class D
{
public:
    void notify(A* pa, B* pb, C* pc)
    {
        pa->update(m_x + 10);
        pb->update(m_x + 20);
        pc->update(m_x + 30);
    }

private:
    int m_x{0};
};
