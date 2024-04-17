
module;

#include <math.h>

export module factorial;

namespace oneModulePerFile
{

export template <typename T>
class Factorial
{
public:
    explicit Factorial(T N)
        : num(N)
    {
    }

    unsigned long long getValue()
    {
        return static_cast<unsigned long long>(std::round(tgamma(num + 1)));
    }

private:
    T num;
};

} // namespace oneModulePerFile
