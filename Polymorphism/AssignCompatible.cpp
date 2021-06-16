//
// Created by helianhaodong on 2021/6/5.
//

/* 赋值兼容细化 */
// 1. 派生类的对象可以赋值给基类对象。
// 2. 派生类的对象可以初始化基类的引用。
// 3. 派生类对象的地址可以赋给指向基类的指针。

#include "../all.h"

using namespace std;

class Shape
{
public:
    Shape(int x = 0, int y = 0)
        : _x(x), _y(y)
    {
        cout << "Shape=>" << this << endl;
        cout << typeid(this).name() << endl;
    }

    virtual void draw()
    {
        cout << "draw Shape from " << "(" << _x << ", " << _y << ")" << endl;
    }

protected:
    int _x;
    int _y;
};

class Circle : public Shape
{
public:
    Circle(int x = 0, int y = 0, int r = 0)
        : Shape(x, y), _r(r)
    {
        cout << "Shape=>" << this << endl;
        cout << typeid(this).name() << endl;
    }

    // shadow
    void draw()
    {
        cout << "draw Circle from " << "(" << _x << ", " << _y << ")"
            << ", radious = " << _r << endl;
    }

protected:
    int _r;
};

int mainAC()
{
//    Shape sp(1, 2);
//    sp.draw();

    cout << "----------------" << endl;

    Circle crk(4, 5, 6);
    crk.draw();

    // AssignCompatible 1
//    sp = crk;
//    sp.draw();

    // AssignCompatible 2
//    Shape& rsp = crk;
//    rsp.draw();

    // AssignCompatible 3, which is corresponding for "Polymorphism"
    Shape* psp = &crk;
    psp->draw();

    return 0;
}


