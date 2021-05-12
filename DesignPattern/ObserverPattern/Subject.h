//
// Created by helianhaodong on 2021/5/8.
//

#ifndef MODERNCPP_SUBJECT_H
#define MODERNCPP_SUBJECT_H

#include "../../all.h"
#include "Observer.h"

class Subject
{
public:
    Subject();

    void registerObserver(Observer* ob);
    void removeObserver(Observer* ob);

    virtual void notify();

protected:
    std::list<Observer*> m_obsvrList;
};


#endif //MODERNCPP_SUBJECT_H
