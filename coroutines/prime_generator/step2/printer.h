#pragma once

#include <coroutine>

struct PrinterPromise;

class Printer
{
public:
	using promise_type = PrinterPromise;
	using handle_type = std::coroutine_handle<PrinterPromise>;

	Printer(PrinterPromise& promise);
	~Printer() { m_handle.destroy(); }
	void print(int value) const;

private:
	handle_type m_handle;
};

//---------------------------------------------------------------------------------------------------------------------

Printer createPrinter();

