#include "generator.h"

#include <iostream>
#include <iomanip>

int main()
{
	auto primes = createPrimes(40000);

	auto pos{ 0 };
	for (const auto number : primes)
	{
		std::cout << std::setw(8) << number;
		if (++pos % 10 == 0)
		{
			std::cout << std::endl;
		}
	}

	return 0;
}