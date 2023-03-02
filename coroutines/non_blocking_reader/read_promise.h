#pragma once

#include <coroutine>
#include <string>

class ReadResult;
struct ReadAwaiter;

struct ReadPromise
{
	ReadResult get_return_object();
	std::suspend_never initial_suspend() const noexcept { return {}; }
	ReadAwaiter await_transform(int value) const noexcept;
	void return_value(std::string buffer);
	void unhandled_exception() {}
	std::suspend_always final_suspend() const noexcept;

	std::string m_buffer;
};