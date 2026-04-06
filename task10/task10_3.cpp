#include <iostream>
#include <string>
#include <map>
#include <set>

int
main()
{
    constexpr const char END[] = "END";

    std::map<std::pair<std::string, char>, std::string> func_map;
    std::set<std::string> term_states;

    std::string CUR, NEW;
    char CHAR;

    while (std::cin >> CUR && CUR != END) {
        std::cin >> CHAR >> NEW;
        func_map[{CUR, CHAR}] = NEW;
    }

    while ((std::cin >> NEW) && NEW != END) {
        term_states.insert(NEW);
    }

    std::string cur_state;
    std::cin >> cur_state;

    int count = 0;
    bool flag = false;
    char cur_char;

    while ((std::cin >> cur_char)) {
        if (func_map.contains({cur_state, cur_char})) {
            cur_state = func_map.at({cur_state, cur_char});
            ++count;
        } else {
            flag = true;
            break;
        }
    }

    flag = flag || !term_states.contains(cur_state);

    std::cout << !flag << std::endl << count << std::endl << cur_state << std::endl;
}
