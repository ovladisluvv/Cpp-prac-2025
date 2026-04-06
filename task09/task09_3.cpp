#include <iostream>
#include <iomanip>
#include <cctype>

// S -> ABCD
// AB-> AABB
// CD-> CCDD
// BC-> CB
// A -> a
// B -> b
// C -> 0
// D -> 1

enum class States
{
    A = 0,
    B = 1,
    ZERO = 2,
    ONE = 3
};

int
in_lang(unsigned char &cur_char)
{
    States cur_state = States::A;
    int count_a = 1, count_b = 0, count_0 = 0, count_1 = 0;
    bool flag = true;

    if (cur_char != 'a') {
        flag = false;
    }

    while (std::cin >> cur_char && !isspace(cur_char)) {
        if (cur_state == States::ONE && count_0 < count_1) {
            flag = false;
        }

        if (cur_state == States::B && count_a < count_b) {
            flag = false;
        }

        if (!flag) {
            continue;
        }

        switch (cur_state) {
        case (States::A):
            switch (cur_char) {
            case 'a':
                ++count_a;
                break;

            case '0':
                ++count_0;
                cur_state = States::ZERO;
                break;

            default:
                flag = false;
            }

            break;

        case (States::B):
            switch (cur_char) {
            case 'b':
                ++count_b;
                break;

            case '1':
                ++count_1;
                cur_state = States::ONE;
                break;

            default:
                flag = false;
            }

            break;

        case (States::ZERO):
            switch (cur_char) {
            case '0':
                ++count_0;
                break;

            case 'b':
                ++count_b;
                cur_state = States::B;
                break;

            default:
                flag = false;
            }

            break;

        case (States::ONE):
            switch (cur_char) {
            case '1':
                ++count_1;
                break;

            default:
                flag = false;
            }

            break;
        }
    }

    return flag && count_a == count_b && count_0 == count_1 && count_a > 0 && count_0 > 0;
}

int
main()
{
    unsigned char cur_char;
    std::cin >> std::noskipws;

    while (std::cin >> cur_char) {
        if (!isspace(cur_char)) {
            std::cout << in_lang(cur_char) << std::endl;
        }
    }
}