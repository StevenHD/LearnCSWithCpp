//
// Created by helianhaodong on 2021/4/25.
//

#include "../all.h"

class A
{
public:
    //------------------Constructor------------------
    A(int* i = nullptr) : m_i(i)
    {
        std::cout << "A(int* i = nullptr)" << std::endl;
        m_i = new int;
    }

    //------------------Destructor------------------
    ~A()
    {
        std::cout << "~A()" << std::endl;
        if (m_i != nullptr)
        {
            delete m_i;
        }
    }

    //------------------Copy_Constructor------------------
    A(const A& another)
    {
        std::cout << "A(const A& another)" << std::endl;
        m_i  = new int;
        *m_i = *another.m_i;
    }

    //------------------Copy_AssignConstructor------------------
    A& operator=(const A& another)
    {
        std::cout << "A& operator=(const A& another)" << std::endl;
        if (this != &another)
        {
            delete m_i;
            m_i = new int;
            *m_i = *another.m_i;
        }
        return *this;
    }


    //------------------Move_Constructor------------------
    A(A && another)
    {
        std::cout << "A(A && another)" << std::endl;
        m_i         = another.m_i;
        another.m_i = nullptr;
    }

    //------------------Move_AssignConstructor------------------
    A& operator=(A && another)
    {
        std::cout << "A& operator=(A && another)" << std::endl;
        if (this != &another)
        {
            delete m_i;
            m_i = another.m_i;
            another.m_i = nullptr;
        }
        return *this;
    }

private:
    int* m_i;
};

int mainbs()
{
//    A a;
//    A b(a);
//    A c(std::move(a));
//    A d;
//    d = c;
//
//    A m;
//    A n;
//    n = std::move(m);
}