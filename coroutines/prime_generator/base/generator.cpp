#include "generator.h"

#include <cmath>
#include <algorithm>

std::vector<int> createPrimes(int upperLimit)
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
		}
	}
	return primes;
}
