
import simpsons;

#include <iostream>

int main()
{
    const auto homer = simpsons::Homer();
    std::cout << "Hi, I'm " << homer.getName() << std::endl;
    std::cout << "Hi, I'm " << simpsons::Lisa().getName() << std::endl;
    std::cout << "Hi, I'm " << simpsons::Bart().getName() << std::endl;
    std::cout << "Hi, I'm " << simpsons::Marge().getName() << std::endl;

    // auto person = simpsons::Person();
    // (fails to compile since class Person is not exported by the module, it's
    // just in a partition which is kept internal)

    return 0;
}
