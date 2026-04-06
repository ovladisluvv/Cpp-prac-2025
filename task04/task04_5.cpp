#include <iostream>
#include <list>

int
main()
{
    std::list<unsigned> num_list = {};
    
    unsigned cur_num;
    while (std::cin >> cur_num && cur_num) {
        num_list.push_back(cur_num);
    }
    
    int cur_cmd;
    size_t ind;
    while (std::cin >> cur_cmd) {
        if (cur_cmd < 0) {
            ind = static_cast<size_t>(-cur_cmd);
            if (ind <= num_list.size()) {
                auto it = num_list.begin();
                std::advance(it, ind - 1);
                num_list.erase(it);
            }
        } else {
            std::cin >> cur_num;
            ind = static_cast<size_t>(cur_cmd);
            if (ind <= num_list.size()) {
                auto it = num_list.begin();
                std::advance(it, ind - 1);
                num_list.insert(it, cur_num);
            } else {
                num_list.push_back(cur_num);
            }
        }
    }
    
    for (const auto &num : num_list) {
        std::cout << num << std::endl;
    }
    
    num_list.clear();
}