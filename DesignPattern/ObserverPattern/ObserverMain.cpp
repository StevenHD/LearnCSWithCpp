//
// Created by helianhaodong on 2021/5/8.
//

#include "CanadaTime.h"
#include "LondonTime.h"
#include "BeiJingTime.h"

int mainOR()
{
    CanadaTime  ct;
    LondonTime  lt;
    BeiJingTime bt;

    bt.registerObserver(&ct);
    bt.registerObserver(&lt);

    bt.setTime(100, 200, 300);

    std::cout << "==========" << std::endl;
    bt.removeObserver(&lt);
    bt.setTime(100, 200, 300);

    return 0;
}