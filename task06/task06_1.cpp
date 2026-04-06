#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <numeric>

template <typename Container>
auto
process(const Container &cont)
{
    using val_type = typename Container::value_type;
    if (cont.empty()) {
        return val_type{};
    }

    constexpr int STEP = 2, LIMIT = 5;

    auto it = cont.rbegin();
    val_type sum = *it;

    for (int i = 0; i < LIMIT && it != cont.rend(); ++i, ++it) {
        if (i && !(i % STEP)) {
            sum += *it;
        }
    }

    return sum;
}
