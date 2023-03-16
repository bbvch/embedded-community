#include "example_task.h"

#include "definitions.h"
#include "coro_promise.h"
#include "schedule_next_awaiter.h"

#include <iostream>

void exampleTask1(const CoroSchedulerPtr& sched, std::string_view msg, int iterations)
{
    for (auto i{0}; i < iterations; ++i)
    {
        std::cout << "exampleTask1: " << msg << std::endl;
        co_await ScheduleNext{};
    }
}

void exampleTask2(const CoroSchedulerPtr& sched, std::string_view msg)
{
    while (true)
    {
        std::cout << "exampleTask2: " << msg << std::endl;
        co_await ScheduleNext{};
    }
}
