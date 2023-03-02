#pragma once

#include <coroutine>
#include <string>

struct ReadPromise;

class ReadResult
{
public:
	using promise_type = ReadPromise;
	using handle_type = std::coroutine_handle<ReadPromise>;

	ReadResult(ReadPromise& promise) : m_handle{ handle_type::from_promise(promise) } {}
	~ReadResult() { m_handle.destroy(); }
	bool hasResult() const;
	std::string getResult() const;

private:
	handle_type m_handle;
};