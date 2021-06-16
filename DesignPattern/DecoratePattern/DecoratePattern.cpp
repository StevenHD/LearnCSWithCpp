//
// Created by helianhaodong on 2021/6/3.
//

// Favor Compostion Over Inheritance，一般继承3层就差不多了，不然会出现"类爆炸"的现象

#include "../../all.h"

using namespace std;

class GrandFather
{
public:
    virtual void test()
    {
        cout << "GrandFather test" << endl;
    }
};

class Father : public GrandFather
{
public:
    virtual void test()
    {
        cout << "Father test" << endl;
    }
};

class Son : public Father
{
public:
    virtual void test()
    {
        GrandFather::test();
        Father::test();
        cout << "Son test" << endl;
    }
};

int mainDPx()
{
//     Father* pf = new Son;
//     pf->test();

    GrandFather* pg = new Son;
    pg->test();

    return 0;
}