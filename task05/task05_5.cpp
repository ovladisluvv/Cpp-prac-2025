#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <limits>

constexpr uint32_t MOD = 4294967161;

struct Matrix_el
{
    uint32_t row;
    uint32_t col;
    uint64_t val;

    bool
    operator<(const Matrix_el &other) const
    {
        if (row != other.row) {
            return row < other.row;
        }
        return col < other.col;
    }
};

void
read_matr(std::vector<Matrix_el> &matr)
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
matr_el_mul(uint64_t a, uint64_t b)
{
    return (a * b) % MOD;
}

uint64_t
matr_el_add(uint64_t a, uint64_t b)
{
    a %= MOD;
    b %= MOD;
    return (a >= MOD - b) ? (a - (MOD - b)) : (a + b);
}

std::vector<Matrix_el>
get_mul_matr(const std::vector<Matrix_el> &matr1, const std::vector<Matrix_el> &matr2)
{
    std::unordered_map<uint32_t, std::vector<Matrix_el>> matr2_rows;
    for (const auto &el : matr2) {
        matr2_rows[el.row].push_back(el);
    }

    std::unordered_map<uint64_t, uint32_t> res_map;
    auto hash = [](uint32_t row, uint32_t col) {
        return (uint64_t(row) << CHAR_BIT * sizeof(col)) | col;
    };

    for (const auto &el1 : matr1) {
        auto it = matr2_rows.find(el1.col);
        if (it != matr2_rows.end()) {
            for (const auto &el2 : it->second) {
                uint64_t key = hash(el1.row, el2.col);
                res_map[key] = matr_el_add(res_map[key], matr_el_mul(el1.val, el2.val));
            }
        }
    }

    std::vector<Matrix_el> res;
    for (const auto &[key, val] : res_map) {
        if (val) {
            uint32_t row = uint32_t(key >> CHAR_BIT * sizeof(val));
            uint32_t col = uint32_t(key & std::numeric_limits<uint32_t>::max());
            res.push_back({row, col, val});
        }
    }

    return res;
}

int
main()
{
    std::vector<Matrix_el> matr1, matr2;
    read_matr(matr1);
    read_matr(matr2);

    std::vector<Matrix_el> res = get_mul_matr(matr1, matr2);
    std::sort(res.begin(), res.end());

    for (const auto &el : res) {
        std::cout << el.row << " " << el.col << " " << el.val << std::endl;
    }
}