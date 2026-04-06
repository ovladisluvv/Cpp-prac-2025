#include <iostream>
#include <algorithm>
#include <cmath>

namespace Game
{
template <typename T> class Coord
{
  public:
    using value_type = T;
    T row = 0, col = 0;

    Coord() : row(0), col(0) {}
    Coord(T r) : row(r), col(0) {}
    Coord(T r, T c) : row(r), col(c) {}
};

template <typename T>
T
dist(const Coord<T> &size, const Coord<T> &p1, const Coord<T> &p2)
{
    T d_row = p2.row - p1.row;
    T d_col = p2.col - p1.col;
    T d_row_abs = std::abs(d_row);
    T d_col_abs = std::abs(d_col);
    T diag_step = std::min(d_row_abs, (d_col_abs + 1) / 2);
    if ((!(p1.col & 1) && d_row < 0) || (p1.col & 1 && d_row > 0)) {
        diag_step = std::min(d_row_abs, (d_col_abs) / 2);
    }
    return std::abs(d_row) + std::abs(d_col) - diag_step;
}
} // namespace Game