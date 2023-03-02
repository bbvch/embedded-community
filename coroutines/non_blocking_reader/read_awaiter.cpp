#include "read_awaiter.h"

#include <iostream>

void ReadAwaiter::await_suspend(const ReadResult::handle_type & _) const
{
	std::cout << "ReadAwaiter: suspend" << std::endl;
}

int ReadAwaiter::await_resume() const
{
	std::cout << "ReadAwaiter: resume" << std::endl;
	return m_value;
}
