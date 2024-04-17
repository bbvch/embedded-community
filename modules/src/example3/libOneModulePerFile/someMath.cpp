
module someMath;

import factorial;
import fibonacci;


namespace oneModulePerFile
{

int fibofact(int N)
{
    return Factorial<int>(fibonacci(N)).getValue();
}

} // namespace oneModulePerFile
