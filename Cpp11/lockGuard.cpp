//
// Created by helianhaodong on 2021/4/26.
//

#include "../all.h"

// 锁的粒度太大，如果中间throw异常，
// 就会导致当前拿到mtx的线程没有释放锁，但是其他线程处于"死等"的状态(当然，这不是"死锁")

// 栈自旋是一种现象：抛出异常时"栈对象"会自我析构

std::mutex g_mtx;

void printEven(int i)
{
    if( i % 2 == 0) std::cout << i << " is even" << std::endl;
    else throw std::logic_error("not even");
}

void printThreadId(int id)
{
//    try
//    {
//        g_mtx.lock();
//        printEven(id);
//        g_mtx.unlock();
//    }
    try
    {
        std::lock_guard<std::mutex> lck(g_mtx); // g_mtx是资源，拿到g_mtx这个资源即是lck这个对象的初始化
        printEven(id);
    }
    catch(std::logic_error & )
    {
        std::cout << "exception caught" << std::endl;
    }
}

int mainlg()
{
    std::thread ths[10]; //spawn 10 threads

    for (int i = 0; i < 10; i ++)
    {
        ths[i] = std::thread(printThreadId, i + 2);
    }

    for (auto & th : ths) th.join();

    return 0;
}