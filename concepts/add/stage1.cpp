#include <type_traits>
#include <string_view>
#include <iostream>

using namespace std::literals::string_literals;

auto add(auto arg1, auto arg2)
{
    return arg1 + arg2;
}

int main()
{
    std::cout << "39 + 3 = " << add(39, 3) << std::endl;
    std::cout << "25 + 3.14 = " << add(25, 3.14) << std::endl;
    std::cout << "13 + \"hello\" = " << add(13, "hello") << std::endl;
//    std::cout << "-22 + \"world\"s = " << add(-22, "world"s) << std::endl;
}
