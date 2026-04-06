#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <format>

class Date
{
    int year;
    int month;
    int day;

public:
    Date(std::string &str_date) {
        std::istringstream iss(str_date);
        char temp_ch;
        iss >> year >> temp_ch >> month >> temp_ch >> day;
    }

    bool operator<(const Date &other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    std::string to_str() const {
        return std::format("{:04}/{:02}/{:02}", year, month, day);
    }
};

int
main()
{
    std::map<std::string, std::map<Date, int>> stud_map;
    std::set<std::string> studs;
    std::set<Date> dates;
    std::string cur_stud;
    std::string str_date;
    int cur_grade;

    while (std::cin >> cur_stud >> str_date >> cur_grade) {
        studs.insert(cur_stud);
        Date cur_date(str_date);
        dates.insert(cur_date);
        stud_map[cur_stud][cur_date] = cur_grade;
    }

    std::cout << ".";
    for (const auto &date : dates) {
        std::cout << " " << date.to_str();
    }
    std::cout << std::endl;

    for (const auto &stud : studs) {
        std::cout << stud;
        for (auto &date : dates) {
            auto it = stud_map[stud].find(date);
            if (it != stud_map[stud].end()) {
                std::cout << " " << it->second;
            } else {
                std::cout << " .";
            }
        }
        std::cout << "\n";
    }
}
