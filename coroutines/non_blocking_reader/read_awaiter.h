#pragma once

#include "read_result.h"
#include "read_stub.h"

struct ReadAwaiter
{
    int m_value{ 0 };
    bool await_ready() const { return m_value != ReadStub::WOULDBLOCK; }
    void await_suspend(const ReadResult::handle_type & _) const;
    int await_resume() const;
};
