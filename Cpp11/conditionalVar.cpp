//
// Created by helianhaodong on 2021/4/26.
//

#include "../all.h"

std::condition_variable cv;
std::mutex m_mtx;

bool ready = false;

void printId(int id)
{
    std::unique_lock<std::mutex> ql(m_mtx);
    while (!ready)
    {
        // 条件不满足
        cv.wait(ql);
    }

    std::cout << "thread id: " << std::this_thread::get_id()
              << " id = "      << id << std::endl;
}

void goo()
{
    std::unique_lock<std::mutex> ql(m_mtx); // 主线程中也要上锁的。
    ready = true;
    cv.notify_all();
}

int maincv()
{
    std::thread ths[10];
    for (int i = 0; i < 10; i ++ )
    {
        ths[i] = std::thread(printId, i);
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));
    goo();

    for(auto &th: ths)
    {
        th.join();
    }

    return 0;
}
