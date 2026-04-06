#include <iostream>
#include <string>
#include <cctype>

enum class Answers
{
    NOT_G = -1,
    KS = 2,
    NKS = 23,
    OTHER = 10
};

bool
nonterm(const std::string &str)
{
    for (const char &cur_char : str) {
        if (!std::islower(cur_char)) {
            return false;
        }
    }

    return true;
}

int
main()
{
    std::string left, right;
    bool init_rule = false, init_right = false, not_left = false, eps = false, init_eps = false, is_ks = true;

    while (std::cin >> left >> right) {
        if (nonterm(left)) {
            not_left = true;
            break;
        }

        if (left == "S") {
            init_rule = true;
        }

        if (left.size() > 1) {
            is_ks = false;
        }

        if (is_ks) {
            if (right == "_") {
                eps = true;
                if (left != "S") {
                    init_eps = true;
                }
            }

            if (right.find('S') != std::string::npos) {
                init_right = true;
            }
        }
    }

    if (not_left || !init_rule) {
        std::cout << static_cast<int>(Answers::NOT_G) << std::endl;
    } else if (is_ks) {
        if (init_eps || (eps && init_right)) {
            std::cout << static_cast<int>(Answers::KS) << std::endl;
        } else {
            std::cout << static_cast<int>(Answers::NKS) << std::endl;
        }
    } else {
        std::cout << static_cast<int>(Answers::OTHER) << std::endl;
    }
}
