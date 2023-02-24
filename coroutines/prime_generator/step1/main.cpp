#include "generator.h"

#include <iostream>
#include <iomanip>

int main()
{
	auto primeGenerator = createPrimes(40000);

	auto pos{ 0 };
	while (primeGenerator.next())
	{
		std::cout << std::setw(8) << primeGenerator.value();
		if (++pos % 10 == 0)
		{
			std::cout << std::endl;
		}
	}

	return 0;
}