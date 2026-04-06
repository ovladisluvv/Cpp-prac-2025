#include <iostream>
#include <vector>
#include <iterator>

template <typename Iterator, typename Compare = std::less<>>
void
selection_sort(Iterator begin, Iterator end, Compare compare = Compare())
{
    for (Iterator it = begin; it != end; ++it) {
        Iterator min_it = it;

        for (Iterator jt = it + 1; jt != end; ++jt) {
            if (compare(*jt, *min_it)) {
                min_it = jt;
            }
        }

        if (min_it != it) {
            std::iter_swap(it, min_it);
        }
    }
}
