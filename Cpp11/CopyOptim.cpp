//
// Created by helianhaodong on 2021/4/28.
//

#include "../all.h"

/* 拷贝优化效率最高，移动构造次之 */
/* 拷贝优化在两种情况下进行：一是对于函数返回值的拷贝优化；二是对于向函数中传递临时对象的优化 */

struct Floo
{
    Floo()               { std::cout << "Constructed" << std::endl; }
    Floo(const Floo &)    { std::cout << "Copy-constructed" << std::endl; }
    Floo(Floo &&)         { std::cout << "Move-constructed" << std::endl; }
    ~Floo()              { std::cout << "Destructed" << std::endl; }
};

// Named Return Value Optimization (NRVO)
Floo f1()
{
    Floo foo;
    return foo;
}

// Return Value Optimization (RVO)
Floo f2()
{
    return Floo();
}

int mainco()
{
//    std::vector<Floo> vec;
//    vec.push_back(Floo());

    f1();
    Floo res = f1();

    return 0;
}