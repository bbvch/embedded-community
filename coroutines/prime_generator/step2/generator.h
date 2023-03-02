#pragma once

#include <coroutine>

struct PrimePromise;

class PrimeGenerator
{
public:
	using promise_type = PrimePromise;
	using handle_type = std::coroutine_handle<PrimePromise>;

	PrimeGenerator(PrimePromise& promise);
	~PrimeGenerator() { m_handle.destroy(); }
	bool next();
	int value() const;

private:
	handle_type m_handle;
};

//---------------------------------------------------------------------------------------------------------------------

PrimeGenerator createPrimes(int upperLimit);
