#include <iostream>
#include <string>

enum class States
{
    INIT = 0,
    FIRST = 1,
    SECOND = 2
};

enum class Symbols
{
    ALPHA1 = '3',
    ALPHA2 = '4',
    BETA1 = '1',
    BETA2 = '2'
};

int
main()
{
    std::string str;

    while (std::cin >> str) {
        bool flag = true;
        States cur_state = States::INIT;

        if (str[0] == char(Symbols::ALPHA1) || str[0] == char(Symbols::ALPHA2)) {
            cur_state = States::FIRST;
        } else {
            cur_state = States::SECOND;
        }

        for (const auto &cur_char : str) {
            bool is_alpha = (cur_char == char(Symbols::ALPHA1) || cur_char == char(Symbols::ALPHA2));
            bool is_beta = (cur_char == char(Symbols::BETA1) || cur_char == char(Symbols::BETA2));

            if (!is_alpha && !is_beta) {
                flag = false;
            }

            if (flag && cur_state == States::FIRST) {
                if (is_beta) {
                    cur_state = States::SECOND;
                } else if (!is_alpha) {
                    flag = false;
                }
            } 
            
            if (flag && cur_state == States::SECOND) {
                if (!is_beta) {
                    flag = false;
                }
            }
        }

        if (cur_state != States::INIT) {
            std::cout << flag << std::endl;
        }
    }
}
