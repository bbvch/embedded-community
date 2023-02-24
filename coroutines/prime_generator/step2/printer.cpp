#include "printer.h"

#include <coroutine>
#include <iostream>
#include <iomanip>

struct PrinterPromise
{
	Printer get_return_object() { return { *this }; }
	constexpr std::suspend_never initial_suspend() const noexcept { return {}; }
	constexpr void return_void() const noexcept {}
	constexpr std::suspend_never final_suspend() const noexcept { return {}; }

	constexpr void unhandled_exception() const noexcept {}

	int m_value{ 0 };
};

//---------------------------------------------------------------------------------------------------------------------

struct PrinterAwaiter
{
	constexpr bool await_ready() const noexcept { return false; }
	void await_suspend(const Printer::handle_type& handle) { m_promise = &handle.promise(); }
	constexpr int await_resume() const noexcept { return m_promise->m_value; }

	PrinterPromise* m_promise {};
};

//---------------------------------------------------------------------------------------------------------------------

void Printer::print(int value) const
{
	m_handle.promise().m_value = value;
	m_handle.resume();
}

//---------------------------------------------------------------------------------------------------------------------

Printer createPrinter()
{
	auto pos{ 0 };
	while (true)
	{
		std::cout << std::setw(8) << co_await PrinterAwaiter{};
		if (++pos % 10 == 0)
		{
			std::cout << std::endl;
		}
	}
}

