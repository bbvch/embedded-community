#pragma once

#include <coroutine>

struct PrimePromise;

class PrimeGenerator
{
public:
	using promise_type = PrimePromise;
	using handle_type = std::coroutine_handle<PrimePromise>;

	PrimeGenerator(PrimePromise& promise) : m_handle{ handle_type::from_promise(promise) } {}
	~PrimeGenerator() { m_handle.destroy(); }
	bool next();
	int value() const;

private:
	handle_type m_handle;
};

//---------------------------------------------------------------------------------------------------------------------

PrimeGenerator createPrimes(int upperLimit);
