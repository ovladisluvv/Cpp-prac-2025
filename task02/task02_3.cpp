#include <iostream>
#include <iomanip>

void
print_seq(char prev_symb, int count)
{
    constexpr int CORRECTION_LIMIT = 4;

    if (count > CORRECTION_LIMIT || prev_symb == '#') {
        std::cout << '#' << prev_symb << count << '#';
    } else {
        for (int i = 0; i < count; ++i) {
            std::cout << prev_symb;
        }
    }
}

int
main()
{
    char prev_symb = '\0';
    char cur_symb;
    int count = 0;

    std::cin >> std::noskipws;
    std::cout << std::hex;
    while (std::cin >> cur_symb) {
        if (cur_symb != prev_symb) {
            print_seq(prev_symb, count);
            prev_symb = cur_symb;
            count = 1;
        } else {
            ++count;
        }
    }

    print_seq(prev_symb, count);
}
