#include <type_traits>
#include <string_view>
#include <iostream>

using namespace std::literals::string_literals;

template<typename T1, typename T2>
concept addable = requires(T1 t1, T2 t2)
{
    { t1 + t2 } -> std::convertible_to<std::common_type_t<T1, T2>>;
};

template<typename T1, typename T2> requires addable<T1, T2>
auto add(T1 arg1, T2 arg2)
{
    return arg1 + arg2;
}

int main()
{
    std::cout << "39 + 3 = " << add(39, 3) << std::endl;
    std::cout << "25 + 3.14 = " << add(25, 3.14) << std::endl;
//    std::cout << "13 + \"hello\" = " << add(13, "hello") << std::endl;
//    std::cout << "-22 + \"world\"s = " << add(-22, "world"s) << std::endl;
}
