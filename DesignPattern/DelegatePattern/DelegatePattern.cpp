//
// Created by helianhaodong on 2021/6/2.
//

#include "../../all.h"

using namespace std;

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }

    void dis()
    {
        cout << "shared_ptr" << endl;
    }
};

void funcx()
{
//    A* p = new A;
//    p->dis();
    shared_ptr<A> sp(new A); // sp代理了A, 好处是自动析钩，sp是A的代理
    sp->dis();
}

int mainDP()
{
    funcx();
}

// 智能代理和保护代理均是 provide 一个代理从而可以实现对对象的控制访问
// 智能指针是智能代理