#include "read_result.h"

#include "read_promise.h"

#include <iostream>

bool ReadResult::hasResult() const
{
    if (m_handle.done())
    {
        return true;
    }
    else
    {
        std::cout << "ReadResult: --> to coroutine" << std::endl;
        m_handle.resume();
        std::cout << "ReadResult: <-- from coroutine" << std::endl;
        return m_handle.done();
    }
}

std::string ReadResult::getResult() const
{
    return m_handle.promise().m_buffer;
}
