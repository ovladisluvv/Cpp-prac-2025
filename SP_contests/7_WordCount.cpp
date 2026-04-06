#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <set>
#include <map>

int
main()
{
    std::ifstream fin("noMore.in");
    std::ofstream fout("noMore.out");

    std::unordered_map<int, std::unordered_map<char, int>> trans;
    std::set<int> ok_states;
    std::set<int> all_states;
    std::string cur_line;
    int init_state = -1;

    while (std::getline(fin, cur_line)) {
        if (cur_line.empty()) {
            break;
        }

        if (cur_line[0] == '[' && cur_line[1] == '[') {
            int state = std::stoi(cur_line.substr(2, cur_line.find("]]") - 2));
            ok_states.insert(state);
            all_states.insert(state);
        } else if (cur_line[0] == '[') {
            size_t r1 = cur_line.find(']');
            if (cur_line[r1 + 1] == ' ') {
                int from_state = std::stoi(cur_line.substr(1, r1 - 1));
                char trans_sym = cur_line[r1 + 2];
                size_t l2 = cur_line.rfind('[');
                int to_state = std::stoi(cur_line.substr(l2 + 1, cur_line.find(']', l2) - l2 - 1));

                trans[from_state][trans_sym] = to_state;
                all_states.insert(from_state);
                all_states.insert(to_state);

                if (init_state == -1) {
                    init_state = from_state;
                }
            } else {
                int state = std::stoi(cur_line.substr(1, r1 - 1));

                all_states.insert(state);

                if (init_state == -1) {
                    init_state = state;
                }
            }
        }
    }

    int N;
    fin >> N;

    std::map<int, size_t> cur_word, next_word;
    cur_word[init_state] = 1;

    size_t ans = ok_states.count(init_state);

    for (int len = 0; len < N; ++len) {
        next_word.clear();
        for (const auto &[state, count] : cur_word) {
            for (const auto &[trans_sym, to_state] : trans[state]) {
                next_word[to_state] += count;
            }
        }
        for (int acc : ok_states) {
            ans += next_word[acc];
        }
        cur_word.swap(next_word);
    }

    fout << ans;
}
