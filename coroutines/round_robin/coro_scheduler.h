#pragma once

#include <deque>
#include <memory>

#include "definitions.h"

class CoroScheduler
{
public:
    ~CoroScheduler();
    void enqueCoroutine(CoroEHandle&& handle);
    CoroEHandle dequeCoroutine();
    void executeRound();

private:
    std::deque<CoroEHandle> m_queue;
};
