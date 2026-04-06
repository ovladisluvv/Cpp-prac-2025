#include <iostream>
#include <map>

struct Student
{
    double score_sum = 0;
    int score_count = 0;
};

int
main()
{
    std::map<std::string, Student> stud_map;
    std::string cur_name;
    double cur_score;

    while (std::cin >> cur_name >> cur_score) {
        auto &stud = stud_map[cur_name];
        stud.score_sum += cur_score;
        ++stud.score_count;
    }

    for (auto &[name, stud] : stud_map) {
        std::cout << name << ' ' << stud.score_sum / stud.score_count << std::endl;
    }
}