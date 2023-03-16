#include "coro_promise.h"

#include "coro_scheduler.h"
#include "schedule_next_awaiter.h"

std::suspend_always CoroPromise::initial_suspend()
{
    m_scheduler.lock()->enqueCoroutine(CoroPHandle::from_promise(*this));
    return {};
}


ScheduleNextAwaiter CoroPromise::await_transform(const ScheduleNext &) const noexcept
{ 
    return {true};
}


ScheduleNextAwaiter CoroPromise::final_suspend() const noexcept 
{
    return {false};
}
