#pragma once

#include <coroutine>
#include <memory>

class CoroScheduler;
using CoroSchedulerPtr = std::shared_ptr<CoroScheduler>;

struct CoroPromise;
using CoroPHandle = std::coroutine_handle<CoroPromise>;
using CoroEHandle = std::coroutine_handle<>;

struct ScheduleNextAwaiter;

struct ScheduleNext{};

template<typename... Ts>
struct std::coroutine_traits<void, const CoroSchedulerPtr&, Ts...>
{
    using promise_type = CoroPromise;
};

