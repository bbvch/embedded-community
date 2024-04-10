#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <iostream>

template<typename It>
void my_regular_sort(It first, It last)
{
    std::sort(first, last);
}

template<typename It>
void my_copy_sort(It first, It last)
{
    using value_type = typename std::iterator_traits<It>::value_type;
    std::vector<value_type> copy_cont{first, last};
    std::sort(copy_cont.begin(), copy_cont.end());
    std::copy(copy_cont.begin(), copy_cont.end(), first);
}

template <typename It>
void print(It first, It last)
{
    using value_type = typename std::iterator_traits<It>::value_type;
    std::copy(first, last, std::ostream_iterator<value_type>(std::cout, " "));
    std::cout << std::endl;
}
int main()
{
    std::deque<int> d = {-20, 30, 5};
    std::list<double> l = {3.14, -1.5, 10.2};

    my_regular_sort(d.begin(), d.end());
    print(d.begin(), d.end());
    my_copy_sort(l.begin(), l.end());
//    my_regular_sort(l.begin(), l.end());
    print(l.begin(), l.end());
}
