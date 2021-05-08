//
// Created by helianhaodong on 2021/4/26.
//

#include "../all.h"

#define N 100

void fool()
{
    std::cout << "thread id is: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int mainnt()
{
    std::thread th[N];
    for (int i = 0; i < N; i ++ )
    {
        th[i] = std::thread(fool);
        th[i].detach();
    }

    return 0;
}