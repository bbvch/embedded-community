#pragma once

#include "definitions.h"

struct ScheduleNextAwaiter
{
    ScheduleNextAwaiter(bool storeSuspending) noexcept : m_storeSuspending{storeSuspending} {}
    bool await_ready() const noexcept { return false; }
    CoroEHandle await_suspend(CoroPHandle handle) const noexcept;
    void await_resume() const noexcept {}

    bool m_storeSuspending;
};
