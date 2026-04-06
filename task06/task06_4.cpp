#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

template <typename Iter_num, typename Iter_elems>
Iter_elems
myremove(Iter_num it_num_begin, Iter_num it_num_end, Iter_elems it_el_begin, Iter_elems it_el_end)
{
    std::vector<int> ind_vec(it_num_begin, it_num_end);
    std::sort(ind_vec.begin(), ind_vec.end());
    ind_vec.erase(std::unique(ind_vec.begin(), ind_vec.end()), ind_vec.end());

    int cur_ind = 0;
    Iter_elems ans = it_el_begin;

    for (Iter_elems it = it_el_begin; it != it_el_end; ++it, ++cur_ind) {
        if (std::find(ind_vec.begin(), ind_vec.end(), cur_ind) == ind_vec.end()) {
            if (it != ans) {
                std::swap(*ans, *it);
            }
            ++ans;
        }
    }

    return ans;
}
