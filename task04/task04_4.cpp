#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Avg_calc
{
    double sum = 0.0;
    size_t count = 0;

  public:
    Avg_calc(double sum_ = 0.0, int count_ = 0) : sum(sum_), count(count_) {}

    void
    operator()(double val)
    {
        sum += val;
        ++count;
    }

    double
    get_res() const
    {
        return count ? sum / count : 0.0;
    }
};

int
main()
{
    constexpr int FIRST_DISCARD_PERCENT = 10, SECOND_DISCARD_PERCENT = 10, LEFT_RIGHT_DISCARDING = 2,
                  ALL_PERCENTS = 100;

    std::vector<double> val_arr;
    double num;

    while (std::cin >> num) {
        val_arr.push_back(num);
    }

    size_t n = val_arr.size();
    int extra = n * FIRST_DISCARD_PERCENT / ALL_PERCENTS;
    std::sort(val_arr.begin() + extra, val_arr.end() - extra);

    int new_extra = (n - LEFT_RIGHT_DISCARDING * extra) * SECOND_DISCARD_PERCENT / ALL_PERCENTS;
    Avg_calc avg_calc =
        std::for_each(val_arr.begin() + extra + new_extra, val_arr.end() - extra - new_extra, Avg_calc());

    std::cout << std::fixed << std::setprecision(10) << avg_calc.get_res() << std::endl;

    return 0;
}
