//
// Created by helianhaodong on 2021/4/26.
//

// join()会让主线程阻塞在那里

#include "../all.h"

void func()
{
    std::cout << "func thread: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
}

void go()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void run()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int maintd()
{
    std::cout << "main thread: " << std::this_thread::get_id() << std::endl;
    std::thread td(func);
    td.join();

    std::thread td1(go);
    std::thread td2(run);
    td1.join();
    std::cout << "td1 is over" << std::endl;
    td2.join();
    std::cout << "td2 is over" << std::endl;

    return 0;
}
