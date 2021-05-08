//
// Created by helianhaodong on 2021/5/8.
//

#include "Subject.h"

Subject::Subject()
{

}

void Subject::registerObserver(Observer* ob)
{
    m_obsvrList.push_back(ob);
}

void Subject::removeObserver(Observer* ob)
{
    m_obsvrList.remove(ob);
}

void Subject::notify()
{

}