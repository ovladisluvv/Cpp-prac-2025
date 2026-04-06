#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void
process(const std::vector<int> &arr1, std::vector<int> &arr2)
{
    if (arr1.empty() || arr2.empty()) {
        return;
    }

    std::set<int> ind_set;

    for (int ind : arr1) {
        if (ind >= 0 && ind < static_cast<int>(arr2.size())) {
            ind_set.insert(ind);
        }
    }
    
    for (auto it = ind_set.rbegin(); it != ind_set.rend(); ++it) {
        arr2.erase(arr2.begin() + *it);
    }
}
