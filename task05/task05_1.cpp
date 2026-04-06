#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>

bool
compare(unsigned num1, unsigned num2)
{
    return std::popcount(num1) < std::popcount(num2);
}

int
main()
{
    unsigned num;
    std::vector<unsigned> num_arr;

    while (std::cin >> num) {
        num_arr.push_back(num);
    }

    std::stable_sort(num_arr.begin(), num_arr.end(), compare);

    for (auto it = num_arr.begin(); it != num_arr.end(); ++it) {
        std::cout << *it << std::endl;
    }
}
