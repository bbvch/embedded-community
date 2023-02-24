#include "generator.h"

#include <cmath>
#include <algorithm>
#include <vector>

struct PrimePromise
{
	PrimeGenerator get_return_object() { return { *this }; }
	std::suspend_always initial_suspend() { return {}; }
	std::suspend_always yield_value(int value) { m_value = value; return {}; }
	void return_void() {}
	std::suspend_always final_suspend() noexcept { return {}; }

	void unhandled_exception() { }

	int m_value{ 0 };
};

//---------------------------------------------------------------------------------------------------------------------

bool PrimeGenerator::next()
{
	if (!m_handle.done())
	{
		m_handle.resume();
	}
	return !m_handle.done();
}

int PrimeGenerator::value() const
{
	return !m_handle.done() ? m_handle.promise().m_value : 0;
}

//---------------------------------------------------------------------------------------------------------------------


PrimeGenerator createPrimes(int upperLimit)
{
	std::vector<int> primes;
	for (auto candidate{ 2 }; candidate <= upperLimit; ++candidate)
	{
		auto primeFound{ true };
		const auto upperDivisorLimit = static_cast<int>(std::sqrt(candidate));
		const auto itEnd = std::upper_bound(primes.begin(), primes.end(), upperDivisorLimit);
		for (auto it{primes.begin()}; it != itEnd; ++it)
		{
			if (candidate % *it == 0)
			{
				primeFound = false;
				break;
			}
		}
		if (primeFound)
		{
			primes.push_back(candidate);
			co_yield candidate;
		}
	}
	co_return;
}

