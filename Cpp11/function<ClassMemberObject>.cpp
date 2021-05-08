//
// Created by helianhaodong on 2021/4/25.
//

// fucntion 作类成员实现回调
// 类似于观察者模式

#include "../all.h"

class FunctorA
{
public:
    void operator()()
    {
        std::cout << "class FunctorA" << std::endl;
    }
};

class FunctorB
{
public:
    void operator()()
    {
        std::cout << "class FunctorB" << std::endl;
    }
};

class FunctorC
{
public:
    void operator()()
    {
        std::cout << "class FunctorC" << std::endl;
    }
};

class Object
{
public:
    Object(FunctorA a, FunctorB b, FunctorC c)
    {
        m_list.push_back(a);
        m_list.push_back(b);
        m_list.push_back(c);
    }

    void notify()
    {
        for (auto& item : m_list) item();
    }

private:
    std::list<std::function<void(void)>> m_list;
};

int mainfco()
{
    FunctorA a;
    FunctorB b;
    FunctorC c;

    Object obj(a, b, c);
    obj.notify();

    return 0;
}