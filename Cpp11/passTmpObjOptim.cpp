//
// Created by helianhaodong on 2021/4/28.
//


/* 传递临时对象的优化 */

#include "../all.h"

struct Food
{
    Food()                { std::cout << "Constructed"      << std::endl; }
    Food(const Food &)    { std::cout << "Copy-constructed" << std::endl; }
    Food(Food &&)         { std::cout << "Move-constructed" << std::endl; }
    ~Food()               { std::cout << "Destructed"       << std::endl; }
};

// Passing a Temporary by Value
void f3(Food f)
{
    std::cout << "F3 called" << std::endl;
}

// Copy Elision does not always work
Food f4(int i)
{
    Food x, y;
    if (i > 0)  return x;
    else        return y;
    // 由于if...else…分支结构的存在，编译器不确定f4()函数具体的返回对象，无法实施优化。
}

int mainptoo()
{
//    f3(Food());
    Food food = f4(0);
    return 0;
}