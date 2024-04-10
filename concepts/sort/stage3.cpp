#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <iostream>

template<typename It>
concept forward_it =
    std::is_base_of<std::forward_iterator_tag,
                    typename std::iterator_traits<It>::iterator_category>::value;

template<typename It>
concept random_access_it =
    forward_it<It> &&
    std::is_base_of<std::random_access_iterator_tag, 
                    typename std::iterator_traits<It>::iterator_category>::value;

template<random_access_it It>
void my_sort(It first, It last)
{
    std::sort(first, last);
}

template<forward_it It>
void my_sort(It first, It last)
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

    my_sort(d.begin(), d.end());
    print(d.begin(), d.end());
    my_sort(l.begin(), l.end());
    print(l.begin(), l.end());
//    my_sort(2, 5);
}
