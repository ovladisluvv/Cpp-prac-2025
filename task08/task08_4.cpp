#include <iostream>
#include <complex>
#include <array>
#include <vector>
#include <limits>

namespace Equations
{
template <typename T>
std::pair<bool, std::vector<std::complex<T>>>
quadratic(std::array<std::complex<T>, 3> v)
{
    constexpr T EPS = 32 * std::numeric_limits<T>::epsilon();
    constexpr T K1 = 4;
    constexpr T K2 = 2;

    if (std::norm<T>(v[2]) < EPS) {
        if (std::norm<T>(v[1]) < EPS) {
            return {!(std::norm<T>(v[0]) < EPS), {}};
        }

        std::complex<T> x = -v[0] / v[1];

        return {true, {x}};
    }

    std::complex<T> D = v[1] * v[1] - K1 * v[2] * v[0];
    std::complex<T> x1 = (-v[1] + std::sqrt(D)) / (K2 * v[2]);
    std::complex<T> x2 = (-v[1] - std::sqrt(D)) / (K2 * v[2]);

    return {true, {x1, x2}};
}
} // namespace Equations
