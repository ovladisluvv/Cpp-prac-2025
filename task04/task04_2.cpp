#include <iostream>
#include <vector>
#include <algorithm>

void
process(std::vector<long> &arr, long limit)
{
    std::vector<long> to_add;
    
    for (auto &elem : arr) {
        if (elem >= limit) {
            to_add.push_back(elem);
        }
    }
    
    std::reverse(to_add.begin(), to_add.end());
    arr.insert(arr.end(), to_add.begin(), to_add.end());
}
