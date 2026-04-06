#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

int
main()
{
    std::set<char> N;
    std::map<char, std::vector<int>> id_map;
    std::vector<std::string> P_left, P_right;

    std::string cur_l, cur_r;
    int i = 0;
    while (std::cin >> cur_l >> cur_r) {
        P_left.push_back(cur_l);
        P_right.push_back(cur_r);
        char id = cur_l[0];
        id_map[id].push_back(i++);
        N.insert(cur_l[0]);
    }

    std::set<unsigned char> V = {'S'}, prev = V;

    for (size_t i = 0; i < N.size(); ++i) {
        std::set<unsigned char> dif;
        for (char sym : prev) {
            const auto &ids = id_map[sym];
            for (int id : ids) {
                std::string cur_r = P_right[id];
                for (unsigned char cur_nterm : cur_r) {
                    if (isupper(cur_nterm)) {
                        dif.insert(cur_nterm);
                    }
                }
            }
        }

        size_t size = V.size();

        for (unsigned char sym : dif) {
            V.insert(sym);
        }

        if (V.size() == size) {
            break;
        }

        prev = dif;
    }

    for (char nterm : V) {
        const auto &ids = id_map[nterm];
        for (int id : ids) {
            std::cout << P_left[id] << ' ' << P_right[id] << std::endl;
        }
    }
}
