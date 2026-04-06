#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
#include <limits>

constexpr uint32_t MOD = 4294967161;

struct matrix_el
{
    uint32_t row;
    uint32_t col;
    uint64_t val;

    bool
    operator<(const matrix_el &other) const
    {
        if (row != other.row) {
            return row < other.row;
        }
        return col < other.col;
    }
};

void
read_matr(std::vector<matrix_el> &matr)
{
    uint32_t cur_row, cur_col;
    uint64_t cur_val;

    while (std::cin >> cur_row >> cur_col >> cur_val) {
        if (!cur_row && !cur_col && cur_val == MOD) {
            return;
        }
        matr.push_back({cur_row, cur_col, cur_val % MOD});
    }
}

uint64_t
matr_el_add(uint64_t a, uint64_t b)
{
    a %= MOD;
    b %= MOD;
    return (a >= MOD - b) ? (a - (MOD - b)) : (a + b);
}

std::vector<matrix_el>
get_sum_matr(std::vector<matrix_el> &matr1, std::vector<matrix_el> &matr2)
{
    std::unordered_map<uint64_t, uint32_t> sum_map;

    auto hash = [](uint32_t row, uint32_t col) { return (static_cast<uint64_t>(row) << CHAR_BIT * sizeof(uint32_t)) | col; };

    for (const auto &el : matr1) {
        uint64_t key = hash(el.row, el.col);
        sum_map[key] = el.val;
    }

    for (const auto &el : matr2) {
        uint64_t key = hash(el.row, el.col);
        sum_map[key] = matr_el_add(sum_map[key], el.val);
    }

    std::vector<matrix_el> res;
    for (auto &el : sum_map) {
        if (el.second) {
            uint32_t row = static_cast<uint32_t>(el.first >> CHAR_BIT * sizeof(uint32_t));
            uint32_t col = static_cast<uint32_t>(el.first & std::numeric_limits<uint32_t>::max());
            res.push_back({row, col, el.second});
        }
    }

    return res;
}

int
main()
{
    std::vector<matrix_el> matr1, matr2;
    read_matr(matr1);
    read_matr(matr2);

    std::vector<matrix_el> res = get_sum_matr(matr1, matr2);
    std::sort(res.begin(), res.end());

    for (const auto &el : res) {
        std::cout << el.row << " " << el.col << " " << el.val << std::endl;
    }
}
