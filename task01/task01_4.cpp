#include <iostream>
#include <iomanip>
#include <cmath>

int
main()
{
    constexpr int PRECISION = 10;
    double cur_num, arithm_avg = 0, std_deviation = 0;
    int n = 0;

    while (std::cin >> cur_num) {
        arithm_avg += cur_num;
        std_deviation += cur_num * cur_num;
        ++n;
    }

    arithm_avg /= n;
    std_deviation = sqrt(std_deviation / n - arithm_avg * arithm_avg);
    std::cout << std::fixed << std::setprecision(PRECISION) << arithm_avg << std::endl << std_deviation << std::endl;
}
