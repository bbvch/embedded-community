#include "read_promise.h"

#include "read_result.h"
#include "read_awaiter.h"

#include <iostream>

ReadResult ReadPromise::get_return_object()
{
    return { *this };
}

ReadAwaiter ReadPromise::await_transform(int value) const noexcept
{
    return { value };
}

void ReadPromise::return_value(std::string buffer)
{
    std::cout << "ReadPromise: return_value: " << buffer << std::endl;
    m_buffer = std::move(buffer);
}

std::suspend_always ReadPromise::final_suspend() const noexcept
{
    std::cout << "ReadPromise: final_suspend" << std::endl;
    return {};
}
