
import someMath;
import fibonacci;

#include <iostream>

int main()
{
    static constexpr int N = 6;
    std::cout << "Factorial of the " << N << "-th Fibonacci number (" << oneModulePerFile::fibonacci(N)
              << "): " << oneModulePerFile::fibofact(N) << std::endl;
    return 0;
}
