#include "coro_scheduler.h"

CoroScheduler::~CoroScheduler() {
    for (auto& handle : m_queue) {
        handle.destroy();
    }
}

void CoroScheduler::enqueCoroutine(CoroEHandle &&handle) {
    m_queue.push_back(std::move(handle));
}

CoroEHandle CoroScheduler::dequeCoroutine() { 
    const auto popHandle = m_queue.front();
    m_queue.pop_front();
    return popHandle;
}

void CoroScheduler::executeRound() { 
    enqueCoroutine(std::noop_coroutine());
    dequeCoroutine().resume();
}



