//
// Created by helianhaodong on 2021/4/26.
//

#include "../all.h"

// volatile关键字：编译器不要进行优化，不要将数值存到"寄存器"中，而是每次都从"内存"中取
// try_lock()需要增加"判断条件"，直接替代lock()会得不到想要的正确结果

volatile int cnt(0);
std::mutex mtx_;

void increase1kTimes()
{
    for (int i = 0; i < 1000; i ++ )
    {
        while (!mtx_.try_lock());
        cnt ++;
        mtx_.unlock();
    }
}

int mainmtx()
{
    std::thread ths[10];
    for (int i = 0; i < 10; i ++ ) ths[i] = std::thread(increase1kTimes);
    for (auto& th : ths)
    {
        th.join();
    }

    std::cout << "cnt = " << cnt << std::endl;

    return 0;
}

