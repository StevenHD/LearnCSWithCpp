//
// Created by helianhaodong on 2021/6/3.
//

#include "../../all.h"

using namespace std;

class Phone
{
public:
    Phone()
    {
        cout << "Phone()" << endl;
    }

    virtual int cost() = 0;
};

class Nokia : public Phone
{
public:
    int cost()
    {
        return 5000;
    }
};

class DecoratePhone : public Phone
{
public:
    DecoratePhone(Phone* ph) : m_phone(ph) {}
protected:
    Phone* m_phone;
};

class ScreenProtectorPhone : public DecoratePhone
{
public:
    ScreenProtectorPhone(Phone* ph)
        : DecoratePhone(ph) {}

    int cost()
    {
        return 100 + m_phone->cost();
    }
};

int main()
{
    Nokia nk;
    cout << nk.cost() << endl;

    ScreenProtectorPhone sp(&nk);
    cout << sp.cost() << endl;

    ScreenProtectorPhone sp2(&sp);
    cout << sp2.cost() << endl;

    return 0;
}