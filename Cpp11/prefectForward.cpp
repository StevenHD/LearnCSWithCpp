//
// Created by helianhaodong on 2021/4/28.
//

#include "../all.h"

template<typename T>
void func(T& param)
{
    std::cout << "传入的是左值" << std::endl;
    std::cout << param << std::endl;
}

template<typename T>
void func(T&& param)    /* 只有发生"类型推导"的时候，T&&才表示万能引用；否则，表示右值引用。 */
{
    std::cout << "传入的是右值" << std::endl;
    std::cout << param << std::endl;
}

template<typename T>
void warp(T&& param)
{
    func(std::forward<T>(param));
}

int mainpf()
{
    int num = 2019;
//    func(num);
//    func(2019);
    warp(num);
    warp(2019);

    return 0;
}