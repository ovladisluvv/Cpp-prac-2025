#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>

std::chrono::year_month_day parse_date(const std::string &date) {
    std::istringstream iss(date);
    int y, m, d;
    char sep;
    iss >> y >> sep >> m >> sep >> d;
    return static_cast<std::chrono::year>(y) / static_cast<std::chrono::month>(m) / static_cast<std::chrono::day>(d);
}

int main() {
    std::vector<std::chrono::sys_days> day_arr;
    std::string cur_date;

    while (std::cin >> cur_date) {
        day_arr.push_back(static_cast<std::chrono::sys_days>(parse_date(cur_date)));
    }

    int ans = 0;
    for (size_t i = 0; i < day_arr.size() - 1; ++i) {
        ans += std::chrono::abs((day_arr[i] - day_arr[i + 1])).count();
    }

    std::cout << ans << std::endl;
}
