#pragma once

#include "definitions.h"


struct CoroPromise
{
    template<typename... Ts>
    CoroPromise(const CoroSchedulerPtr& scheduler, Ts...) noexcept : m_scheduler{scheduler} {}
    void get_return_object() const noexcept {}
    std::suspend_always initial_suspend();
    ScheduleNextAwaiter await_transform(const ScheduleNext&) const noexcept;
    ScheduleNextAwaiter final_suspend() const noexcept;

    void unhandled_exception() const noexcept {}

    CoroSchedulerPtr::weak_type m_scheduler;
};
