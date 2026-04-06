#include <iostream>
#include <array>

class Matrix
{
    static constexpr int SIZE = 3;
    std::array<std::array<int, SIZE>, SIZE> matrix{};

  public:
    int &
    operator[](std::size_t i, std::size_t j)
    {
        return matrix[i][j];
    }

    auto
    begin()
    {
        return matrix.begin();
    }

    auto
    end()
    {
        return matrix.end();
    }
};
