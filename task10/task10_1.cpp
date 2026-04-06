#include <iostream>
#include <string>

enum class Answers
{
    KS = 2,
    NKS = 21,
    LREG = 31,
    LAUTO = 311,
    RREG = 32,
    RAUTO = 321
};

bool
check_one_nterm(const std::string &str, size_t &nterm_pos)
{
    bool nterm_flag = false;
    size_t cur_pos = 0;

    for (unsigned char cur_char : str) {
        if (isupper(cur_char)) {
            if (nterm_flag) {
                return false;
            }

            nterm_flag = true;
            nterm_pos = cur_pos;
        }

        ++cur_pos;
    }

    return true;
}

int
main()
{
    char cur_lhs;
    std::string cur_rhs;
    unsigned eps_nterms = 0, one_nterm_rules = 0, S_to_one_nterm = 0;
    bool S_to_eps = false, S_in_rhs = false, all_nterm_rhs = true;
    bool lreg_flag = true, rreg_flag = true, auto_flag = true;

    while (std::cin >> cur_lhs >> cur_rhs) {
        if (cur_rhs == "_") {
            if (cur_lhs == 'S') {
                S_to_eps = true;
            } else {
                ++eps_nterms;
            }
        } else {
            if (cur_rhs.find('S') != std::string::npos) {
                S_in_rhs = true;
            }

            size_t nterm_pos = 0;
            all_nterm_rhs &= check_one_nterm(cur_rhs, nterm_pos);

            if (all_nterm_rhs) {
                if (nterm_pos > 1) {
                    lreg_flag = false;
                }

                if (nterm_pos > 0 && nterm_pos < cur_rhs.size()) {
                    rreg_flag = false;
                }

                auto_flag &= (cur_rhs.size() == 1 && nterm_pos == 0) || (cur_rhs.size() <= 2 && nterm_pos > 0);

                if (cur_rhs.size() == 1 && nterm_pos > 0) {
                    if (cur_lhs == 'S') {
                        ++S_to_one_nterm;
                    }

                    ++one_nterm_rules;
                }
            }
        }
    }

    if (all_nterm_rhs) {
        if (auto_flag && !eps_nterms && (!one_nterm_rules || (one_nterm_rules == 1 && S_to_one_nterm == 1)) &&
            (!S_to_eps || (S_to_eps && !S_in_rhs))) {
            if (lreg_flag) {
                std::cout << static_cast<int>(Answers::LAUTO);
            } else if (rreg_flag) {
                std::cout << static_cast<int>(Answers::RAUTO);
            }
        } else {
            if (lreg_flag) {
                std::cout << static_cast<int>(Answers::LREG);
            } else if (rreg_flag) {
                std::cout << static_cast<int>(Answers::RREG);
            }
        }
    } else if ((S_to_eps && S_in_rhs) || eps_nterms > 0) {
        std::cout << static_cast<int>(Answers::KS);
    } else {
        std::cout << static_cast<int>(Answers::NKS);
    }

    std::cout << std::endl;
}