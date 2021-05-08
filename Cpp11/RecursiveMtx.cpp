//
// Created by helianhaodong on 2021/4/26.
//

#include "../all.h"

template <typename T>

class container
{
public:
    void add(T element)
    {
        std::unique_lock<std::recursive_mutex> lck(_mtx);
        _elements.push_back(element);
    }

    void addrange(int num, ...)
    {
        va_list arguments;
        va_start(arguments, num);
        for (int i = 0; i < num; i++)
        {
            std::unique_lock<std::recursive_mutex> lck(_mtx);
            add(va_arg(arguments, T));
        }

        va_end(arguments);
    }

    void dump()
    {
        std::unique_lock<std::recursive_mutex> lck(_mtx);
        for(auto e : _elements)
        {
            std::cout << e << std::endl;
        }
    }

private:
    std::recursive_mutex _mtx;
    std::vector<T> _elements;
};

void func(container<int>& cont)
{
    cont.addrange(3, rand(), rand(), rand());
}

int mainrm()
{
    srand((unsigned int)time(0));
    container<int> cont;

    std::thread t1(func, std::ref(cont));
    std::thread t2(func, std::ref(cont));
    std::thread t3(func, std::ref(cont));

    t1.join();
    t2.join();
    t3.join();

    cont.dump();

    return 0;
}