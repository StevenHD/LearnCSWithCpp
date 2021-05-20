//
// Created by helianhaodong on 2021/5/12.
//

#include "../../all.h"

class Weapon
{
public:
    virtual void use() = 0;
};

class Gun : public Weapon
{
public:
    void use()
    {
        std::cout << "Use Gun to Kill U!" << std::endl;
    }
};

class Knife : public Weapon
{
public:
    void use()
    {
        std::cout << "Use Knife to Kill U!" << std::endl;
    }
};

class Sprite
{
public:
    Sprite(Weapon* wp)
    {
        m_wp = wp;
    }

public:
    void setWeapon(Weapon* wp)
    {
         m_wp = wp;
    }

    void fight()
    {
        m_wp->use();
    }

private:
    Weapon* m_wp;
};

int mainSM()
{
    Gun g;
    Knife k;
    Sprite sp(&g);
    sp.fight();

    sp.setWeapon(&k);
    sp.fight();

    // 增加Weapon的代码，只需要增加Weapon的子类就好，Weapon是不用改的，那么Sprite也不用改
    // 符合开闭原则

    // 策略模式就是2步：1. 选择策略，2. 执行

    return 0;
}
