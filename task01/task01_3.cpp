#include <iostream>
#include <cctype>

int
main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    char cur_symb;
    bool only_zeros = true, has_symb = false;

    while ((cur_symb = std::cin.get()) != EOF) {
        if (isdigit(cur_symb)) {
            has_symb = true;

            if (cur_symb - '0') {
                only_zeros = false;
            }

            if (!only_zeros) {
                std::cout << cur_symb;
            }
        } else {
            if (has_symb && only_zeros) {
                std::cout << '0';
            }

            only_zeros = true;
            has_symb = false;
            std::cout << cur_symb;
        }
    }

    if (has_symb && only_zeros) {
        std::cout << '0';
    }
}
