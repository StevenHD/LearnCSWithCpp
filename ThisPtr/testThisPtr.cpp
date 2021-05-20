//
// Created by helianhaodong on 2021/5/13.
//

#include "../all.h"

class XX
{
public:
    XX(){}

    ~XX()
    {

    }
};

int mainThis()
{
    XX* p = new XX;
    ::operator delete(p);
    delete p;
}