#include <iostream>

enum class Symbols
{
    ZERO = '0',
    ONE = '1'
};

enum class States
{
    FIRST = 1,
    SECOND = 2,
    THIRD = 3,
    FOURTH = 4
};

void
check_word(unsigned char &cur_char, States &cur_state, int &cur_zeros, int &cur_ones, int &zeros, int &ones, bool &flag)
{
    bool stop = false;
    while (!stop && std::cin >> cur_char) {
        stop = false;
        if (isspace(cur_char)) {
            stop = true;

            if (cur_state == States::THIRD || cur_state == States::FOURTH) {
                if (cur_ones != ones || cur_zeros != zeros) {
                    flag = false;
                }
            }

            if (!ones || !zeros) {
                flag = false;
            }
        } else if (flag) {
            if (cur_char != static_cast<unsigned char>(Symbols::ONE) && cur_char != static_cast<unsigned char>(Symbols::ZERO)) {
                flag = false;
            } else {
                switch (cur_state) {
                case States::FIRST:
                    if (cur_char == static_cast<unsigned char>(Symbols::ZERO)) {
                        ++zeros;
                    } else if (cur_char == static_cast<unsigned char>(Symbols::ONE)) {
                        ++ones;
                        cur_state = States::SECOND;
                    }
                    break;

                case States::SECOND:
                    if (cur_char == static_cast<unsigned char>(Symbols::ZERO)) {
                        ++cur_zeros;
                        cur_state = States::THIRD;
                    } else if (cur_char == static_cast<unsigned char>(Symbols::ONE)) {
                        ++ones;
                    }
                    break;

                case States::THIRD:
                    if (cur_char == static_cast<unsigned char>(Symbols::ZERO)) {
                        ++cur_zeros;
                    } else if (cur_char == static_cast<unsigned char>(Symbols::ONE)) {
                        ++cur_ones;
                        cur_state = States::FOURTH;
                    }
                    break;

                case States::FOURTH:
                    if (cur_char == static_cast<unsigned char>(Symbols::ZERO)) {
                        if (cur_ones != ones || cur_zeros != zeros) {
                            flag = false;
                        }
                        cur_ones = 0;
                        cur_zeros = 0;
                        ++cur_zeros;
                        cur_state = States::THIRD;
                    } else if (cur_char == static_cast<unsigned char>(Symbols::ONE)) {
                        ++cur_ones;
                    }
                }
            }
        }
    }

    if (!ones || !zeros) {
            flag = false;
        }

        if (cur_state == States::THIRD || cur_state == States::FOURTH) {
            if (cur_ones != ones || cur_zeros != zeros) {
                flag = false;
            }
        }
}

int
main()
{
    unsigned char cur_char;
    std::cin >> std::noskipws;

    while (std::cin >> cur_char) {
        if (isspace(cur_char)) {
            while (std::cin >> cur_char && isspace(cur_char))
                ;
        }

        bool flag = true;
        int zeros = 0, ones = 0, cur_zeros = 0, cur_ones = 0;
        States cur_state = States::FIRST;

        if (cur_char == static_cast<unsigned char>(Symbols::ZERO)) {
            ++zeros;
        } else {
            flag = false;
        }

        check_word(cur_char, cur_state, cur_zeros, cur_ones, zeros, ones, flag);

        std::cout << flag << std::endl;
    }
}
