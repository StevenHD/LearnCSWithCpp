//
// Created by helianhaodong on 2021/5/7.
//

#include "../../all.h"

class A
{
public:
    void update(int curNum)
    {
        std::cout << "A = " << curNum << std::endl;
    }
};

class B
{
public:
    void update(int curNum)
    {
        std::cout << "B = " << curNum << std::endl;
    }
};

class C
{
public:
    void update(int curNum)
    {
        std::cout << "C = " << curNum << std::endl;
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

    void setState(int add, A* pa, B* pb, C* pc)
    {
        m_x += add;
        notify(pa, pb, pc);
    }

private:
    int m_x{0};
};

int mainOB1()
{
    D d;
    A a; B b; C c;
    d.setState(9, &a, &b, &c);
    d.setState(4, &a, &b, &c);

    return 0;
}