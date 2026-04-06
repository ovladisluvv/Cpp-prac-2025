#include <iostream>
#include <vector>
#include <list>
#include <functional>

template <typename Iterator, typename Function>
void
myapply(Iterator begin, Iterator end, Function f)
{
    for (Iterator it = begin; it != end; ++it) {
        f(*it);
    }
}

template <typename Iterator, typename Predicate>
auto
myfilter2(Iterator begin, Iterator end, Predicate pred)
{
    std::vector<std::reference_wrapper<typename std::iterator_traits<Iterator>::value_type>> ans;

    for (Iterator it = begin; it != end; ++it) {
        if (pred(*it)) {
            ans.push_back(*it);
        }
    }

    return ans;
}
