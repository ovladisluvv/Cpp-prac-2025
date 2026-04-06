#include <iostream>
#include <vector>

void
process(const std::vector<unsigned long> &arr1, std::vector<unsigned long> &arr2, size_t step)
{
    auto it1 = arr1.begin();
    auto it2 = arr2.rbegin();

    while (it2 != arr2.rend() && it1 != arr1.end()) {
        *it2 += *it1;
        if (std::distance(arr1.begin(), it1) + step <= arr1.size()) {
            std::advance(it1, step);
        } else {
            it1 = arr1.end();
        }
        ++it2;
    }
}
