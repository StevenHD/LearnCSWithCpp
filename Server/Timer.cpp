//
// Created by helianhaodong on 2021/4/26.
//

#include "Timer.h"

void TimerManager::addTimer(HttpRequest* req, int &time_out, const TimeoutCallback &cb)
{
    std::unique_lock<std::mutex> lck(m_mtx);
    assert(req != nullptr);

    updateTime();
    Timer* timer = new Timer(m_nowTime + MS(time_out), cb);
    m_timerQueue.push(timer);

    // 对同一个request连续调用两次addTimer，需要把前一个定时器删除
    if(req->getTimer() != nullptr)
    {
        delTimer(req);
    }

    req->setTimer(timer);
}

// 这个函数不必上锁，没有线程安全问题
// 若上锁，反而会因为连续两次上锁造成死锁：handleExpireTimers -> runCallBack -> __closeConnection -> delTimer
void TimerManager::delTimer(HttpRequest* req)
{
    assert(req != nullptr);

    Timer* timer = req -> getTimer();
    if (timer == nullptr) return;

    // 如果这里写成delete timeNode，会使priority_queue里的对应指针变成垂悬指针
    // 正确的方法是惰性删除
    timer -> del();

    // 防止request -> getTimer()访问到垂悬指针
    req -> setTimer(nullptr);
}

void TimerManager::handleExpiredTimers()
{
    std::unique_lock<std::mutex> lck(m_mtx);
    updateTime();

    while (!m_timerQueue.empty())
    {
        Timer* timer = m_timerQueue.top();
        assert(timer != nullptr);

        // 定时器被删除
        if (timer -> isDeleted())
        {
            m_timerQueue.pop();
            delete timer;
            continue;
        }

        // 优先队列头部的定时器也没有超时，return
        if (std::chrono::duration_cast<MS>(timer -> getExpiredTime() - m_nowTime).count() > 0)
        {
            return;
        }

        timer -> runCallBack();
        m_timerQueue.pop();
        delete timer;
    }
}

int TimerManager::getNearestExpiredTimer()
{
    std::unique_lock<std::mutex> lck(m_mtx);
    updateTime();
    int res = -1;

    while (!m_timerQueue.empty())
    {
        Timer* timer = m_timerQueue.top();
        if(timer -> isDeleted())
        {
            m_timerQueue.pop();
            delete timer;
            continue;
        }

        res = std::chrono::duration_cast<MS>(timer -> getExpiredTime() - m_nowTime).count();
        res = (res < 0) ? 0 : res;
        break;
    }

    return res;
}


