//
// Created by hlhd on 2021/5/20.
//

#include "../all.h"

std::mutex mtx;
std::condition_variable proCV, conCV;
std::queue<int> buf;
const int MAXSIZE = 20;

void producerFunc(int idx)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(900));      // producer is a little faster than consumer

        std::unique_lock<std::mutex> lck(mtx);
        proCV.wait(lck, [] {return buf.size() != MAXSIZE; });   // wait(block) producer until q.size() != maxSize is true

        std::cout << "-> producer " << std::this_thread::get_id() << ": ";
        buf.push(idx);
        std::cout << buf.size() << '\n';

        conCV.notify_all();                                   // notify(wake up) consumer when q.size() != 0 is true
    }
}

void consumerFunc()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::unique_lock<std::mutex> lck(mtx);                        // RAII，程序运行到此block的外面（进入下一个while循环之前），资源（内存）自动释放
        conCV.wait(lck, [] {return buf.size() != 0; });     // wait(block) consumer until q.size() != 0 is true

        std::cout << "consumer " << std::this_thread::get_id() << ": ";
        buf.pop();
        std::cout << buf.size() << '\n';

        proCV.notify_all();                               // nodity(wake up) producer when q.size() != maxSize is true
    }
}

int main()
{
    std::thread producers[2];
    std::thread consumers[2];

    for (int i = 0; i < 2; i ++ )
    {
        consumers[i] = std::thread(consumerFunc);
        producers[i] = std::thread(producerFunc, i + 1);
    }

    for (int i = 0; i < 2; i ++ )
    {
        producers[i].join();
        consumers[i].join();
    }


    system("pause");
    return 0;
}

/* https://blog.csdn.net/u013390476/article/details/52067321 */