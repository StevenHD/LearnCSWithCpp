//
// Created by helianhaodong on 2021/4/26.
//

#include "../all.h"

void foo()
{
    std::cout << "void foo()" << std::endl;
}

void func(int a)
{
    std::cout << "void func(int a)" << std::endl;
}

class Foo
{
public:
    void method()
    {
        std::cout << "Foo::void method()" << std::endl;
    }

    void method2(std::string s)
    {
        std::cout<< "Foo:void method2()" << std::endl;
    }
};

class Bar
{
public:
    void method3(int a, std::string s)
    {
        std::cout << "Bar:void method3()" << std::endl;
    }
};

std::function<void(void)> f;

int mainfb()
{
    f = std::bind(foo);
    f();

    f= std::bind(func,1);
    f();

    Foo x;
    f = std::bind(&Foo::method, &x);
    f();

    f = std::bind(&Foo::method2, &x, "china");
    f();

    Bar bar;
    f = std::bind(&Bar::method3, &bar, 10, "china");
    f();

    return 0;
}