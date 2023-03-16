#include "schedule_next_awaiter.h"

#include "coro_scheduler.h"
#include "coro_promise.h"

CoroEHandle ScheduleNextAwaiter::await_suspend(CoroPHandle handle) const noexcept
{
    auto scheduler = handle.promise().m_scheduler.lock();
    if (m_storeSuspending)
    {
        scheduler->enqueCoroutine(handle);
    }
    else
    {
        handle.destroy();
    }
    return scheduler->dequeCoroutine();
}

