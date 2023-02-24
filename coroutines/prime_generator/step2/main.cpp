#include "generator.h"
#include "printer.h"

int main()
{
	auto primeGenerator = createPrimes(40000);
	const auto printer = createPrinter();

	while (primeGenerator.next())
	{
		printer.print(primeGenerator.value());
	}

	return 0;
}